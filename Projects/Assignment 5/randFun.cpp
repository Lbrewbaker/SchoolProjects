/********************************
Author: Luke Brewbaker
Date: 10/28/14
Modified: 10/28/14
File: randFun.cpp (week5)

Overview:
This program using a function to generate a random number

Input:
No user input.

Output:
Random numbers between an upper and lower limit

*******************************/
#include <iostream>
#include <cstdlib>

using namespace std;

//randy function prototype
void randymode(const int &x , const int &y, int &val);



int main()
{
	const int x = 1; //lower limit
	const int y = 50; //upper limit
	int val; //defines int for randy generato
	

	//calls randymode function
	randymode(x, y, val); 
	

return 0;

}

//randy mode function
void randymode(const int &x, const int &y, int &val)

{
	srand(time(NULL));

	val = rand() % y + x; //generates randy as a number between the two variables defined.

	cout << "\nYour random number is: " << val << "\n" << endl; //prints the random number the program generated.
}
