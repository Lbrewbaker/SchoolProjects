/********************************
Author: Luke Brewbaker
Date: 5/31/16
Modified: 6/1/16
File: otp__dec.c

Overview: : Similarly, this program will connect to otp_dec_d and will ask it to decrypt ciphertext using a passed-in ciphertext and key. It will use the same syntax and usage as otp_enc, and must be runnable in the same three ways.otp_dec should NOT be able to connect to otp_enc_d, even if it tries to connect on the correct port - you'll need to have the programs reject each other.

Sources:
http://codereview.stackexchange.com/questions/41748/small-one-time-pad-encryption-program
https://en.wikipedia.org/wiki/One-time_pad
http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

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

	//check command line arguments
	if (argc < 4) {
		fprintf(stderr, "Usage: ./otp_dec [port number] \n");
		exit(1);
	}

	//open socket
	int port_num = atoi(argv[3]);
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0) {
		fprintf(stderr, "Error: Unable to open socket.\n");
		exit(1);
	}

	struct sockaddr_in server_add;
	bzero((char*)&server_add, sizeof(server_add));
	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(port_num);
	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

	//connect to port
	if (connect(sock_fd, (struct sockaddr*)&server_add, sizeof(server_add)) < 0) {
		fprintf(stderr, "Error: could not contact otp_dec_d on port %d\n", port_num);
		exit(2);
	}

	//look signal identification with a sentinel
	int size = 1024;
	char buff[size];
	char sentinel[size];
	sentinel[1] = '*';
	snprintf(buff, size, "%c", sentinel[1]);
	int b = write(sock_fd, buff, strlen(buff));
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write ciphertext filename to socket.\n");
		exit(1);
	}
	sleep(1);


	//write ciphertext filename:
	snprintf(buff, size, "%s", argv[1]);
	b = write(sock_fd, buff, strlen(buff));
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write ciphertext filename to socket.\n");
		exit(1);
	}
	sleep(1);

	//write key file name
	snprintf(buff, size, "%s", argv[2]);
	b = write(sock_fd, buff, strlen(buff));
	if (b < 0) {
		fprintf(stderr, "Error: Unable to write key filename to socket.\n");
		exit(1);
	}

	//connect to server
	bzero(buff, size);
	b = read(sock_fd, buff, size);
	if (b < 0) {
		fprintf(stderr, "Error: could not contact otp_dec_d on port %d", port_num);
		exit(2);
	}

	//retrieve a response
	if (strcmp(buff,"error_3") == 0) {
		close(STDOUT_FILENO); // No FILE
		fprintf(stderr, "Eror: unable to connect to otp_dec_d on port %d\n", port_num);
	}
	
	else {
		//send to buffer
		printf("%s\n", buff);
	}

	//close connection
	close(sock_fd);

	return 0;
}
