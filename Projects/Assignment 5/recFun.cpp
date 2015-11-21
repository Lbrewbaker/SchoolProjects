/********************************
Author: Luke Brewbaker
Date: 10/28/14
Modified: 10/28/14
File: recFun.cpp

Overview:
This program will print out fibonacci sequence numbers to an Nth degree.  The nth degree is decided by the user.

Input:
The user will input the digit for the Fibonacci sequence.

Output:
Program will ouput the Fibonacci number at Nth degree.

*******************************/
#include <iostream>
#include <string>


using namespace std;

int fib(int);


int main()

{
	int nth;

	cout << "what digit do you want the Fibonacci sequence to print out to? ";
	cin >> nth;

	//prints fibonacci numbers
	cout << "Your Fibonacci numbers are: \n";

	//calls the fucntion and runs the calculations.
	for (int x = 0; x < nth; x++)
		cout << fib(x) << " ";
	cout << endl;


	return 0;
}


int fib(int n)
{
	//calculates fibonacci numbers.
	if (n <= 0)
		return 0;

	else if (n == 1)
		return 1;

	else
		return fib(n - 1) + fib(n - 2);
}