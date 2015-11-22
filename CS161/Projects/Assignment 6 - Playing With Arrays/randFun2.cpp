/********************************
Author: Luke Brewbaker
Date: 11/5/14
Modified: 11/6/14
File: randFun2.cpp

Overview:
This program uses values in an array and passes them to a function to generate a random number.

Input:
The user will input the lower and upper value limits on the random generator

Output:
a random number!


*******************************/
#include <iostream>
#include <cstdlib>

using namespace std;

//function prototype
int randInt(int min, int max, int val);


int main()

{
	int val = 0;
	int randgen[4] = {0, 0, 0, 0};

	cout << "Please enter a lower integer for random generator: ";
	cin >> randgen[1];

	cout << "please enter an upper integer for random generator: ";
	cin >> randgen[2];

	int min = randgen[1];
	int max = randgen[2];

	
	

	randgen[3] = randInt(min, max, val);

	cout << "your randomly generated number is: " << randgen[3] << endl;



	return 0;

}

int randInt(int min, int max, int val)
{
	srand(time(NULL));
	val = rand() % max + min;

	return val;
}