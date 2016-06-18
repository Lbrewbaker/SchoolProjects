/********************************
Author: Luke Brewbaker
Date: 4/24/16
Modified:4/30/16
File:  Adventure.c

Overview: Adventure game for CS344 Project 2.

This program is loosely based on a project from cs162.  In this version, rooms get shuffled upon game starting and the path will likely not be the same two times around.

*******************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

char *createDir(int pid);
void shuffleRooms(char **arr, size_t x);
struct Location fillRooms(char *roomDir);
void interface(struct Location userLoc);

struct Location {
	char *path;
	char *start;
	char *end;
};

int main(void) {
	srand(time(NULL));
	printf("\n");

	int pid = getpid();
	char *roomDir = createDir(pid);

	//Fill Room Files:
	struct Location userLoc = fillRooms(roomDir);

	//User Interface Presented:
	interface(userLoc);

	//clean up memory 
	free(roomDir);

	return 0;
}


char *createDir(int pid) {
	int size = 20;
	char *dirName = malloc(size);
	char *name = "brewbakl.rooms.";

	// generates and creates a directory name
	snprintf(dirName, size, "%s%d", name, pid);
	struct stat st = {0};
	if (stat(dirName, &st) == -1) {
		mkdir(dirName, 0755);  // 7=rwx 5=r-x 5=r-x.  This is making a directory with -rwxr-xr-x permissions so we can have full access to it.
	}

	return dirName;
}


void shuffleRooms(char **arr, size_t x) {
	struct timeval val;
	gettimeofday(&val, NULL);
	int value = val.tv_usec;
	srand48(value);

	if (x>1) {
		size_t i;
		for (i=x-1; i>0; i--) {
			size_t j = (unsigned int)(drand48()*(i+1));
			char* v = arr[j];  //Swapping positions here
			arr[j] = arr[i];   //in the room array for randomness
			arr[i] = v;
		}
	}
}


struct Location fillRooms(char *roomDir) {
	struct Location loc;
	loc.path = roomDir;
	char *room[11];

	//Setting room names.
	room[0] = "Dungeon";
	room[1] = "Bathroom";
	room[2] = "Garage";
	room[3] = "Attic";
	room[4] = "Bedroom";
	room[5] = "Library";
	room[6] = "Closet";
	room[7] = "Kitchen";
	room[8] = "Balcony";
	room[9] = "Foyer";
	room[10] = "Gazebo";

	//shuffle the rooms.
	shuffleRooms(room, 11);

	//Create Room Files:
	int size = 128;
	char *file = malloc(size);
	int i;
	for (i=0; i<7; i++) {
		snprintf(file, size, "%s/%s", roomDir, room[i]);
		FILE *f = fopen(file, "w");
		if (f == NULL) {
			perror("Unable to open.\n");
			exit(1);
		}
		else {
			//Add Room Name to Files:
			fprintf(f, "Room Name: %s\n", room[i]);
		}
		fclose(f);
	}

	//Save room names for connections
	char *roomName[7];
	for (i=0;i<7; i++) {
		roomName[i] = room[i];
	}

	// Set start and end room
	int endRoom = rand()%7;
	int startRoom = rand()%7;
	
	 //verify duplicates not taken
	while (startRoom == endRoom) { 
		endRoom = rand()%7;
	}

	//variables for room connections
	int totalConnects;
	char *connect;
	char currRoom[100];

	//open file to add room connections
	for (i=0; i<7; i++) {
		shuffleRooms(roomName, 7);
		snprintf(file, size, "%s/%s", roomDir, room[i]);
		FILE *f = fopen(file, "a");

		if (f == NULL) {
			perror("Unable to open file.\n");
			exit(1);
		}
		else {
			totalConnects = rand()%4+3;

			int k=0;
			int j;
			for (j=0; j<totalConnects; j++) {
				connect = roomName[k];
				if (connect == room[i]) {
					k++;
					connect = roomName[k];
				}
				//Add Room Connections to Room Files:
				fprintf(f, "CONNECTION %d: %s\n", j+1, connect);
				k++;
			}

			//Include Room Types:
			if (i == startRoom) {
				fprintf(f, "ROOM TYPE: START_ROOM\n");
				loc.start = room[i];
			}
			else if (i == endRoom) {
				fprintf(f, "ROOM TYPE: END_ROOM\n");
				loc.end = room[i];
			}
			else {
				fprintf(f, "ROOM TYPE: MID_ROOM\n");
			}
		}

		fclose(f);
	}

	free(file);

	return loc;
}

void interface(struct Location userLoc) {
	char *curr = userLoc.start;
	char *endRoom = userLoc.end;
	char *dir = userLoc.path;
	int stepCount = 0;
	int connectionCount = 0;

	char (*visited)[15] = malloc(sizeof *visited * 8); //rooms visited
	char (*contents)[15] = malloc(sizeof *contents * 8);
	char destination[15];
	int size = 128;
	char *file = malloc(size);

	//Read the Room File for Room Connections:
	int c;
	while (!(strcmp(curr, endRoom)) == 0) {
		snprintf(file, size, "%s/%s", dir, curr);
		FILE *f = fopen(file, "r");

		connectionCount = 0;

		if (f) {
			while ((c = getc(f)) != EOF) {
				if (c == '\n') {  //For every newline, count the number
					connectionCount++; //of room connections
				}
			}
		}

		//total number of connections
		connectionCount = connectionCount-2;

		//Get room information from the files
		char str[20];
		fseek(f, 11, SEEK_SET); //begin capture after the lable
		fgets(str, 20, f); //get everything on the line
		int len = strlen(str);
		//remove null char at the end. It does wierd stuff if you don't remove the null char at the end.
		if (str[len-1] == '\n') { 
			str[len-1] = 0;
		}
		
		//saves room name
		strcpy(contents[0], str); 

		int i;
		for (i=1; i<=connectionCount; i++) {
			fseek(f, 14, SEEK_CUR); //begin capture after the lable
			fgets(str, 20, f); //get everything on the line
			len = strlen(str);
			//remove null char at the end. It does wierd stuff if you don't remove the null char at the end.
			if (str[len-1] == '\n') {
				str[len-1] = 0;
			}
			//saves room name
			strcpy(contents[i], str); 
		}

		// print room contents, get user input for next location
		int correct = 0;
		//If user input was correct
		while (correct == 0) { 
			printf("Current Location: %s\n", contents[0]);
			printf("Connected rooms: ");
			
			//print contents of connected rooms
			for (i=1; i<=connectionCount; i++) {
				if (i == connectionCount) {
					printf("%s.\n", contents[i]);
				}
				else {
					printf("%s, ", contents[i]);
				}
			}

			// get user input
			printf("Next Room? >");
			scanf("%s", destination);

			// verify room user selects is correct
			for (i=1; i<=connectionCount; i++) {
				if (strcmp(destination, contents[i]) == 0) {
					correct = 1;
					curr = destination; //move to room
				}
			}
			
			//if connection user selects doesnt exit, have them retry.
			if (correct != 1) {
				printf("\nThere is no room there. Try again.\n\n");
			}
		}

		//Add visted room to rooms visited.
		printf("\n");
		strcpy(visited[stepCount], curr);
		stepCount++;
		fclose(f);
	}

	printf("\n ~~~~~ END OF THE LINE! ~~~~~\n");
	printf("Steps taken: %d.\n", stepCount);

	printf("\nPath Taken:\n");
	//Print the rooms player visited to get to the end.
	int i;
	for (i=0; i<stepCount; i++) {
		printf("%s\n", visited[i]);
	}

	//End Marker
	printf("%\n\n");

	//clean up memory
	free(visited);
	free(contents);
	free(file);
}
