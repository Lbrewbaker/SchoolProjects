/********************************
Author: Luke Brewbaker
Date: 11/18/14
Modified: 11/20/14
File: shopCart.cpp

Overview:
This program is a simple shopping cart program that allows the user chose what to do, add items, display contents, and display totals



Input:
User can input items, price, and quantitiy


Output:
Depends on what the user selects.


*******************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;


struct shoppingCart
{

	string name;
	double price;
	int quantity;
};


void input(shoppingCart[], int);
void print(shoppingCart[], int);
void total(shoppingCart[], int);

int main()
{
	int items;
	int f = 0; //used for the loop
	int xss;  //used to increase by number of inputs for the print function
	int choice;
	struct shoppingCart cart[100]; //shopping cart array

	//intialize cart array
	for (int i = 0; i < 100; i++)
	{
		cart[i].name == "";
		cart[i].price == 0;
		cart[i].quantity == 0;
	}


		cout << "\n Lets modify that shopping cart. \n" << endl;

		do
		{
			//the menu options
			cout << "What would you like to do?" << endl;
			cout << "1. Add an item." << endl;
			cout << "2. Display contents. " << endl;
			cout << "3. Display the total cost. " << endl;
			cout << "4. Quit." << endl;
			cin >> choice;

			//first choice
			while (choice == 1)
			{
			
				cout << "How many items will you be adding today? ";
				cin >> items;

				input(cart, items);
				break;

			}
			
			//defines xss as the counter of items included
			xss = items + xss;


			//second choice
			while (choice == 2)
			{
				print(cart, xss);
				break;
			}


			//choice 3
			while (choice == 3)
			{
				//total(cart, xss);
				break;
			}

			while (choice == 4)
			{
				exit(0);

			}


			//print
			for (int i = 0; i < xss; i++)
			{
				if (cart[i].name != "\0") //this will loop as long as name is not null
				{
					cout << "\nItem Name: " << cart[i].name << endl;
					cout << "Quantity: " << cart[i].quantity << endl;
					cout << "Price: $" << cart[i].price << setprecision(2) << "\n\n\n\n" << endl;

				}

		} while (f == 0);





	return 0;
}


void input(shoppingCart cart[], int items)
{
	for (int i = 0; i < items; i++)
	{
		cout << "Please enter the item name: ";
		cin >> cart[i].name;

		cout << "Please enter the price: ";
		cin >> cart[i].price;

		cout << "How many of those items would you like to purchase?: ";
		cin >> cart[i].quantity;
	}


}

/*
void print(shoppingCart cart[], int xss)
{

	for (int i = 0; i < xss; i++)
	{
		if (cart[i].name != "\0") //this will loop as long as name is not null
		{
			cout << "\nItem Name: " << cart[i].name << endl;
			cout << "Quantity: " << cart[i].quantity << endl;
			cout << "Price: $" << cart[i].price << setprecision(2) << "\n\n\n\n" << endl;

		}

		else if (cart[i].name = "\0")
		{ 
				break;
		}

}
	*/

void total(shoppingCart cart[], int xss)
{
	double totals = 0;

	for (int i = 0; i < xss; i++)
	{
		//so long as the price does not equal 0, it will calculate the new total
		if (cart[i].price != 0)
		{
			totals += (cart[i].price * cart[i].quantity);
		}

		else if (cart[i].price == 0)
			break;
	}


	cout << "The total price is: $" << totals << setprecision(2) << endl;
}