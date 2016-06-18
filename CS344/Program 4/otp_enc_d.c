/********************************
Author: Luke Brewbaker
Date: 5/31/16
Modified: 6/1/16
File: otp_enc_d.c

Overview: This program will run in the background as a daemon. Its function is to perform the actual encoding, as descripted above in the Wikipedia quote (note that the C % operator won't perform the modulus you want - you'll have to write your own). This program will listen on a particular port, assigned when it is first ran, and receives plaintext and a key via that port when a connection to it is made. It will then write back the ciphertext to the process that it is connected to via the same port. Note that the key passed in must be at least as big as the plaintext. This program must output an error if the program cannot be run due to a network error, such as the ports being unavailable.

Sources:
http://codereview.stackexchange.com/questions/41748/small-one-time-pad-encryption-program
https://en.wikipedia.org/wiki/One-time_pad
http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

*******************************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>


int validInput(char character); //check for valid input, i.e. no illegal characters
int numConvert(char character); //convert char to number

int main(int argc, char *argv[]) {
	
	//check command line arguments
	if (argc < 2) {
		fprintf(stderr, "Usage:./otp_dec_d [listening port number]\n");
		exit(1);
	}

	//create child process and exit parent process.
	pid_t pid = fork();
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}
	umask(0); //enable read/write access

	//set sid for child process.
	pid_t sid = setsid();
	if (sid < 0) {
		exit(EXIT_FAILURE);
	}

	//close terminal access.
	close(STDOUT_FILENO);
	close(STDIN_FILENO);

	//Open and bind socket.
	int portNum = atoi(argv[1]);
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//error opening socket
	if (sock_fd < 0) {
		fprintf(stderr, "Error: Unable to open socket.\n");
		exit(1);
	}
	struct sockaddr_in server_add;
	struct sockaddr_in client_add;
	bzero((char*)&server_add, sizeof(server_add));
	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(portNum);
	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock_fd, (struct sockaddr*)&server_add, sizeof(server_add)) < 0) { //bind socket
		fprintf(stderr, "Error: Unable to bind server to socket.\n");
		exit(1);
	}

	//listen for connections on socket, up to 5 max
	listen(sock_fd, 5); 
	socklen_t client_add_length = sizeof(client_add);
	int accept_fd;
	
	//forever a loop
	while (1) {
		accept_fd = accept(sock_fd, (struct sockaddr*)&client_add, &client_add_length);
		
		if (accept_fd < 0) {
			fprintf(stderr, "Error: Unable to accept.\n");
			exit(1);
		}

		//verify signal 
		int size = 1024;
		char send[size];
		bzero(send, size);
		char receive[size];
		bzero(receive, size);
		int b = read(accept_fd, receive, size);
		if (b < 0) {

			exit(1);
		}
		printf("%c",receive[0]);
		if (receive[0] != '^') {
			snprintf(send, size, "%s", "error_3");
			
			//sends error to client if write fail
			b = write(accept_fd, send, strlen(send)); 
			if (b < 0) {
				fprintf(stderr, "Error: Unable to read from socket.\n");
				exit(1);
			}
			continue;
		}

		//get plaintext:
		bzero(receive, size);
		b = read(accept_fd, receive, size);
		if (b < 0) {
			fprintf(stderr, "Error: Unable to read from socket.\n");
			exit(1);
		}

		//open plaintext file:
		FILE *file;
		file = fopen(receive, "r");
		//if no file, print error
		if (file == NULL) {
			fprintf(stderr, "Error: Unable to open plaintext.\n");
			exit(1);
		}

		//convert file to upper case.
		char plaintext[size];
		fgets(plaintext, size, file);
		int i;
		for (i=0; i<strlen(plaintext); i++) {
			plaintext[i] = toupper(plaintext[i]);
		}
		plaintext[(strlen(plaintext))+1] = '\0';

		//err on bad character.
		bzero(send, size);
		for (i=0; i<(strlen(plaintext)-1); i++) {
			if (validInput(plaintext[i]) == 1) {
				snprintf(send, size, "%s", "error_2");
				b = write(accept_fd, send, strlen(send)); // Send error to client.
				if (b < 0) {
					fprintf(stderr, "Error: Unable to write to socket.\n");
					exit(1);
				}
				break;
			}
			continue;
		}
		fclose(file);

		//get a key 
		bzero(receive, size);
		b = read(accept_fd, receive, size);
		//error if no connection
		if (b < 0) {
			fprintf(stderr, "Error: Unable to read from socket.\n");
			exit(1);
		}

		//open key
		file = fopen(receive, "r");
		if (file == NULL) {
			fprintf(stderr, "Error: Unable to open key.\n");
			exit(1);
		}

		//save key
		char key[size];
		fgets(key, size, file);
		fclose(file);

		//verify key in plain text
		if (strlen(key) < strlen(plaintext)) {
			bzero(send, size);
			snprintf(send, size, "%s", "error_1");
			b = write(accept_fd, send, strlen(send));
			if (b < 0) {
				fprintf(stderr, "Error: Unable to write to socket.\n");
				exit(1);
			}
			continue;
		}

		//start encryption
		char characters[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "; //28 characters, this includes a space.
		char ciphertext[strlen(plaintext)];
		int keyNumber[strlen(plaintext)];
		int plaintextNum[strlen(plaintext)];
		int ciperNumber[strlen(plaintext)];

		//convert each characer to a number
		for (i=0; i<strlen(plaintext); i++) {
			keyNumber[i] = numConvert(key[i]);
			plaintextNum[i] = numConvert(plaintext[i]);
			ciperNumber[i] = plaintextNum[i] + keyNumber[i];
			if (ciperNumber[i] > 26) { 
				ciperNumber[i] -= 27;
			}
			//generates the cipher text
			ciphertext[i] = characters[ciperNumber[i]];
		}
		ciphertext[strlen(plaintext)-1] = '\0';

		//print cipher to client
		bzero(send, size);
		snprintf(send, size, "%s", ciphertext);
		b = write(accept_fd, send, strlen(send));
		if (b < 0) {
			fprintf(stderr, "Error: Unable to write to socket.\n");
			exit(1);
		}
	}

	return 0;
}

int validInput(char character) {
	switch (character) {
	case 'A':
		return 0;
	case 'B':
		return 0;
	case 'C':
		return 0;
	case 'D':
		return 0;
	case 'E':
		return 0;
	case 'F':
		return 0;
	case 'G':
		return 0;
	case 'H':
		return 0;
	case 'I':
		return 0;
	case 'J':
		return 0;
	case 'K':
		return 0;
	case 'L':
		return 0;
	case 'M':
		return 0;
	case 'N':
		return 0;
	case 'O':
		return 0;
	case 'P':
		return 0;
	case 'Q':
		return 0;
	case 'R':
		return 0;
	case 'S':
		return 0;
	case 'T':
		return 0;
	case 'U':
		return 0;
	case 'V':
		return 0;
	case 'W':
		return 0;
	case 'X':
		return 0;
	case 'Y':
		return 0;
	case 'Z':
		return 0;
	case ' ':
		return 0;
	default:
		return 1;
	}
}

int numConvert(char character) {
	switch (character) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	case 'K':
		return 10;
	case 'L':
		return 11;
	case 'M':
		return 12;
	case 'N':
		return 13;
	case 'O':
		return 14;
	case 'P':
		return 15;
	case 'Q':
		return 16;
	case 'R':
		return 17;
	case 'S':
		return 18;
	case 'T':
		return 19;
	case 'U':
		return 20;
	case 'V':
		return 21;
	case 'W':
		return 22;
	case 'X':
		return 23;
	case 'Y':
		return 24;
	case 'Z':
		return 25;
	case ' ':
		return 26;
	}
}
