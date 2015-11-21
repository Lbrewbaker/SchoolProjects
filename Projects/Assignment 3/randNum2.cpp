/********************************
Author: Luke Brewbaker
Date: 10/15/14
Modified: 10/17/14
File: randNum2.cpp

Overview:
This program will generate a random number between two user defined numbers

Input:
two user defined upper and lower limits for the program.  It will also check to make sure the user input is an integer, and that the lower number is less than the upper limit.

Output:
program will output 5 random numbers between the two user defined numbers

*******************************/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int randy; //random interger
	int up; //upper limit
	int low; //lower limit

	cout << "Please enter an upper limit for the random number generator: " << endl; //defines upper limit
	cin >> up;

	while (!cin) //checks for an integer value
	{
		cout << "That was not a number! Please enter a number: ";
		cin.clear(); //clears cin value
		cin.ignore();
		cin >> up; //alows user to redefine upper
	}


	cout << "Please enter a lower limit for the random number generator: " << endl; //defines lower limit
	cin >> low;

	while (!cin) //checks for an interger value
	{
		cout << "That was not a number! Please enter a number: ";
		cin.clear(); //clears CIN value, allows user to enter another number
		cin.ignore();
		cin >> low; //will allow user to input another number
	}

	//checks if low number is higher than up value
	if (low >=up)
	{
		cout << "Please enter a number lower than "<< up << endl;
		cin.clear();
		cin.ignore();
		cin >> low;
	}

	//runs the random number generator
	do
	{

	randy = rand() % (up - low) + low; //generates randy as a number between 1 and 100
	cout << "\nYour random number is: " << randy << endl; //prints the random number the program generated.
	
	break; //exits the loop

	} while (low <= up);


	return 0;
}