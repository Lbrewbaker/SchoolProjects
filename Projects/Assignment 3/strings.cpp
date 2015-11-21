/********************************
Author: Luke Brewbaker
Date: 10/14/14
Modified: 10/16/14
File: strings.cpp

Overview:
This program will allow the user to enter a string, it will then print the string forward, backward, and count the letters in the string.

Input:
The user input will be the first string.

Output:
Using three for loops, it will print the string forward, backward, and count the number of letters in the string.

*******************************/
#include <string>
#include <iostream>

using namespace std;

int main()
{
   int i; //introduce int i to be used in first 2 for loops
   string my_str; //defines string
  
   cout << "Please enter some text " << endl; //prompt user for string  
   getline (cin, my_str); //stores the users string

   int strlength = my_str.length(); //defines strlength as the users string length

  	cout << "Forwads: \n" << endl; //forward string loop
	for (i = 0; i < my_str.length(); i ++)

	{
		cout << my_str.at(i) << endl; //prints name forward
	}

	cout << "\nBackwards! \n" << endl; //backwards string loop
	for (i = my_str.length()-1; i >= 0;  i--)

	{
		cout << my_str.at(i) << endl;  //prints name backwards
	}

	for (int x = 0; x < my_str.length(); x++) //counts string length
	{
		if (my_str.at(x) == ' ')  //if null character, delete 1 from string length
	         
		{ 
		     strlength--; //subtracts string length for null characters
		}

	}
	cout << "There are " << strlength << " letters in your text." << endl; //counts stringlength
	
return 0;
}
