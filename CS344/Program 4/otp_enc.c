/********************************
Author: Luke Brewbaker
Date: 5/31/16
Modified: 6/1/16
File: otp_enc.c

Overview: This program connects to otp_enc_d, and asks it to perform a one-time pad style encryption as detailed above. By itself, otp_enc doesn’t do the encryption. Its syntax is as follows:
otp_enc plaintext key port
In this syntax, plaintext is the name of a file in the current directory that contains the plaintext you wish to encrypt. Similarly, key contains the encryption key you wish to use to encrypt the text. Finally, port is the port that otp_encshould attempt to connect to otp_enc_d on.
When otp_enc receives the ciphertext, it should output it to stdout. Thus, otp_enc can be launched in any of the following methods, and should send its output appropriately:


Sources:
http://codereview.stackexchange.com/questions/41748/small-one-time-pad-encryption-program
https://en.wikipedia.org/wiki/One-time_pad
http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html
http://www6.uniovi.es/cscene/CS4/CS4-03.html
http://www.sanfoundry.com/cpp-program-implement-one-time-pad-algorithm/

*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>


int main(int argc, char *argv[]) {
	
	//checking command line arguments
	if (argc < 4) {
		fprintf(stderr, "Usage: ./otp_enc [port number] \n");
		exit(1);
	}

	//open up and bind socket/port
	int port_num = atoi(argv[3]);
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//error message if unable to open
	if (sock_fd < 0) {
		fprintf(stderr, "Error: Unable to open socket.\n");
		exit(1);
	}

	struct sockaddr_in server_add;
	bzero((char*)&server_add, sizeof(server_add));
	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(port_num);
	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

	// Connect to port:
	if (connect(sock_fd, (struct sockaddr*)&server_add, sizeof(server_add)) < 0) {
		fprintf(stderr, "Error: could not contact otp_enc_d on port %d\n", port_num);
		exit(2);
	}

	//look signal identification with a sentinel
	int size = 1024;
	char buff[size];
	char sentinel[size];
	sentinel[1] = '^';
	snprintf(buff, size, "%c", sentinel[1]);
	int b = write(sock_fd, buff, strlen(buff));
	
	//error message
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write plaintext filename to socket.\n");
		exit(1);
	}
	sleep(1);

	//plaintext filename:
	snprintf(buff, size, "%s", argv[1]);
	b = write(sock_fd, buff, strlen(buff));
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write plaintext filename to socket.\n");
		exit(1);
	}
	sleep(1);

	//key filename:
	snprintf(buff, size, "%s", argv[2]);
	b = write(sock_fd, buff, strlen(buff));
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write key filename to socket.\n");
		exit(1);
	}

	//server response:
	bzero(buff, size);
	b = read(sock_fd, buff, size);
	if (b < 0) {
		fprintf(stderr, "Error: could not contact otp_end_d on port %d", port_num);
		exit(2);
	}

	//error 1 is too short of a key
	if (strcmp(buff,"error_1") == 0) {
		close(STDOUT_FILENO); //should prevent file creation
		fprintf(stderr, "Error: key '%s' is too short\n", argv[2]);
		exit(1);
	}
	
	//error 2 is bad characters in key.
	else if (strcmp(buff,"error_2") == 0) {
		close(STDOUT_FILENO);
		fprintf(stderr, "Error: input contains bad characters\n");
		exit(1);
	}
	
	//error 3 is unable to connect to otp_enc_d on specified port
	else if (strcmp(buff,"error_3") == 0) {
		close(STDOUT_FILENO);
		fprintf(stderr, "Error: unable to connect to otp_enc_d on port %d\n", port_num);
	}
	
	//print buffer if no effors
	else {
		printf("%s\n", buff);
	}

	//close socket connection
	close(sock_fd);

	return 0;
}
