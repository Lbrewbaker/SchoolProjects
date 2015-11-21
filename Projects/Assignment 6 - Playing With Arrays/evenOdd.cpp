/********************************
Author: Luke Brewbaker
Date: 11/4/14
Modified: 11/4/14
File: evenOdd.cpp

Overview:
This program will let the user determine the size of an array, and also its contents (integers in this case).  It will then calculate odd and even numbers in that array.

Input:
User can define the size of the array, and also its contents

Output:
The program will calculate the odd and even numbers in each array, separately through different functions.

*******************************/
#include <iostream>


using namespace std;

//prototypes
int calcEven(int myarray[], int sizeOfArray);
int calcOdd(int myarray[], int sizeOfArray);



int main()
{
	int x; //size of array

	//define size
	cout << "How many integers do you want in the array? ";
	cin >> x;

	//start array
	int myarray[x];

	//input data into the arrays
	for (int i = 0; i < x; i++)
	{
		cout << "Please choose up to " << x << " numbers: ";
		cin >> myarray[i];
	}

	//print out the calculations.
	cout << "The sum of the even numbers is " << calcEven(myarray, x) << endl;
	cout << "The sum of the odd numbers is " << calcOdd(myarray, x) << endl;

	return 0;

}



int calcEven(int myarray[], int sizeOfArray)
{
	int even = 0;//intially sets even to 0
	int temp = 0; //temp integer
	int y; //used in calculation

	for (int i = 0; i < sizeOfArray; i++)
	{

		//use remainder to find out if position is even
		y = myarray[i] % 2;


		//if integer is even, add the position to temp
		if (y == 0)
			{
				even = myarray[i] + temp;

			}

		temp = even; //sets temp to even.

	}


	return even;
}




int calcOdd(int myarray[], int sizeOfArray)
{
	int odd = 0;//intially sets Odd to 0
	int temp = 0; //temp integer
	int y; //used in calculation

	for (int i = 0; i < sizeOfArray; i++)
	{
		//use remainder to find out if position is even
		y = myarray[i] % 2;


		//if integer is even, add the position to temp
		if (y == 1)
			{
				odd = myarray[i] + temp;

			}

		temp = odd; //sets temp to odd.

	}


	return odd;
}