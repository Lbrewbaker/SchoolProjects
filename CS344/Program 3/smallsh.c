/********************************
Author: Luke Brewbaker
Date:  16 May 2016
Modified: 23 May 2016
File: smallsh.c

Overview: 
A shell program written in C,  similar to bash.

Resources:

[1]http://brennan.io/2015/01/16/write-a-shell-in-c/ 
[2] http://www.gnu.org/software/libc/manual/html_node/Implementing-a-Shell.html#Implementing-a-Shell
[3] https://gist.github.com/parse/966049

*******************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#define DELIMS " \t\r\n\a"


int backPs = 0;
int argsNum = 0;

//functions
char *readCommand();
char **splitCommand(char *command); 
int execOther(char **args); 


int main() {
	int calledExit = 0;
	int exitValue = 0;

	do {
		char *command = NULL;
		char **args;
		backPs = 0;
		argsNum = 0;
		int fDesc;

		//Prompt for each line
		printf(": ");

		//read command from user
		command = readCommand();

		//split command
		args = splitCommand(command);
		
		//check background for processes running
		if (!(strncmp(args[argsNum-1], "&", 1))) {
			backPs = 1;
			args[argsNum-1] = NULL;
		}

		//check for blanks or comments (lines beginning with #):
		if (args[0] == NULL || !(strncmp(args[0], "#", 1))) {
			exitValue = 0;
		}

		//check for exit command
		else if (strcmp(args[0], "exit") == 0) {
			calledExit = 1;
			exitValue = 0;
		}

		//check for cd (change directory) command:
		else if (strcmp(args[0], "cd") == 0) {
			if (args[1]) { // Directory provided
				if (chdir(args[1]) != 0) {
					printf("No such file or directory\n"); // If there's an error
					exitValue = 1;
				}
			}
			else {
				chdir(getenv("HOME")); //default to home
				exitValue = 0;
			}
		}

		//check for status command:
		else if (strcmp(args[0], "status") == 0) {
			printf("Exit value: %d\n", exitValue);
			exitValue = 0;
		}

		//check for redirection:
		else if (argsNum == 3 && ((strcmp(args[1], ">") == 0) || (strcmp(args[1], "<") == 0))) {
			int stdin = dup(0);
			int stdout = dup(1);

			//opens write to file destination
			if (strcmp(args[1], ">") == 0) {
				fDesc = open(args[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);

				if (fDesc == -1) {
					printf("%s: No such file or direcotry\n", args[2]);
					exitValue = 1;
				}
				else {
					dup2(fDesc, 1); // Point stdout to this file
					args[1] = NULL; // Only save command
					close(fDesc); // Clean up
					exitValue = execOther(args); // Execute command
				}
			}

			//open file to read from
			else if (strcmp(args[1], "<") == 0) {
				fDesc = open(args[2], O_RDONLY);

				if (fDesc == -1) {
					printf("smallsh: cannot open %s for input\n", args[2]);
					exitValue = 1;
				}
				else {
					dup2(fDesc, 0); //sendd stdout to this file
					args[1] = NULL; //save command
					close(fDesc); //clean up
					exitValue = execOther(args); //execute command
				}
			}

			//Restore original stdin and stdout:
			dup2(stdin, 0);
			close(stdin);
			dup2(stdout, 1);
			close(stdout);
		}

		//Check for other
		else {
			exitValue = execOther(args);
		}

		//free memory
		free(args);
		free(command);

	} while (!calledExit);

	return 0;
}


char *readCommand() {
	char *command = NULL;
	ssize_t size = 0;

	//reads command from command line as a string
	getline(&command, &size, stdin); //i get an implicit declaration warning from this in compiler, but it seems to work OK

	return command;
}


char **splitCommand(char *command) {
	int pos = 0;
	int size = 64;
	char **tokens = malloc(size*sizeof(char*));
	char *token;


	token = strtok(command, DELIMS);

	//retrieve and count arguments
	while (token != NULL) {
		tokens[pos] = token;
		pos++;
		argsNum++;

		//reallocate size for tokens if needed.
		if (pos >= size) {
			size += 64;
			tokens = realloc(tokens, size*sizeof(char*));
		}

		//get next token
		token = strtok(NULL, DELIMS);
	}
	tokens[pos] = NULL;

	return tokens;
}


int execOther(char **args) {
	pid_t pid;
	pid_t wpid;
	int value = 0;
	int exitValue = 0;

	//fork a child
	pid = fork();

	if (pid == 0) {
		//execute commands
		if (execvp(args[0], args) == -1) {
			//error message
			printf("%s: No such file or directory\n", args[0]);
			exit(1);
		}
	}

	//error forking
	else if (pid < 0) {
		perror("smallsh");
	}

	//parent will wait for child to exit or be killed
	else {
		do {
			if (backPs == 0) {
				wpid = waitpid(pid, &value, WUNTRACED);
			}
			else if (backPs == 1) {
				wpid = waitpid(-1, &value, WNOHANG);
			}
		} while (!WIFSIGNALED(value) && !WIFEXITED(value));
	}

	//displays when background process ends.
	if (backPs == 1) {
		printf("Background pid: %d. Exit value: %d\n", pid, exitValue);
	}

	//set exit value of parent process.
	if (WIFSIGNALED(value) || value != 0) {
		exitValue = 1;
	}

	return exitValue;
}
