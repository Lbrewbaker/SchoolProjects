/********************************
Author: Luke Brewbaker
Date: 11/22/14
Modified: 11/23/14
File: carLot.cpp

Overview:
This program will allow the user to enter their car lot information, including inventory and sold vehicles.

Input:
User will input relevant information pertaining to their car lot


Output:
It will allow the user to print their car lot inventory, as well as their profit from a given month in time.

*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

//date struct
struct Date
{
	int day;
	int month;
	int year;

};

//car struct
struct Car
{
	string make;
	string model;
	int year;
	Date datePurchased;
	double purchasePrice;
	bool isSold;
	Date dateSold;
	double salePrice;

};


void input(vector<Car>& carvec);
void print(vector<Car> carvec);
void profit(vector<Car> carvec);

int main()
{
	int f = 0;
	int choice;
	vector<Car> carvec;

	cout << "\n Lets add the inventory for your car lot. \n" << endl;

	do
	{
		//the menu options
		cout << "\nWhat would you like to do?" << endl;
		cout << "1. Add a vehicle to inventory." << endl;
		cout << "2. Display inventory. " << endl;
		cout << "3. Display the profit from a month. " << endl;
		cout << "4. Quit." << endl;
		cin >> choice;


		if (choice == 1)
			input(carvec);

		if (choice == 2)
			print(carvec);

		if (choice == 3)
			profit(carvec);

		if (choice == 4)
			exit(0);

		continue;


	} while (f == 0);


	return 0;
}

void input(vector<Car>& carvec)
{
	char yesno;
	Car newCar;
	int monthz, dayz;


	cout << "Please enter the vehicle Make: ";
	cin >> newCar.make;

	cout << "Please enter the vehicle Model: ";
	cin >> newCar.model;

	//i couldn't figure out how to get this all on one line, so I separated it.
	cout << "Please enter the Date you purchased the vehicle. (MM/DD/YYYY)" << endl;

	//enter the month
	do
	{
		cout << "Month purchased: ";
		cin >> monthz;

		//month validation
		if (monthz >= 1 && monthz <= 12)
			newCar.datePurchased.month = monthz;
		else
			cout << "invalid month, please enter again. " << endl;

	} while (monthz != newCar.datePurchased.month);

	//enter day
	do
	{
		cout << "Day purchased: ";
		cin >> dayz;

		//day
		if (dayz >= 1 && dayz <= 31)
			newCar.datePurchased.day = dayz;
		else
			cout << "invalid day, please enter again. " << endl;

	} while (dayz != newCar.datePurchased.day);

	cout << "Year Purchased ";
	cin >> newCar.datePurchased.year;


	cout << "How much did you pay for the vehicle? ";
	cin >> newCar.purchasePrice;

	//is sold bool value
	cout << "Did you sell this vehicle? (Y/N) ";
	cin >> yesno;

	//if it is sold, enter the sold information.
	if (yesno == 'y' || yesno == 'Y')
	{
		newCar.isSold = true;

		cout << "Month sold: ";
		cin >> newCar.dateSold.month;
		cout << "Day sold: ";
		cin >> newCar.dateSold.day;
		cout << "Year sold ";
		cin >> newCar.dateSold.year;
		cout << "What was the sale price? ";
		cin >> newCar.salePrice;
	}

	//else, issold = false
	else
		newCar.isSold = false;


	//push this entry to the pack of the vector to make room.
	carvec.push_back(newCar);

	

}


void print(vector<Car> carvec)
{
	//for loop to go through inventory
	for (int i = 0; i < carvec.size(); i++)
	{

		//if statement to show unsold cars, since sold cars will already be out of inventory
		if (carvec[i].isSold == false)
			{
				cout << "Car make: " << carvec[i].make << endl;
				cout << "Car model: " << carvec[i].model << endl;
				cout << "Car year: " << carvec[i].year << endl;
				cout << "Date purchased: " << carvec[i].datePurchased.month << "/" << carvec[i].datePurchased.day << "/" << carvec[i].datePurchased.year << endl;
				cout << "Purchase price: $" << carvec[i].purchasePrice << setprecision(2) << endl;
			}
	}
}

void profit(vector<Car> carvec)
{
	//declare variables
	double total;
	int month, year;

	//select the month and year
	cout << "Enter the month you would like to check the profit for (MM): ";
	cin >> month;

	cout << "In which year (YYYY):";
	cin >> year;

	//loops through to check if there is one for that month and year
	for (int i = 0; i < carvec.size(); i++)
	{

		if (carvec[i].dateSold.month == month || carvec[i].dateSold.year == year)
			total += (carvec[i].salePrice - carvec[i].purchasePrice);

	}

	cout << "Total profit for " << month << "/" << year << " is $" << total << setprecision(2) << endl;



}

