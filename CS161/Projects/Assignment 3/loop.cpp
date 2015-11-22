/********************************
Author: Luke Brewbaker
Date: 10/15/14
Modified: 10/19/14
File: loop.cpp

Overview:
This program will prompt the user for two strings, and then check to see if the two strings match each other

Input:
2 user variables will be the two strings 

Output:
If the strings match, it will alert the user, and if they don't it will report an error.

*******************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	string first, second;  //two user defined strings

	cout << "\nType something, anything: " << endl;  //declares the first string
	cin >> first;
	

	cout << "\nType something again! " << endl;  //declares the second string
	cin >> second;



	while (first.compare(second) == 0) //compares strings together, and if equal tells user
	{
		cout << "You entered the same thing twice!" << endl;
		break;
	}
		
	while (first.compare(second) !=0) //compares strings and if unequal will well the user
	{
		cout << "You did not enter the same thing twice!" << endl;
		break;
	}


	return 0;
}
