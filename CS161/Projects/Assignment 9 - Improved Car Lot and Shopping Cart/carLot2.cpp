/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File: carLot2.cpp

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


/*****************************************

Car Class

******************************************/

class Car
{
private:
	string make;
	string model;
	int year;
	double purchasePrice;
	bool isSold;
	double salePrice;
    int daypurch;
	int mopurch;
	int yeapurch;
	int daysold;
	int mosold;
	int yeasold;

public:
	Car();
	Car(string, string, int, double, bool, int, int, int); //not sold
	Car(string, string, int, double, bool, double, int, int, int, int, int, int); //sold
	string getMake()const;
	string getModel()const;
	int getYear()const;
	double getPurchasePrice()const;
	bool getisSold()const;
	double getSalePrice()const;
    int getDayp() const;
	int getMonthp()const;
	int getYearp()const;
    int getDays() const;
	int getMonths()const;
	int getYears()const;
	void setMake(string);
	void setModel(string);
	void setYear(int);
	void setPurchasePrice(double);
	void setisSold(bool);
	void setSalePrice(double);
	void setDayp(int);
	void setMonthp(int);
	void setYearp(int);
	void setDays(int);
	void setMonths(int);
	void setYears(int);


	~Car();

};

/**************************************

Car Constructors

****************************************/

Car::Car()
{
	int year = 0;
	double purchasePrice = 0;
	double salePrice = 0;
    string make = "";
	string model = "";
    int daypurch = 0;
	int mopurch = 0;
	int yeapurch = 0;
	int daysold = 0;
	int mosold = 0;
	int yeasold = 0;
}

Car::Car(string ma, string mo, int moy, double pp, bool qSold, int dpurch, int mpurch, int ypurch) //not sold
{

	make = ma;
	mo = mo;
	year = moy;
	purchasePrice = pp;
	isSold = qSold;
    daypurch = dpurch;
    mopurch = mpurch;
    yeapurch = ypurch;
}

Car::Car(string ma, string mo, int moy, double pp, bool qSold, double sPSO, int dpurch, int mpurch, int ypurch, int dsold, int msold, int ysold)//sold
{
	make = ma;
	mo = mo;
	year = moy;
	purchasePrice = pp;
	isSold = qSold;
	salePrice = sPSO;
    daypurch = dpurch;
    mopurch = mpurch;
    yeapurch = ypurch;
    daysold = dsold;
    mosold = msold;
    yeasold = ysold;


}

//destructor
Car::~Car(){};

//accessor functions
string Car::getMake()const
{
	return make;
}

string Car::getModel()const
{
	return model;
}

int Car::getYear() const
{
    return year;
}

double Car::getPurchasePrice()const
{
	return purchasePrice;
}

bool Car::getisSold()const
{
	return isSold;
}

double Car::getSalePrice()const
{
	return salePrice;
}

int Car::getDayp() const
{
    return daypurch;
}
int Car::getMonthp()const
{
    return mopurch;
}
int Car::getYearp()const
{
    return yeapurch;
}
int Car::getDays() const
{
    return daysold;
}
int Car::getMonths()const
{
    return mosold;
}
int Car::getYears()const
{
    return yeasold;
}

//mutators
void Car::setMake(string ma)
{
	make = ma;
}
void Car::setModel(string mo)
{
	model = mo;
}

void Car::setYear(int moy)
{
    year = moy;
}

void Car::setPurchasePrice(double pp)
{
	purchasePrice= pp;
}

void Car::setisSold(bool qSold)
{
	isSold = qSold;
}
void Car::setSalePrice(double sPSO)
{
	salePrice = sPSO;
}

void Car::setDayp(int dpurch)
{
    daypurch = dpurch;
}
void Car::setMonthp(int mpurch)
{
    mopurch = mpurch;
}
void Car::setYearp(int ypurch)
{
    yeapurch= ypurch;
}
void Car::setDays(int dsold)
{
    daysold= dsold;
}
void Car::setMonths(int msold)
{
    mosold= msold;
}
void Car::setYears(int ysold)
{
    yeasold=ysold;
}




/********************************************

Function Prototypes

*********************************************/

void input(vector<Car>& lot);
void print(vector<Car>& lot);
void profit(vector<Car>& lot);


/********************************************

Main

*********************************************/

int main()
{
	int f = 0;
	int choice;
	vector<Car> lot;

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
			input(lot);

		if (choice == 2)
			print(lot);

		if (choice == 3)
			profit(lot);

		if (choice == 4)
			exit(0);

		continue;


	} while (f == 0);


	return 0;
}


/****************************************

Functions

****************************************/
void input(vector<Car>& lot)
{

	int dayz, monthz;
	char yesno;
	string ma;
	string mo;
	int moy;
	bool qSold;
	int dp;
	int mp;
	int yp;
	int pp;
	int sPSO;
    int msold;
    int dsold;
    int ysold;
    int mpurch = 0;
    int ypurch;
    int dpurch = 0;

	int numcar;
	cout << "How many cars would you like to enter? ";
	cin >> numcar;



	for (int i = 0; i < numcar; i ++)
	{

		cout << "Please enter the vehicle Make: ";
		cin >> ma;

		cout << "Please enter the vehicle Model: ";
		cin >> mo;

        cout << "Please enter car Model Year: ";
        cin >> moy;

        cout << endl;

		cout << "Please enter the Date you purchased the vehicle. (MM/DD/YYYY)" << endl;


		//enter the month
            do
            {
                cout << "Month purchased: ";
                cin >> monthz;

                //month validation
                if (monthz >= 1 && monthz <= 12)
                    mpurch = monthz;
                else
                    cout << "invalid month, please enter again. " << endl;

            } while (monthz != mpurch);

		//enter day
            do
            {
                cout << "Day purchased: ";
                cin >> dayz;

                //day
                if (dayz >= 1 && dayz <= 31)
                    dpurch = dayz;
                else
                    cout << "invalid day, please enter again. " << endl;

            } while (dayz != dpurch);

		cout << "Year Purchased ";
		cin >> ypurch;


		cout << "How much did you pay for the vehicle? ";
		cin >> pp;

		//is sold bool value
		cout << "Did you sell this vehicle? (Y/N) ";
		cin >> yesno;


		//if it is sold, enter the sold information.
		if (yesno == 'y' || yesno == 'Y')
		{
			qSold = true;
			cout << "Month sold: ";
			cin >> msold;
			cout << "Day sold: ";
			cin >> dsold;
			cout << "Year sold ";
			cin >> ysold;
			cout << "What was the sale price? ";
			cin >> sPSO;

			Car soldInv(ma,  mo,  moy,  pp,  qSold,  sPSO, dpurch, mpurch, ypurch, dsold, msold, ysold);
			lot.push_back(soldInv);
		}

		//else, issold = false
		else
		{
			qSold = false;
			Car newInv(ma, mo, moy, pp, qSold, dpurch, mpurch, ypurch);
			lot.push_back(newInv);
		}


	}


}


void print(vector<Car>& lot)
{
    int lotsize = lot.size();

	//for loop to go through inventory
	for (int i = 0; i < lotsize; i++)
	{
			cout << "Car make: " << lot[i].getMake() << endl;
			cout << "Car model: " << lot[i].getModel() << endl;
			cout << "Car year: " << lot[i].getYear() << endl;
			cout << "Date purchased: " << lot[i].getMonthp() << "/" << lot[i].getDayp() << "/" << lot[i].getYearp() << endl;
			cout << "Purchase price: $" << lot[i].getPurchasePrice() << setprecision(2) << ".\n" << endl;

	}
}



void profit(vector<Car>& lot)
{
	//declare variables
	int sizez = lot.size();
	double total = 0;
	int month, year;

	//select the month and year
	cout << "Enter the month you would like to check the profit for (MM): ";
	cin >> month;

	cout << "In which year (YYYY):";
	cin >> year;

	//loops through to check if there is one for that month and year
	for (int i = 0; i < sizez; i++)
	{

		if (lot[i].getMonths() == month || lot[i].getYears() == year)
			total += (lot[i].getSalePrice() - lot[i].getPurchasePrice());

	}

	cout << "Total profit for " << month << "/" << year << " is $" << total << setprecision(2) << endl;

}


