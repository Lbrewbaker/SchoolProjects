/********************************
Author: Luke Brewbaker
Date: 10/15/14
Modified: 10/17/14
File: randNum.cpp

Overview:
This program will generate a random number 10 times in a loop

Input:
no user input for this program

Output:
10 random numbers will be printed to console

*******************************/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int randy; //randome interger

	for (unsigned int x = 0; x < 10; x++) //loops 10 times

	{
		randy = rand() % 100 + 1; //generates randy as a number between 1 and 100
		cout << "Your random number is " << randy << endl; //prints the random number the program generated.
	}
	



	return 0;
}