/********************************
Author: Luke Brewbaker
Date: 5/6/15
Modified: 5/9/15
File: lab6.cpp

Overview:


Input:


Output:


*******************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void input(vector<double>&);
void sort(vector<double>&);
void output(vector<double>&);
void search();
void binsearch(vector<double>&);



int main()
{

	//creates input vector
	vector<double> inputvec;


	//function call for input stream function
	input(inputvec);

	    //function call to sort function
	sort(inputvec);

	//output function call
	output(inputvec);

    //search by input integer
	search();

    //binary search
	binsearch(inputvec);




	return 0;
}

void input(vector<double> &inputvec)
{
	//input integers
	double inp1, inp2, inp3, inp4;

	//creates input stream for files
	ifstream ifone("early.txt");
	ifstream iftwo("middle.txt");
	ifstream ifthree("end.txt");
	ifstream iffour("last.txt");

	//inputs the integers from the file to vectors
	while (!ifone.eof()){
		ifone >> inp1;
		inputvec.push_back(inp1);

	}

	while (!iftwo.eof()){

	iftwo >> inp2;
	inputvec.push_back(inp2);

	}

    while (!ifthree.eof()){
		ifthree >> inp3;
		inputvec.push_back(inp3);

	}

    inputvec.pop_back(); //for  some reason it was inputing a 0 here for no reason.  I pop back to eliminate

	while (!iffour.eof()){

	iffour >> inp4;
	inputvec.push_back(inp4);

	}

	//prints the input
    cout << "input: ";
	for(int i = 0; i < inputvec.size(); i++){
         cout << inputvec[i];
    }
    cout << endl;
}
void output(vector<double> &inputvec)
{
	int size = inputvec.size();

	//creates and sends vector to output file
	ofstream outone; //creates output stream
	outone.open("output.txt"); //opens new output file

	outone << "output: ";
	for (int i = 0; i < size; i++)
	{

		outone << inputvec[i] << " " << endl;
	}

	//closes the file
	outone.close();


}
void sort(vector<double> &inputvec)
{

	double temp; //temp int used for sorting
	int size = inputvec.size();

	//bubble sort the vector
	for (int k = 0; k < size; k++)
		for (int i = 0; i < size - 1; i++)
			if (inputvec[i] > inputvec[i + 1])
			{
                temp = inputvec[i];
                inputvec[i] = inputvec[i + 1];
                inputvec[i + 1] = temp;
			}

	//print sorted array
	cout << "sorted out: ";
	for (int i = 0; i < size; i++)
	{
		cout << inputvec[i];

	}
	cout << endl;
}


void search()
{

	//input integers
	double searchnumber;
	double temp1, temp2, temp3, temp4;
    double in1 = 0;
    double in2 = 0;
    double in3 = 0;
    double in4 = 0;


	//creates input stream for files
	ifstream ifone("early.txt");
	ifstream iftwo("middle.txt");
	ifstream ifthree("end.txt");
	ifstream iffour("last.txt");

	cout << "Please enter the number you'd like to search for: ";
	cin >> searchnumber;

    //first file

    while(!ifone.eof()) //will search input file for the number, and count each instance of each numbeer.
    {
            ifone >> temp1;
        if(temp1 == searchnumber){
                in1++;
        }

    }
    cout << "There are " << in1 << " instances of that number in the 1st file. " << endl;

    //second file.

    while(!iftwo.eof())
    {
           iftwo >> temp2;
        if(temp2 == searchnumber){
                in2++;
        }

    }
    cout << "There are " << in2 << " instances of that number in the 2nd file. " << endl;

    //third file

    while(!ifthree.eof())
    {
          ifthree >> temp3;
        if(temp3 == searchnumber){
                in3++;
        }

    }
    cout << "There are " << in3 << " instances of that number in the 3rd file. " << endl; //for some reason - the third file adds an extra 0 at the end of the file.

    //fourth file

    while(!iffour.eof())
    {
        iffour >> temp4;
        if(temp4 == searchnumber){
                in4++;
        }

    }
    cout << "There are " << in4 << " instances of that number in the 4th file. " << endl;


}

void binsearch(vector<double> &inputvec)
{
    double num;
    int index;
    int first = 0;
    int last = inputvec.size();
    int mid = 0;
    int key = 0;
    bool found = false;

    cout << "What number would you like to search for using a Binary search? ";
    cin >> num;

    //while loop to search vector for the number.
    while (first <= last && !found){

            mid = (first + last) / 2;

            if(num > inputvec[mid]){
                first = mid + 1;
            }

            else if (num < inputvec[mid]){
                last = mid - 1;
            }

            else{
                cout << "We have found " << num << " in position "<< mid << " of the vector" endl;
                found = true;
                break; //break added just to make sure it ends loops

            }

    }


            //prints if number not found
            if (!found){
                cout << "your number was not found " << endl;
            }


}

