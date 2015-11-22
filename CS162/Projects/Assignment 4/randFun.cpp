/********************************
Author: Luke Brewbaker
Date: 10/20/14
Modified: 10/20/14
File: randFun.cpp

Overview:
This coding assignment is similar to randNum2.cpp from last week, except it asks us to use a function to call upon to use the random number generator.  

Input:
Two user inputs are the top and bottom values for the random number generator.


Output:
A random number between the two limits defined by the user.

*******************************/
#include <iostream>
#include <cstdlib>

using namespace std;

//randy function prototype
void randymode(int up, int low);



int main()
{
	int up; //upper limit
	int low; //lower limit
	
	//defines lower limit
	cout << "Please enter a lower limit for the random number generator: " << endl; 
	cin >> low;

	//defines upper limit
	cout << "Please enter an upper limit for the random number generator: " << endl; 
	cin >> up;

	//calls randymode function
	randymode(up, low); 
	

return 0;

}

//randy mode function
void randymode(int up, int low)

{
	int randy; //defines int for randy generator

	randy = rand() % (up - low) + low; //generates randy as a number between the two variables defined.

	cout << "\nYour random number is: " << randy << "\n" << endl; //prints the random number the program generated.
}
