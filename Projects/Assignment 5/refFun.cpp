/********************************
Author: Luke Brewbaker
Date: 10/28/14
Modified: 10/28/14
File: refFun.cpp

Overview:
This program will accept two strings, and compare them to each other in a function

Input:
Two user defined strings

Output:
The program checks both strings and outputs whether or not they are equal

*******************************/

#include <iostream>
#include <string>

using namespace std;

void check(string &first, string &second);

int main()
{

	string first, second;  //two user defined strings

	cout << "\nType a string: " << endl;  //declares the first string
	cin >> first;


	cout << "\nType another string! " << endl;  //declares the second string
	cin >> second;

	//calls function to check
	check(first, second);

	return 0;

}
//compares strings together, and if equal tells user

void check(string &first, string &second)
{
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

	}