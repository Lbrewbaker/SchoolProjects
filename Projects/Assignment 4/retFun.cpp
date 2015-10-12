/********************************
Author: Luke Brewbaker
Date: 10/24/14
Modified: 10/24/14
File: retFun.cpp

Overview:
This program will compare two strings to check if they are the same 

Input:
User will input two seprate strings

Output:
It will output if they are the same, or different.

*******************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string first, second;  //two user defined strings

	cout << "\nType something, anything: " << endl;  //declares the first string
	cin >> first;


	cout << "\nType something again! " << endl;  //declares the second string
	cin >> second;


//compares strings together, and if equal tells user
	
	for (int i = 0; i < first.length(); i++)
		{
			//breaks if strings are not of equal length
			if (first.length() != second.length())
			{
				cout << "Your strings are not equal! " << endl;
				break;
			}

			//starts comparing character by character
			else if (first.at(i) == second.at(i))
			{
				cout << "\nyour strings are equal! \n" << endl;
				i++;
				break;
			}

			//checks to see if two characters aren't equal.
			else if (first.at(1) != second.at(1))
			{
				cout << "\nyour strings aren't equal! \n" << endl;
				break;
			}



		}



		return 0;
	}