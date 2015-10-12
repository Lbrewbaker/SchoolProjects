
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Copies one array to another.
void copy(int array1[40][20], int array2[40][20])
{
	for (int j = 0; j < 40; j++)
	{
		for (int i = 0; i < 20; i++)
			array2[j][i] = array1[j][i];
	}
}

//Main life function
void life(int array[40][20])
{
	//Copies the main array to a temp array so changes can be entered into a grid
	int temp[40][20];
	copy(array, temp);
	for (int j = 1; j < 40; j++)
	{
		for (int i = 1; i < 20; i++)
		{
					//checks all 8 cells surrounding the current cell in the array.
					int count = 0;
					count = array[j - 1][i] +
						array[j - 1][i - 1] +
						array[j][i - 1] +
						array[j + 1][i - 1] +
						array[j + 1][i] +
						array[j + 1][i + 1] +
						array[j][i + 1] +
						array[j - 1][i + 1];
					//The cell dies.
					if (count < 2 || count > 3)
						temp[j][i] = 0;
					//The cell stays the same.
					if (count == 2)
						temp[j][i] = array[j][i];
					//The cell either stays alive, or born
					if (count == 3)
						temp[j][i] = 1;
			//Copies the completed temp array back to the main array.
			copy(temp, array);
			}
		}
	

}

//This function prints the array
void print(int array[40][20])
{
	for (int j = 1; j < 40; j++)
	{
		for (int i = 1; i < 20; i++)
		{
			if (array[j][i] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
	
}

int main()
{
	int gen0[40][20];
	int game[40][20];
	int play;
	char again;
	char cont;


	//Loop to check if user wants to keep simulating.
	do
	{
		//Loop to start simulation.
		do
			{
				cout << "\nWould you like to play? Please Selecet an option: " << endl;
				cout << "1. Play " << endl;
				cout << "2. Quit " << endl;
				cin >> play;

			} while (play = NULL);


		//Clears the screen so the simulation can run on a clean scream
		system("clear");
		int i = 0;


		//Loop that does the bulk of the simulation.
		do
		{
			//Generates the initial random state of the game board.
			srand(time(NULL));

			for (int j = 1; j < 40; j++)
				{
					for (int i = 1; i < 20; i++)
						gen0[j][i] = rand() % 2;
				}

			cout << "Generation: " << i << endl; //prints generation number

			//calls functions to start simulation
			copy(gen0, game);
			print(game);
			life(game);
			cout << endl; //adds a space between generations.

			i++; //this is to increment the generation number.

			//Pauses the system for .5 seconds to allow it to refresh
			system("sleep .5");

			//Checks whether the generation is at 50, or multiple of 50 if user continues simulation
			if (i % 50 == 1 && i != 1)
			{
				//Prompt user to continue if they desire
				do
				{
					cout << "Would you like to continue this simulation? (y/n): ";
					cin >> cont;
				} while (cont != 'y' && cont != 'n');
				if (cont == 'n')
					break;
			}

			system("clear"); //keeps only 1 game on screen at any given time, you can still scroll up to see other generations


		} while (play = 1);



		//Ask user if they want to try a second simulation, will restart if they do.
		do
			{
				cout << "Would you like to run another simulation? (y/n): ";
				cin >> again;

			} while (again != 'y' && again != 'n');
	} while (again == 'y');




	//will exit if option 2 selected
	do
	{
		exit(0);
	} while (play = 2);


	return 0;
}
