/********************************
Author: Luke Brewbaker
Date:11/10/14
Modified:11/14/14
File:ticTacToe.cpp

Overview:
Tic Tac Toe game.

Input:
2 player tic tac toe game.  Each player can select a square to put a mark, either an X or O.  

Output:
If either character can match up 3 similar characters, that character wins!

*******************************/
#include <iostream>
using namespace std;
#include <cstdlib> 

//set the tic tac toe array before main and fucntion calls so you don't have to pass it off each function
char tictac[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int main(int argc, char *argv[])
{
	int player = 1;
	int i;
	int choice;
	char mark;
	
	int game = atoi(argv[1]);

	do
	{
		do
		{
			board();

			//defines the player
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;


			mark = (player == 1) ? 'X' : 'O';

			//determines where to place the mark
			if (choice == 1 && tictac[1] == '1')
				tictac[1] = mark;

			else if (choice == 2 && tictac[2] == '2')
				tictac[2] = mark;

			else if (choice == 3 && tictac[3] == '3')
				tictac[3] = mark;

			else if (choice == 4 && tictac[4] == '4')
				tictac[4] = mark;

			else if (choice == 5 && tictac[5] == '5')
				tictac[5] = mark;

			else if (choice == 6 && tictac[6] == '6')
				tictac[6] = mark;

			else if (choice == 7 && tictac[7] == '7')
				tictac[7] = mark;

			else if (choice == 8 && tictac[8] == '8')
				tictac[8] = mark;

			else if (choice == 9 && tictac[9] == '9')
				tictac[9] = mark;

			//input validation
			else
			{
				cout << "Invalid move "; 
				player--;
				cin.ignore();
				cin.get();
			}

			i = checkwin();
			player++;

		} while (i == -1);

		board();

		if (i == 1)

			cout << "Player " << --player << " wins!";
		else
			cout << "Game is a draw";

		cin.ignore();
		cin.get();

		game--;

	} while (game > 0);


	return 0;
}


int checkwin()
{

	//the winning combinations
	if (tictac[1] == tictac[2] && tictac[2] == tictac[3])
		return 1;

	else if (tictac[4] == tictac[5] && tictac[5] == tictac[6])
		return 1;

	else if (tictac[7] == tictac[8] && tictac[8] == tictac[9])
		return 1;

	else if (tictac[1] == tictac[4] && tictac[4] == tictac[7])
		return 1;

	else if (tictac[2] == tictac[5] && tictac[5] == tictac[8])
		return 1;

	else if (tictac[3] == tictac[6] && tictac[6] == tictac[9])
		return 1;

	else if (tictac[1] == tictac[5] && tictac[5] == tictac[9])
		return 1;

	else if (tictac[3] == tictac[5] && tictac[5] == tictac[7])
		return 1;

	//game draws
	else if (tictac[1] != '1' && tictac[2] != '2' && tictac[3] != '3'
		&& tictac[4] != '4' && tictac[5] != '5' && tictac[6] != '6'
		&& tictac[7] != '7' && tictac[8] != '8' && tictac[9] != '9')

		return 0;

	//game continues
	else
		return -1;
}


//draws the board.  Arranges the 1D positions into a square.

void board()
{
	
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << tictac[1] << "  |  " << tictac[2] << "  |  " << tictac[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tictac[4] << "  |  " << tictac[5] << "  |  " << tictac[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tictac[7] << "  |  " << tictac[8] << "  |  " << tictac[9] << endl;

	cout << "     |     |     " << endl << endl;
}
