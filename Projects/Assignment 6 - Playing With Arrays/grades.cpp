/********************************
Author: Luke Brewbaker
Date: 11/4/14
Modified: 11/5/14
File: grades.cpp

Overview:
This program will allow the user to enter grades that students received, and then let them know how many of each type of grade there is.

Input:
User can input as many grades as they like (as defined by them).


Output:
The program will output the total number of each grade.


*******************************/
#include <iostream>

using namespace std;

//int count(int grades[], int sizeOfArray);

int main()
{
	int stu; //number of students
	int grade; //individual student grade

	//define how many students there are
	cout << "How many students are in your class? ";
	cin >> stu;


	//grades array
	int grades[6] = { 0, 0, 0, 0, 0, 0 };


	//inputting grades into the array
	for (int i = 0; i < stu; i++)
	{
		cout << "Please enter the grades from 0-5 starting with the first student: ";
		cin >> grade;

			if (grade == 0)
				grades[0]++;

			if (grade == 1)
				grades[1]++;

			if (grade == 2)
				grades[2]++;

			if (grade == 3)
				grades[3]++;

			if (grade == 4)
				grades[4]++;

			if (grade == 5)
				grades[5]++;

	}

	cout << "There are " << grades[0] << " - zero grades" << endl;
	cout << "There are " << grades[1] << " - one grades" << endl;
	cout << "There are " << grades[2] << " - two grades" << endl;
	cout << "There are " << grades[3] << " - three grades" << endl;
	cout << "There are " << grades[4] << " - four grades" << endl;
	cout << "There are " << grades[5] << " - five grades" << endl;


	return 0;

}
