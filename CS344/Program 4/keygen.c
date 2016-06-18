/********************************
Author: Luke Brewbaker
Date: 5/31/16
Modified: 6/1/16
File: keygen.c

Overview: This program creates a key file of specified length. The characters in the file generated will be any of the 27 allowed characters, generated using the standard UNIX randomization methods. Do not create spaces every five characters, as has been historically done. Note that you specifically do not have to do any fancy random number generation: we’re not looking for cryptographically secure random number generation! The last character keygen outputs should be a newline. All error text must be output to stderr, if any.

Sources: I based this off a few sources on how to generate random strings in C.

http://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	//checking command line arguments
	if (argc != 2) {
		printf("usage: ./keygen [length] \n");
		exit(1);
	}
	else {
		srand(time(NULL));
		int length = atoi(argv[1]);
		char key[length];

		//randomly create characters within the key length.
		int i;
		char temp;
		for (i = 0; i < length; i++) {
			temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "[random()%27]; //this also includes spaces.
			key[i] = temp;
		}
		key[length] = '\0';

		//display the key.
		printf("%s\n", key); 
	}

	return 0;
}
