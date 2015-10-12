/********************************
Author: Luke Brewbaker
Date: 11/21/14
Modified: 11/22/14
File:findMode.cpp

Overview:
This program will find the mode from a vector of ints.



Input:
user will enter their vector of ints



Output:
the program will output the mode from those ints.


*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

int modevec(vector<int>);

int main()
{

	vector<int> modee;
	int values;
	int amount;

	cout << "How many ints do you want to check the Mode of? ";
	cin >> amount;

	//fill the vector
	for (int i = 0; i < amount; i++)
	{
		int temp;

		cout << "Please enter an integer: ";
		cin >> temp;
		modee.push_back(temp); //adds the temp int to the back of the stack
	}

	//sort from smallest to biggest
	sort(modee.begin(), modee.end());


	//find the mode
	int firstcount = 0;
	int secondcount = 0;
	int mode = 0;

	//loops through the vector
	for (int i = 0; i < modee.size(); ++i)
	{
		secondcount = 0; //resets the counter to 0

		//loops the vector to check for similar characters
		for (int j = 0; j < modee.size(); ++j)
		{ 
			if (modee[j] == modee[i]) 
				++secondcount; //increases the counter if two characters are equal
		}

		if (secondcount > firstcount)
		{
			mode = modee[i]; //sets the mode the duplicate character detected
			firstcount = secondcount; //sets first counter to the second counter and then second counter resets to 0 before looping through the program again.
		}
	}

	cout << "\nThe mode is: " << mode << endl;
	return 0;
}