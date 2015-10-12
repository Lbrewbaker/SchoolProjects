/********************************
Author: Luke Brewbaker
Date: 11/4/14
Modified: 11/6/14
File: stringMix.cpp

Overview:
This program will accept a user input as a c-style string.  It will then pass that string to a function, and it will get mixed up and spit out as a second string.

Input:
User inputs 1 string

Output:
Outputs a mixed up string.


*******************************/
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>


using namespace std;

void scrambled(char mixeR[], char mixeD[]);

int main()
{
	char mixeR[30]; //sring to mix up
	char mixeD[30]; //empty one for mixing.

	char rep = 'y';//for the loop
	
	//user enters the string
	cout << "Let us start by entering a word you would like to mix up (less than 30 characters): ";
	cin.getline(mixeR, 30);



	do 
	{
		//call function
		scrambled(mixeR, mixeD);

		cout << "Your string mixed up was: " << mixeD << "." << endl;


		cout << "\nWant to mix it up again? (Y/N)\n";
		cin >> rep;
		

	} while (rep == 'y' || rep == 'Y');

	return 0;
}

void scrambled(char mixeR[], char mixeD[])
{
	srand(time(NULL)); //starts random number generator
	int val; //to pick a random position in the array to move
	int j;
	char temp;

	//copies the two c-style strings
	strcpy(mixeD, mixeR);

	//length
	int len = strlen(mixeR);
	int i = len - 1;

	//Fisher-Yates shuffle
	while (i > 0)
	{
		j = rand() % i;
		temp = mixeD[i];
		mixeD[i] = mixeD[j];
		mixeD[j] = temp;
		i--;
	}
	



}












