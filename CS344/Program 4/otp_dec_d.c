/********************************
Author: Luke Brewbaker
Date: 5/31/16
Modified: 6/3/16
File: otp__dec.c

Overview: 

Sources:
http://codereview.stackexchange.com/questions/41748/small-one-time-pad-encryption-program
https://en.wikipedia.org/wiki/One-time_pad
http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>


int validInput(char character); 
int numConvert(char character);

int main(int argc, char *argv[]) {

	//check command line arguments
	if (argc < 2) {
		fprintf(stderr, "Usage: ./otp_enc [listening port number] \n");
		exit(1);
	}

	//create child, exit parent
	pid_t pid = fork();
	
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}
	umask(0); //enable read and write access.

	//set sid for child.
	pid_t sid = setsid();
	if (sid < 0) {
		exit(EXIT_FAILURE);
	}

	//close terminal access
	close(STDOUT_FILENO);
	close(STDIN_FILENO);

	//open and bind socket
	int portNum = atoi(argv[1]);
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//if error opening print error
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

	//if error binding print error
	if (bind(sock_fd, (struct sockaddr*)&server_add, sizeof(server_add)) < 0) {
		fprintf(stderr, "Error: Unable to bind server to socket.\n");
		exit(1);
	}

	// listen for connections.  5 max.
	listen(sock_fd, 5);
	socklen_t client_add_length = sizeof(client_add);
	int accept_fd;
	
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
			fprintf(stderr, "Error: Unable to read from socket.\n");
			exit(1);
		}
		printf("%c",receive[0]);
		if (receive[0] != '*') {
			snprintf(send, size, "%s", "error_3");
			
			//if unable to read, send error.
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
		if (file == NULL) {
			fprintf(stderr, "Error: Unable to open ciphertext.\n");
			exit(1);
		}

		//convert file to upper case.
		char ciphertext[size];
		fgets(ciphertext, size, file);
		
		int i;
		for (i=0; i<strlen(ciphertext); i++) {
			ciphertext[i] = toupper(ciphertext[i]);
		}
		ciphertext[(strlen(ciphertext))+1] = '\0';
		
		//err on bad character.
		for (i=0; i<(strlen(ciphertext)-1); i++) {
			
			if (validInput(ciphertext[i]) == 1) {
				fprintf(stderr, "Error: input contains bad characters\n");
				exit(1);
			}
		}
		fclose(file);

		//get a key
		bzero(receive, size);
		b = read(accept_fd, receive, size);
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
		if (strlen(key) < strlen(ciphertext)) {
			fprintf(stderr, "Error: key '%s' is too short.\n", receive);
			exit(1);
		}

		//start decryption
		char characters[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		char plaintext[strlen(ciphertext)];
		int keyNumber[strlen(ciphertext)];
		int plaintextNum[strlen(ciphertext)];
		int ciperNumber[strlen(ciphertext)];
		
		//convert each characer to a numbe
		for (i=0; i<strlen(ciphertext); i++) {
			keyNumber[i] = numConvert(key[i]);
			ciperNumber[i] = numConvert(ciphertext[i]);
			plaintextNum[i] = ciperNumber[i] - keyNumber[i]; 
			
			if (plaintextNum[i] < 0) {
				plaintextNum[i] += 27;
			}
		}	
		//generates the cipher text
		plaintext[i] = characters[plaintextNum[i]]; 
		plaintext[strlen(ciphertext)-1] = '\0';

		//print cipher to client
		bzero(send, size);
		snprintf(send, size, "%s", plaintext);
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