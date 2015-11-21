/********************************
Author: Luke Brewbaker
Date: 11/26/14
Modified: 11/28/14
File: shopCart2.cpp

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


class ShoppingCart
{

	private:
		string name;
		double price;
		int quantity;

	public:
		ShoppingCart();
		ShoppingCart(int, string, double);
		double getPrice() const;
		int getQuantity() const;
		string getName() const;
		~ShoppingCart();
		void setName(string);
		void setPrice(double);
		void setQuantity(int);
	

};

//Default Constructor
ShoppingCart::ShoppingCart()
{
	string name = "";
	double price = 0;
	int quantity= 0;
}

//Overload constructor
ShoppingCart::ShoppingCart(int q, string n, double p)
{
	quantity = q;
	name = n;
	price = p;
	
}

//Destructor
ShoppingCart::~ShoppingCart()
{

}

//Accessor fucntions
double ShoppingCart::getPrice() const
{
	return price;
}

string ShoppingCart::getName() const
{
	return name;
}

int ShoppingCart::getQuantity() const
{
	return quantity;
}

//Mutator functions
void ShoppingCart::setName(string n)
{
	name = n;
}
void ShoppingCart::setPrice(double p)
{
	price = p;
}

void ShoppingCart::setQuantity(int q)
{
	quantity = q;
}


void input(vector<ShoppingCart>&);
void print(vector<ShoppingCart>&);
void total(vector<ShoppingCart>&);



int main()
{
	int f = 0; //used for the loop
	int choice;
	vector<ShoppingCart> cart;


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
			input(cart);
			break;

		}


		//second choice
		while (choice == 2)
		{
			print(cart);
			break;
		}


		//choice 3
		while (choice == 3)
		{
			total(cart);
			break;
		}

		while (choice == 4)
		{
			exit(0);

		}


	} while (f == 0);


	return 0;
}




void input(vector<ShoppingCart>& cart)
{
	string n;
	double p;
	int q;
	int numitems;

	cout << "How many items would you like to enter? ";
	cin >> numitems;
	
	for (int i = 0; i < numitems; i++)
	{

	cout << "Please enter the item name: ";
	cin >> n;

	cout << "How many of those items would you like to purchase? ";
	cin >> q;

	cout << "Please enter the price: ";
	cin >> p;

	//create object
	ShoppingCart newItem(q, n, p);

	//push back object to end of vector
	cart.push_back(newItem);

	}

	cout << endl;

}

void print(vector<ShoppingCart>& cart)
{
	int cartsize = cart.size();

	for (int i = 0; i < cartsize; i++)
	{

		cout << "\nItem Name: " << cart[i].getName() << endl;
		cout << "Quantity: " << cart[i].getQuantity() << endl;
		cout << "Price: $" << cart[i].getPrice() << setprecision(2) << "\n\n\n\n" << endl;

	}

}



void total(vector<ShoppingCart>& cart)
{
	double totals = 0;
	int cartsize = cart.size();


	for (int i = 0; i < cartsize; i++)
	{
		totals += (cart[i].getPrice() * cart[i].getQuantity());
	}



	cout << "The total price is: $" << totals << setprecision(2) << endl;
	cout << endl;
}




