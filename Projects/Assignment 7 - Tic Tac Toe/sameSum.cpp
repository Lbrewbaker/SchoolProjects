/********************************
Author: Luke Brewbaker
Date: 11/12/14
Modified: 11/14/14
File: sameSum.cpp

Overview:
This program will allow the user to define an array size (max 10 by 10). Then the user can fill the array and the program will check the sums of the diagonals, rows, and colums to see if they match up.

Input:
use can input the array size (rows and colums), and also fill the array.

Output:
it will sum the rows, colums, and diagonals to check if they equal each other.

*******************************/
#include <iostream>
#include <fstream>

using namespace std;

//const int rows = 5;
//const int col = 5;

//input int
int input(int);

//check the sum
bool checked(int, int, int, int);


int main()
{

	//declare the other ints
	int rows;
	int col;
	int q; 
	double diagone;
	double diagtwo;
	double sumrow;
	double sumcol;

	cout << "How many rows do you want? (max 10): ";
	cin >> rows;
	
	cout << "How many colums do you want? (max 10: ";
	cin >> col;

	int arr[rows][col];


	cout << "Please enter some numbers to fill the array, 1 row at a time with a space between each number: " << endl;

	//fills the array
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < col; x++)
		{
			arr[i][x] = input(q); //I used a function to get Q, it was the easiest way I could make it work
		}
	}

		//prints array just so they can see.

		for (int i = 0; i<rows; i++)    //This loops on the rows.
		{
			for (int j = 0; j<col; j++) //This loops on the columns
			{
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}



		//calc sum of rows
		for (int y = 0; y < rows; y++)
		{
			sumrow = 0;
			for (int x = 0; x < col; x++)
			{
				sumrow += arr[y][x];
			}
		}


		//calc sum of columns
		for (int y = 0; y < rows; y++)
		{
			sumcol = 0;
			for (int x = 0; x < col; x++)
			{
				sumcol += arr[y][x];
			}
		}

		//calc diagonals
		for (int y = 0; y < col; y++)
		{
			diagone += arr[y][y];
			diagtwo += arr[col - y - 1][y];
		}

		/***************************************
			Used to check the calculations

		cout << "sum rows is: " << sumrow << endl;
		cout << "sum col is: " << sumcol << endl;
		cout << "sum diagone is: " << diagone << endl;
		cout << "sum diagtwo is: " << diagtwo << endl;
		cout << "sum combdiag is: " << combdiag << endl;
		*****************************************/



		//check the sums
		bool yesno = checked(sumcol, sumrow, diagone, diagtwo);

		if (yesno == true)
		{
			cout << "(^_^)" << endl;
		}

		else if (yesno == false)
		{
			cout << "(-_-)" << endl;
		}
	

	return 0;
}


//input function
int input(int q)
{

	
	cin >> q;

	return q;

}

bool checked(int diagone, int diagtwo, int sumrow, int sumcol)
{

	//return values
	if (diagone == diagtwo && diagtwo == sumrow && sumrow == sumcol)
		return true;


	else
		return false;

}

