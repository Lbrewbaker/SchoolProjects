/********************************
Author: Luke Brewbaker
Date: 10/7/14
Modified: 10/8/14
File: arcade2.cpp

Overview:
This program will tell you what assortment of candy you can get based on ticket count.

Input:
There will be 3 variables.  Tickets, gumballs, and candy bars.  We will purchase the  max number of candy bars available and then use the remainder of tickets on gumballs.

Output:
Using 2 while loops, the program will calculate the number of candy bars and number of gumballs.  Candy bars will be calculated first, and the remainder of gumballs will be second.

*******************************/
#include <iostream>
using namespace std;
int main()

{

	int tickets;
	cout << "You have hit the ticket jackpot, and now you can get some candy! How many tickets do you have? " << endl; //prompts user for ticket count
	cin >> tickets;

	int candybars = 0 ;
	while (tickets >= 10) //calculate candy bars
	{
		tickets -= 10;
		candybars++;
	}

	int gumballs = 0 ;

	while (tickets > 2) //calculate gumballs
	{
		tickets -= 3;
		gumballs++;
	}

	cout << "Congrats winning all those  tickets! As a reward you can get " << candybars << " candy bars and " << gumballs <<  " gumballs! \n " <<  endl;

	if (tickets<3) //calculate remaining tickets
	{
	cout << "After turning in your tickets, you will have " << tickets  << " tickets remaining!  Please come again soon!\n " << endl;
	}


return 0;

}
