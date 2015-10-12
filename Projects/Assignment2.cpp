	/********************************
	Author: Luke Brewbaker
	Date: 4/17/14
	Modified: 4/25/14
	File: Assignment2.cpp

	Overview:



	Input:



	Output:



	*******************************/
	#include <iostream>
	#include <vector>
	#include <string>
	#include <stdlib.h>
	#include <iomanip>

	using namespace std;



	class Grocery
	{

	private:
		string name;
		double quantity;
		double weight;
		double priceper;
		double tPrice;
		bool loyalty;
		char sale;

	public:

		Grocery() //default constructor - sets everything to 0 or null
		{
			name = "";
			quantity == 0;
			weight == 0;
			priceper == 0;
			tPrice == 0;
			loyalty == false;

		}

		Grocery(string na, double quan, double wei, double pp, double tp, char sales)
		{
			name = na;
			quantity = quan;
			weight = wei;
			priceper = pp;
			tPrice = tp;
			//loyalty = loy;
			sale = sales;

		}
		
		void setN()
		{
			name = name;
		}

		void setQ()
		{
			quantity = quantity;
		}
		
		void setW()
		{
			weight = weight;
		}

		void setP()
		{
			priceper = priceper;
		}

		void setT()
		{
			tPrice = tPrice;
		}

		void setL()
		{
			loyalty = loyalty;
		}

		void setS()
		{
			sale = sale;
		}

		char getS()
		{
			return sale;
		}

		string getName()
		{
			return name;
		}

		double getQ()
		{
			return quantity;
		}

		double getW()
		{
			return weight;
		}
		 
		double getP()
		{
			return priceper;
		}

		double getTP()
		{
			return tPrice;
		}

		bool getL()
		{
			return loyalty;
		}



	};

	class List : public Grocery
	{

	private:

	public:
		string na;
		double quan;
		double wei;
		double pp;
		double tp;
		bool loy;
		char sales;

		//creates vectory from Grocery
		vector<Grocery> cart;
		char sale;


		List()
		{

		}

		void cartinput() //input to vector
		{

			cout << "Please enter item name: ";
			cin >> na;

			cout << "Please enter the quantity: ";
			cin >> quan;

			cout << "Please enter item weight: ";
			cin >> wei;

			cout << "Please enter price per quantity: ";
			cin >> pp;

			tp = (pp * quan);

			cout << "Is the item on sale? (Y/N) ";
			cin >> sales;

		/*	if (sale == 'y' || 'Y')
			{
				loy = true;
			}
			else
				loy = false;*/

			//creates object for adding class
			Grocery newItem(na, quan, wei, pp, tp, sales);  //creates new item vector
			cart.push_back(newItem); //pushes back new item


		}

		void print()
		{
			int size = cart.size(); //sets size of vector size

			for (int i = 0; i < size; i++) //loops through each section of the vector
			{
				cout << endl;
				cout << "Item Name: " <<cart[i].getName() << endl;
				cout << "Quantity: " << cart[i].getQ() << endl;
				cout << "Price per unit: $" << cart[i].getP() << setprecision(2) << endl;
				cout << "Total price: $" << cart[i].getTP() << setprecision(2) << endl;
				cout << "Weight: " << cart[i].getW() << " pounds" << endl;


			}
		}

		void remove()
		{
			int size = cart.size(); //sets size of vector size
			string removed;

			cout << "What is the name of the item you'd like to remove? ";
			cin >> removed;

			for (int i = 0; i < size; i++)
				{

					if (cart[i].getName() == removed)
						{
							cart.pop_back();
							cout << removed << " is now out of your shopping cart. " << endl;
						}

					//figure out how to make this not show up each loop if that item isn't in that position
					else
						cout << "No items by that name " << endl;
				}


		}


		void totalprice() //calculate total price without club card.
		{
			double total;

			int size = cart.size();
			for (int i = 0; i < size; i++)
			{
				total += cart[i].getTP();

			}

			cout << "Your total is: $" << total << setprecision(2) << endl;

		}

		void clubprice()
		{
			double total;
			double loyaltyprice;
			double temp;
			double saved;

			int size = cart.size();

			for (int i = 0; i < size; i++)
			{
				if (cart[i].getS() == 'y' || 'Y') //checks if item is a loyalty item.
				{
					temp += cart[i].getTP(); //adds to loyalty temp

				}

				total += cart[i].getTP(); //calculate total cart price


			}

			//set loyalty price
			loyaltyprice = (temp * .90);

			//calculate dollars saved
			saved = (total - loyaltyprice);

			cout << "Your total is: $" << loyaltyprice << setprecision(2) << endl;
			cout << "You saved: $" << saved << setprecision(2) << " with your loyalty card. " << endl;


		}

	};



int main()
{

		int f = 0; //used for the loop
		int choice;
		int yn;


		//create class object
		List a;



		cout << "Let's go shopping!" << endl;

		do
		{
			//the menu options
			cout << "\nWhat would you like to do?" << endl;
			cout << "1. Add an item." << endl;
			cout << "2. Display contents. " << endl;
			cout << "3. Display the total cost. " << endl;
			cout << "4. Remove an Item." << endl;
			cout << "5. Quit." << endl;
			cin >> choice;

				//add items
				while (choice == 1)
				{
					a.cartinput();
					break;

				}

				//display cart
				while (choice == 2)
				{
					a.print();
					break;
				}


			//total cost
				while (choice == 3)
				{
					cout << "Loyalty club members enter the secret pin (1): ";
					cin >> yn;

					if (yn == 1)
					{
						a.clubprice();
						break;
					}

					else
					{
						a.totalprice();
						break;
					}

					/*
					else  (yn != 'n' || 'N' || 'y' || 'Y')
					{
					cout << "Invalid option, please try again." << endl;
					continue;
					}*/

				}

				//remove items
				while (choice == 4)
				{
					a.remove();
					break;
				}


				//exit
				while (choice == 5)
				{
						exit(0);

				}


			} while (f == 0);

	return 0;
}



