/********************************
Author: Luke Brewbaker
Date: 11/4/14
Modified: 11/4/14
File: arrayAdd.cpp

Overview:
This program adds two same-sized arrays together

Input:
user  will input the values for both arrays, as well as how large they want the array to be.

Output:
The program will display the arrays added together which are combined into a third array.

*******************************/
#include <iostream>


using namespace std;

void addThird(int [], int [], int [], int );

int main()
{

	int x; //size of array

	//define size
	cout << "How many integers do you want in the array? ";
	cin >> x;

	//start array
	int firstarray[x];
	int secondarray[x];
	int thirdarray[x];

	//input data into 1st array
	for (int i = 0; i < x; i++)
		{
			cout << "\nPlease choose up to " << x << " numbers for the FIRST array: ";
			cin >> firstarray[i];
		}

	//input data into 2nd array
	for (int i = 0; i < x; i++)
	{
		cout << "\nPlease choose up to " << x << " numbers for the SECOND array: ";
		cin >> secondarray[i];
	}

	//call function
	addThird(firstarray,  secondarray,  thirdarray, x);


	return 0;
}



void addThird(int firstarray[], int secondarray[], int thirdarray[], int x)
{

	//add into third array
	for (int i = 0; i < x; i++)
	{
		thirdarray[i] = (firstarray[i] + secondarray[i]);
	}



	//print third array

 	for (int i = 0; i < x; i++)
	{
		cout << "your arrays added together are: " << thirdarray[i] << endl;
	}


}