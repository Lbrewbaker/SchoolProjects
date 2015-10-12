/********************************
Author: Luke Brewbaker
Date: 10/28/14
Modified: 10/28/14
File: sortFun.cpp

Overview:
Program will use a function that takes 3 integers by reference and rearrange them smallest to largest.


Input:
The console user will be asked for three values


Output:
the program will sort those values from smallest to largest.

*******************************/
#include <iostream>     
#include <algorithm> 
#include <cstdlib>

using namespace std;

void sorting(int &one, int &two, int &three);

int main()
{
	int one, two, three; //three values from the user


	//defines three integers
	cout << "Please enter an integer: ";
	cin >> one;

	cout << "Please enter another integer: ";
	cin >> two;

	cout << "Please enter the last integer: ";
	cin >> three;

	cout << "Un sorted your numbers are " << one << ", " << two << ", " << three << "." << endl;


	//calls sort function
	sorting(one, two, three);


	return 0;

}



//sort function
void sorting(int &one, int &two, int &three)

{

	double temp;
	if (one > two)
	{
		temp = one;
		one = two;
		two = temp;
	}


	if (two > three)
	{
		temp = two;
		two = three;
		three = temp;
	}


	if (one > two)
	{
		temp = one;
		one = two;
		two = temp;
	}

	cout << "Sorted your numbers are " << one << ", " << two << ", " << three << "." << endl;


}