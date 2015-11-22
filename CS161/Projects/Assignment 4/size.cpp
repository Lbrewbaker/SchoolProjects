/********************************
Author: Luke Brewbaker
Date: 10/20/14
Modified: 10/21/14
File: size.cpp

Overview:

Input:


Output:


*******************************/

/*********************
 Ask for age, height, weight of user.

 Hat size = (weight in pounds divied by height in inches) * 2.9

 Jacket size = ((Height * weight) / 288) + 10 inches for every 10 years over 30
 Waist size = (weight / 5.7) + 1/10th an inch for every 2 years over age 28

*********************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

double hatsize(double weight, double height);
double jacketsize(double age, double height, double weight);
double wasitsize(double weight, double age);


int main()

{
	double weight; //user weight
	double height; //user height
	double age; //user age
	char play; //play

	cout << "Would you like to calculate your jacket, hat, and waist size? (Y/N) ";
	cin >> play;
	

	//ask player if they want to play
		do
		{
			if (play == 'y' || play == 'Y' || play == 'n' || play == 'N')
				break;

			cout << "Please enter Y or N ";
			cin >> play;

		} while (play != 'y' || play != 'Y' || play != 'n' || play != 'N');

	//start main loop
		do
		{
	
				//define age
				cout << "How old are you? ";
				cin >> age;

				//define height
				cout << "How tall are you in inches? ";
				cin >> height;

				//define weight
				cout << "How much do you weigh in pounds? ";
				cin >> weight;

				//function call
				hatsize(weight, height);
				jacketsize(height, weight, age);
				wasitsize(weight, age);

				cout << "Would you like to try again? (Y/N) ";
				cin >> play;

		} while (play == 'y' || play == 'Y');




	return 0;
}


double hatsize(double weight, double height)
{

	float hsize; //defines hsize for the equation

	hsize = ((weight / height)*2.9); //hsize calculation

	cout << "Your hatsize is " << hsize << endl; //cout function
} 


double jacketsize(double height, double weight,double age)
{
	double jsize; //jacket size int
	float agemod; //age modifier

	//age modifier
			if (age < 40)
				agemod = 0;

		else if (age >= 40)
				agemod = (((age - 30) / 10) * (1 / 8.0)); //sets age modifier


	jsize = ((height * weight) / 288 + agemod);
	cout << "Your jacket size is: " << jsize << endl;

}



//  Waist size = (weight / 5.7) + 1/10th an inch for every 2 years over age 28
double wasitsize(double weight, double age)
{
	float wsize; //waist size int
	float x; //waist mod number

	if (age < 30)
		x = 0;

	else if (age >= 30)
		x = (((age - 28) / 2) * (1/10.0)); //sets age modifier


	wsize = (weight / 5.7) + (x); //calculates waist size

	cout << "Your waist size is: " << wsize << endl;

}
