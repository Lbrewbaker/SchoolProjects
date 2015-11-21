/********************************
Author: Luke Brewbaker
Date: 10/24/14
Modified: 10/24/14
File: finalist.cpp

Overview:
This program is to select four prize winners from 25 finalists, but they can't win twice.

Input:
No user input for this program

Output:
Output will be four randomly generated numbers

*******************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	int contestant;  //contestant who wins the prize
	srand(time(NULL));  //seeds random generator

	//just a goofy statement at the beginning of the program
	cout << "Lets select four luck contestants to take home a pat on the back!\n" << endl;



	//loop to select the contest that wins the pat on the back
	for (int x = 1; x < 8; x++)
	{
		contestant = rand() % (25 - 1) + 1;
		cout << "congratulations contestant " << contestant << "! \n" << endl;
		x++;
	}


	return 0;
}