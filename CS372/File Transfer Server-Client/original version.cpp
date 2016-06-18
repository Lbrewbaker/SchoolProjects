/********************************
Author: Luke Brewbaker
Date: 5/20/16
Modified: 5/26/16
File: ftserver.cpp

Overview: file transfer server.  will accept commands from ftclient.py on flip server.


Sources:
Adapted from a variety of online sources.
 https://beej.us/guide/bgnet/
 http://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program
 http://www.cplusplus.com/forum/general/27659/
 http://binarii.com/files/papers/c_sockets.txt
 http://www.bogotobogo.com/cplusplus/sockets_server_client.php
 I also am in a study group organized on reddit.
*******************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <dirent.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

//define back log
#define BACKLOG 10

//define buffer size
#define MAXDATASIZE 5000

using namespace std;


int startUp(char* portNum);
int acceptConnection(int sockfd, string type);
void handleRequest(int new_fd, char* portNum);
string listDirectory();
void sendMessage(string message, int new_fd);
//void sigchld_handler(int s);
void *get_in_addr(struct sockaddr *sa);

int main(int argc, char *argv[]) {
	int sockfd, new_fd; // Listen on sockfd, new connection on new_fd
	char* portNum;       // Port number
	string type;        // Control/Data

	// Check command line arguments count. argv[0] = Program name, argv[1] = Port number
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
		exit(1);
	}

	//validate command line arguments
	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535) {
		fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
		fprintf(stderr, "Port number must be between 1024 and 65535\n");
		exit(1);
	}
	//set port number to command line argument 
	portNum = argv[1];

	// Start control connection
	sockfd = startUp(portNum);
	type = "CONTROL";

	cout << "Server started on " << portNum << endl;

	// Loop forever
	while (1) {
		// Accept connection on control connection
		new_fd = acceptConnection(sockfd, type);

		//Child process
		if (!fork()) { 
			//Child doesn't need the listener
			close(sockfd);
			handleRequest(new_fd, portNum);
		}
	}
	
	return 0;
}


//Start the server socket(), bind(), and listen()
int startUp(char* portNum) {
	// Listen on sockfd
	int sockfd; // Socket file descriptor
	struct addrinfo hints; // Prep the socket address structures
	struct addrinfo *servinfo, *p; // Point to results
	struct sigaction sa; // For action to specific signal
	int yes=1; // optval for setsockopt()
	int rv; // Return value of getaddrinfo()

	memset(&hints, 0, sizeof hints);    // Make sure struct is empty
	hints.ai_family = AF_UNSPEC;        // IP version-agnostic (IPv4 OR IPv6)
	hints.ai_socktype = SOCK_STREAM;    // TCP stream sockets
	hints.ai_flags = AI_PASSIVE;        // Assign my IP address


	// IP address is NULL because hints.ai_flags = AI_PASSIVE
	if ((rv = getaddrinfo(NULL, portNum, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}

	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		// Set socket options
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		// Bind to the first valid one
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	// free servinfo
	freeaddrinfo(servinfo);

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		exit(1);
	}

	//wait for connections
	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	/*
	//close dead processes
	sa.sa_handler = sigchld_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}*/

	return sockfd;
}

//accepts new connection and creates new socket file descriptor.  original still listens for a connection
int acceptConnection(int sockfd, string type) {
	int new_fd;
	socklen_t sin_size;
	struct sockaddr_storage their_addr;
	char host[INET6_ADDRSTRLEN];
	char service[20];

	// Pass pointer to info and size of struct for incoming connection
	sin_size = sizeof their_addr;
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
	if (new_fd == -1) {
		perror("accept");
		exit(1);
	}

	if (type == "CONTROL") {
		// Lookup host name for incoming connection
		getnameinfo((struct sockaddr *)&their_addr, sin_size, host, sizeof host, service, sizeof service, 0);
		cout << "Connection from " << host << endl;
	}
	

	return new_fd;
}

//handles commands sent from the client.
void handleRequest(int new_fd, char* portNum) {
	int data_fd, data_new_fd, numbytes;
	char buffer[MAXDATASIZE];
	string host, command, temp_port, listing, filename, type;
	char* data_port;

	//return number of bytes into bufferr
	if ((numbytes = recv(new_fd, buffer, MAXDATASIZE - 1, 0)) == -1) {
		perror("recv");
		exit(1);
	}

	// Null-terminate
	buffer[numbytes] = '\0';

	// Acknowledge receipt of buffer
	string bufferstr(buffer);
	sendMessage(bufferstr, new_fd);

	// Receive full request
	if ((numbytes = recv(new_fd, buffer, MAXDATASIZE - 1, 0)) == -1) {
		perror("recv");
		exit(1);
	}

	// Null-terminate
	buffer[numbytes] = '\0';

	// Convert buffer to stringstream to read from
	istringstream StrStream(buffer);

	// list: extract host, command, data port
	if (bufferstr == "-l") {
		StrStream >> host;
		StrStream >> command;
		StrStream >> temp_port;
	}

	// et: extract host, command, filename, data port
	if (bufferstr == "-g") {
		StrStream >> host;
		StrStream >> command;
		StrStream >> filename;
		StrStream >> temp_port;
	}

	//Convert data port from string to const char* to char*
	const char* const_temp_port = temp_port.c_str();
	strcpy(data_port, const_temp_port);

	// Start data connection
	data_fd = startUp(data_port);
	type = "DATA";

	//client to connect to data connection
	sendMessage("DATA", new_fd);

	//connection on data connection
	data_new_fd = acceptConnection(data_fd, type);

	//list command
	if (command == "-l") {
		cout << "List directory requested on port " << data_port << endl;
		listing = listDirectory();
		cout << "Sending directory contents to " << host << ":" << data_port << endl;
		sendMessage(listing, data_new_fd);
		close(data_new_fd);
		exit(0);
	}

	//get command 
	if (command == "-g") {
		const char* const_filename = filename.c_str();
		int fd = open(const_filename, O_RDONLY);
		
		// If cannot open file for reading, print error and exit
		if (fd == -1) {
			cout << "File does not exist" << endl;
			exit(1);
		}

		cout << "File \"" << filename << "\" requested on port " << data_port << endl;

		// Get filesize
		struct stat st;
		stat(const_filename, &st);
		int filesize = st.st_size;

		// Declare contents of filesize length
		char contents[filesize];
		// Read file contents
		int r = read(fd, contents, filesize);

		// Variables for send loop
		int bytes_to_send = strlen(contents);
		int bytes_sent_total = 0;
		int bytes_sent;

		// Convert bytes_to_send from int to string
		stringstream ss;
		ss << bytes_to_send;
		string converted_bytes_to_send = ss.str();

		// Send bytes_to_send on control connection
		sendMessage(converted_bytes_to_send, new_fd);

		cout << "Sending \"" << filename << "\" to " << host << ":" << data_port << endl;

		// Send contents on data connection
		// Loop to ensure receive/send routines finishes job before continuing
		// Break transmission every 1000 characters
		while (bytes_sent_total != bytes_to_send) {

			if (bytes_to_send - bytes_sent_total < 1000) {
				bytes_sent = send(data_new_fd, contents + bytes_sent_total, (bytes_to_send - bytes_sent_total), 0);
			}
			else {
				bytes_sent = send(data_new_fd, contents + bytes_sent_total, 1000, 0);
			}

			if (bytes_sent < 0) {
				perror("ERROR sending to socket");
				exit(1);
			}

			bytes_sent_total = bytes_sent_total + bytes_sent;
		}
		
		//print out bytes sent and print success message.  If there was an error it would've been caught sooner
		cout << "Bytes sent: " << bytes_sent << endl;
		cout << "File \"" << filename << "\" sent on port " << data_port << " successfully" << endl;
		
		// Close data connection
		close(data_new_fd);
		exit(0);
	}
}

// send messages over socket
void sendMessage(string message, int new_fd) {
	const char* msg = message.c_str();

	// send returns number of bytes actually sent out
	if (send(new_fd, msg, strlen(msg), 0) == -1) {
		perror("send");
	}
}

string listDirectory() {
	DIR *d;
	struct dirent *dir;
	// Open current directory
	d = opendir(".");
	string listing;

	// Not NULL so we have a pointer to the directory stream
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			// Do not print current and parent hardlinks (. and ..)
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
				
			}
			else {
				// Print the filename
				listing += dir->d_name;
				listing += "\n";
			}
		}

		// Close directory
		closedir(d);
	}

	return listing;
}

/*
// handles zombies and child processes
void sigchld_handler(int s) {
	int saved_errno = errno;

	while(waitpid(-1, NULL, WNOHANG) > 0);

	errno = saved_errno;
}
*/
//get socket addr, works with both ipv4 and ipv6
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}