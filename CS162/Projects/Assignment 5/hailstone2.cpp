/********************************
Author: Luke Brewbaker
Date: 10/29/14
Modified: 10/29/14
File: hailstone.cpp

Overview:
This program is similar to the collatz conjecture

Input:
User defines "n" to put into the program and start the calculations.

Output:
The program will, if integer is even, divide by two and add one.  If odd, multiply by three and add one.  It will stop at 1, but could technically keep going.

*******************************/

#include <iostream> 
using namespace std;

int hail(int);

int main()
{
	//defines int N for the hailstones
	int n;
	cout << "n=? ";
	cin >> n;

	for (int x = 0; x < n; x++)
		cout << hail(n) << "\n";


	

	return 0;


}

int hail(int n)
{
	while (n > 1)
	{
	
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n = n / 2;
	}


	return n;
}