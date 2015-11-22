/*******************************************************************************************************************
Author: Luke Brewbaker
Date:11/12/14
Modified:11/15/14
File:symArrays.cpp

Overview:
This program will check the symmetry of three arrays, using command line arguments to get the size of that array. 
At the end of the program it then deletes the array and returns it to NULL

Input:
User will input the size of the array using the command line argument, and then can fill the arrays full of ints

Output:
The progrtam will cycle through each position in the array, check for symmetry, and return either a true or false boolean.  

**********************************************************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;


//input int
int input(int);


int main(int argc, char *argv[])
{

	int size1, size2, size3;   

	//set the sizes.  Uses atoi to convert from char to int.
	size1 = atoi(argv[1]);
	size2 = atoi(argv[2]);
	size3 = atoi(argv[3]);

	int q; //int's to fill the arrays

	cout << "We are going to create 3 arrays, and see if they are symmetrical or not. " << endl;
	
	/*******************first array*******************************/
	cout << "\nLet us start with the first array: " << endl;


	//intializes and sets ints to zero
	int* one =  NULL;
	one = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			one[i] = 0;
		}

	//fill the array
	cout << "Enter your ints, followed by white space: " << endl;
	for (int x = 0; x < size1; x++)
		{
			one[x] = input(q);
		}




	/*******************second array*******************************/
	cout << "\nNow lets do the second array: " << endl;
	int* two = NULL;

	//intializes array to null
	two = new int[size2];
		for (int i = 0; i < size2; i++)
		{
		two[i] = 0;
		}

	//fill the array
	cout << "Enter your ints for second array, followed by white space: " << endl;
	for (int x = 0; x < size2; x++)
	{
		two[x] = input(q);
	}



	/*******************third array*******************************/
	cout << "\nFinally, the third array: " << endl;
	int* three = NULL;	

	//intializes array to null
	three = new int[size3];
		for (int i = 0; i < size3; i++)
		{
		three[i] = 0;
		}

	//fill the array
	cout << "Enter your ints for third array, followed by white space: " << endl;
	for (int x = 0; x < size3; x++)
	{
		three[x] = input(q);
	}

	/****************** Check the arrays for Symmetry *************************/

	//check array one for symmetry
	bool onefalse = true;
	for (int x = 0; x < size1; x++)
	{
		if (one[x] != one[size1 - 1 - x])
			onefalse = false;

	}

	if (onefalse == true)
		cout << "Array one is Symmetric" << endl;

	else if (onefalse == false)
		cout << "Array one is NOT Symmetric" << endl;


	//check array 2
	bool twofalse = true;
	for (int x = 0; x < size2; x++)
	{
		if (two[x] != two[size2 - 1 - x])
			twofalse = false;

	}

	if (twofalse == true)
		cout << "Array two is Symmetric" << endl;
	else if (twofalse == false)
		cout << "Array two is NOT Symmetric" << endl;



	//check array 3
	bool threefalse = true;
	for (int x = 0; x < size3; x++)
	{
		if (three[x] != three[size3 - 1 - x])
			threefalse = false;

	}

	if (threefalse == true)
		cout << "Array three is Symmetric" << endl;
	else if (threefalse == false)
		cout << "Array three is NOT Symmetric" << endl;



	/********************** Delete Arrays ******************************/

	delete [] one;
	one = NULL;
	delete [] two;
	two = NULL;
	delete [] three;
	three = NULL;

	return 0;
}



int input(int q)
{
	cin >> q;
	return q;
}
