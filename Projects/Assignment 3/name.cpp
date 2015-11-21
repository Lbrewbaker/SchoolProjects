/********************************
Author: Luke Brewbaker
Date: 10/15/14
Modified: 10/17/14
File: name.cpp

Overview:
This program will prompt the user for their name, including middle initial, then print it forward and backwards.

Input:
The user will input their name including middle intial (if applicable)

Output:
It will then output the full name, middle intiial, and last name forward and backward.

*******************************/

#include <iostream>
#include <string>


using namespace std;

int main()
{


	cout << "What is your first name? " << endl;  //first name
	   string firstName;
	   getline(cin, firstName);

	cout << "What is your middle name?" << endl; //middle initial
	   string middleName;
	   getline(cin, middleName);
	   string middleIntial = middleName.substr(0, 1); //uses only first character of the middle name string by creating a substring and taking first character of the middle name

	cout << "What is your last name?" << endl;  //last name
	   string lastName;
	   getline(cin, lastName);

		if (middleName.size() != 0) //will print middle initial with a period if the middleName string is not equal to 0
		  {
		   cout << "Your name is " << lastName << ", " << firstName << " " << middleIntial << "." << endl;
	      }

		else //else it will print middle intial without a period
		  {
			cout << "Your name is " << lastName << ", " << firstName << endl;
		  }
		

return 0;

}

