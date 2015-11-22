/********************************
Author: Luke Brewbaker
Date: 10/20/14
Modified: 10/20/14
File: mpg.cpp

Overview:
This program will calculate fuel consumption in liters that the users car gets, converted from the MPG rating.

Input:
The user will be able to define their cars current MPG


Output:

The program will calculate and convert the MPG to the liters equivallent.

*******************************/


/*************************

There are 0.264179 galons per liter
There are 3.78541 Liters per galon
If a car drove 30 MPG, it would consume 30 * 3.78541 = 113ish liters.

**************************/
#include <iostream>
#include <string>

using namespace std;

//number of liters per gallon
const double LperG = 3.78541;

//MPG prototype
void MPG(int miles, int liters, double LperG);

//main function
int main()
{
	int miles; //distance driven to work
	int liters; //user guess on liters consumed
	//int gallons = 3.78541; //number of liters per gallon


	string cont; //will allow user to continue game

	cout << "Today we are going to calculate your MPG while driving to work.  Does that sound fun?  Please enter yes or no.  ";
	cin >> cont;

	//checks if cin was a yes or no
	while (!cin)
	{
		cout << "Please enter yes or no only! ";
		cin.ignore();
		cin.clear();
		cin >> cont;
	}

	if (cont == "no")
		return 0;


	//loop to calculate MPG
		do
		{
	
			//defines miles driven to work
			cout << "How many miles do you drive to work? ";
			cin >> miles;
		

			//defines liter consumption
			cout << "How many liters of petrol do you think you consume in that distance? ";
			cin >> liters;
		

			//calls MPG function
			MPG(miles, liters, LperG);

			//allows user to retry
			cout << "Would you like to calculate a different vehicle you own? yes or no to continue  ";
			cin >> cont;
			cout << "\n\n";

			//will break if user doesn't want to retry
			if (cont == "no")
				break;

		} while (cont == "yes");


	return 0;
}

//MPG function
void MPG(int miles, int liters, double LperG)
{
	double Mpergal; //users car MPG
	double Mconversion; //will convert liters to gallons

	Mconversion = (liters * LperG);

	Mpergal = ((Mconversion) / miles);  //calculation for MPG

	cout << "Your car gets " << Mpergal << "MPG" << endl;

}