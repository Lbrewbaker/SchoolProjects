/********************************
Author: Luke Brewbaker
Date: 10/31/14
Modified: 11/1/14
File: recConvert.cpp

Overview:


Input:


Output:

*******************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;


//function prototypes
int decimaltobinary(int);
int binarytodecimal(string);



int main()
{
	int b;  //binary conversion int
	char repeat;  //repeat character
	int choice; //choice int that will let user select which function they want to use.
	int f; //random int for program loop

	while (f == 0)
	{
		cout << "Please select from the following options: " << endl;
		cout << "1. Convert a Decimal number to Binary" << endl;
		cout << "2. Convert a Binary to a Decimal" << endl;
		cout << "3. Quit while you're ahead" << endl;
		cout << "Please choose carefully: ";
		cin >> choice;


			//first choice
			while (choice == 1)
			{
				cout << "\nPlease enter a number you would like to convert to binary (positive numbers only): ";
				cin >> b;

				//sets binary integer to the decimal to binary conversion function output
				int binary = decimaltobinary(b);

				//print binary conversion
				cout << "Your binary conversion is: " << binary << endl;

				//repeat
				cout << "\nPlease enter a Y or N if you'd like to convert another number to binary: ";
				cin >> repeat;

				if (repeat == 'y' || repeat == 'Y') //repeat
				{
					continue;

				}

				else if (repeat == 'n' || repeat == 'N')
				{
					break; //breaks if Y is not selected, sends back to main menu.
				}
			} 


			//choice 2
			while (choice == 2)
			{

				//user can enter their binary number
				string binarytodec;
				cout << "Please enter a binary number to convert into decimal: ";
				cin >> binarytodec;


				//sets decimal =  to function
				int decimal = binarytodecimal(binarytodec);


				//print decimal
				cout << "Your number in decimal format is: " << decimal << ".";
			
				//repeat
				cout << "\nPlease enter a Y or N if you'd like to convert another number to binary: ";
				cin >> repeat;

				if (repeat == 'y' || repeat == 'Y') //repeat
					{
						continue;

					}

				else if (repeat == 'n' || repeat == 'N')
					{
						break; //breaks if Y is not selected, sends back to main menu.
					}

			}



			//choice 3
			if (choice == 3)
			{
				cout << "\n(>_<)\n" << endl;
				break;
			}


			//validation for integer selection
			if (!isdigit(choice))
			{
				cout << "\nYou did not enter a number.  Please try again.\n" << endl;
				cin.clear();
				cin.ignore();
				continue;

			}


			//validation for menu selection
			if (choice != 1 || choice != 2 || choice != 3)
			{
				cout << "\nPlease only select a 1, 2 or 3.\n" << endl;
				cin.clear();
				cin.ignore();
				continue;

			}



	continue; //should push back to first menu.


	}

	return 0;
}

//binary conversion function
int decimaltobinary(int b)
{
	int i = 1; //used in the conversion
	int binary = 0; //sets binary intially to 0

	//starts converting
	while (b > 0)
	{
		binary += (b % 2)*i;
		b = b / 2;
		i *= 10;
	}


	return binary; //returns binary number
}




//Decimal to binary conversion


int binarytodecimal(string binarytodec)
{
	int decimal = 0;//sets decimal to 0 intially

	reverse(binarytodec.begin(), binarytodec.end());

	//conversion loop
	for (int i = 0; i < binarytodec.size(); i++)
		{
			decimal += (int(binarytodec[i]) - 48)*pow(2, i);
		}

	return decimal;
}