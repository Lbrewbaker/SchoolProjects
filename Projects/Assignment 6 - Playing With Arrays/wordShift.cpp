/********************************
Author: Luke Brewbaker
Date: 11/6/14
Modified: 11/6/14
File: wordShift.cpp

Overview:
“rev” should reverse the string. “Lx”, where x is some integer, should shift all the characters in the string left x
spaces, with any characters that fall off the beginning getting added on the end. For example, L3 would turn “hello
world” into “lo worldhel”. “Rx”, where x is some integer, should shift all the characters in the string right x spaces,
with any characters that fall off the end of the string getting added on the beginning. “quit” should end the program


Input:
user inputs a c-string

Output:
Depends on the menu choice!

*******************************/
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>

using namespace std;


void reverse(char string[]);
void shiftleft(char string[]);
void shiftright(char string[]);



int main()
{
	int f = 0;  //used for the loop
	int choice; //used in the selection loop
	char repeat; //used to repeat if necessary
	char string[30]; //for reversal

	cout << "First, let us start with a string: ";
	cin.getline(string, 30);

	while (f == 0)
	{
		cout << "\n Now what do you want to do with it? " << endl;
		cout << "1 - To reverse the string" << endl;
		cout << "2 - To shift left from 'x' position" << endl;
		cout << "3 - To shift right from 'x' position" << endl;
		cout << "4 - Quit" << endl;
		cout << "Please choose carefully: ";
		cin >> choice;



		//choice 1
		while (choice == 1)
		{

			reverse(string);
			cout << "Reversed: " << string << endl;
			break;
				
		}

		//choice 2
		while (choice == 2)
		{
			shiftleft(string);
			cout << "\nShifted left: " << string << endl;
			break;
		}

		//choice 3
		while (choice == 3)
		{
			shiftright(string);
			cout << "\nShifted right: " << string << endl;
			break;
		}



		//quit
		if (choice == 4)
		{
			cout << "\n(>_<)\n" << endl;
			break;
		}


	}


	return 0;
}


//reverse function
void reverse(char string[])
{
	int length = strlen(string);
	char x; //temp char
	int y = length;

	for (int i = 0; i < y; i++)
	{
		int position = (y - i - 1);
			if (position < i)
				break;
			else
			{
				x = string[i];
				string[i] = string[position];
				string[position] = x;

			}

	}



}

void shiftleft(char string[])
{
	int length = strlen(string);
	int y = length;
	int shifty; //used to determine how far to shift left

	//determine how far to shift
	cout << "What position do you want to shift it left from? ";
	cin >> shifty;

	char tempo[30]; //secondary array
	char tempotwo[30]; //third array
	
	//define tempo
	for (int i = 0;i < y; i++)
		{
			tempo[i] = string[shifty + i];
		}


	//define tempo2
	for (int i = 0; i < shifty; i++)
		{
			tempotwo[i] = string[i];
		}
	tempo[y] = '\0'; //sets null character on the array.
	tempotwo[shifty] = '\0'; //sets null character on the array.

	strcat(tempo, tempotwo); //concatenate tempo and tempo2
	strcpy(string, tempo); //copy tempo to string and return string to main

}

void shiftright(char string[])

{
	int length = strlen(string);

	int y = length;
	int shifty; //used to determine how far to shift left

	//determine how far to shift
	cout << "What position do you want to shift it right from? ";
	cin >> shifty;

	char tempo[30]; //secondary array
	char tempotwo[30]; //third array

	//define tempo2
	for (int i = shifty; i < y; i++)
	{
		tempotwo[i] = string[i];
	}

	//define tempo
	for (int i = shifty; i >= 0; i--)
	{
		tempo[i] = string[i];
	}

	tempo[shifty] = '\0'; //sets null character on the array.
	tempotwo[y] = '\0'; //sets null character on the array.


	strcat(tempotwo, tempo); //concatenate tempo and tempo2
	strcpy(string, tempotwo); //copy tempo to string and return string to main

}