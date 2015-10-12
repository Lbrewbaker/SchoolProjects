/********************************
Author: Luke Brewbaker
Date: 10/24/14
Modified: 10/24/14
File: secretWord.cpp

Overview:
This is a secret word 2 player game similar to hangman.  Player 1 enters a word, and player 2 guesses that word 1 character at a time.  

Input:
Player 1 inputs a word, and player two is supposed to guess that word 1 letter at a time.  Player 2 will have a limited number of guesses.

Output:
Player 2 will select characters 1 at a time, and if correct it will reveal that character in the secret word that is hidden with asterisks.  When all characters are selected, it will show the correct word.

*******************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

void PlayGame(string secret);

//main function
int main()
{
	int chances; //chances player 2 gets
	string secret; //player 1s secret word
	char play; //play game

	//asks user if they want to play
	cout << "Do you want to play a secret word game? (Y or N)";
	cin >> play;

	while (play == 'y' || play == 'Y')
		{

			//player 1 turn
			cout << "Player 1, please enter your secret word in lower case only please: ";
			cin >> secret;
			cout << string(100, '\n'); //clears screen for player 2



			//player 2 turn
			chances = secret.length() + 1;
			cout << "Player 2, it is now your turn to play the game." << endl;
			cout << "You will have " << chances << " chances to guess correctly" << endl;
			PlayGame(secret); //calls game fucntion

			//replay
			cout << "Would you like to play again? (Y or N)";
			cin >> play;

		} 

	return 0;

}

//play game function
void PlayGame(string secret)

{
	int chances = secret.length()+2; //defines chances as the string length + 2
	int revealed = 0; //revealed characters
	string hidden = secret;

	char answer; //player 2's answer


	//displays secret word in astericks
	for (int i = 0; i < hidden.length(); i++)
	{
		hidden[i] = '*';
	}


		//while loop for the game
		while (revealed < secret.length())
		{
				cout << "You have " << chances << " to guess the word. Please select a letter: ";
				cout << hidden << ": ";
				cin >> answer;

				bool Guess = false;
				for (int x = 0; x < secret.length(); x++)
					{
					if (answer == secret[x]) //checks for answer to see if it is a char in the secret word
						{
								//check if answer is already selected.  Will not subtract a point for answers already selected
								if (hidden[x] == secret[x])
								{
									cout << "you already selected that character\n";
									Guess = true;
									break;
								}

								//else if the answer was in the  there clear out one of the asterisks
								else
								{
									hidden[x] = secret[x];//will clear an asterisk in the hidden word
									revealed++;
									chances--;
									Guess = true;
								}
						}
					continue;

			
					}

				//will tell you if the guess is not in the word
				if (!Guess)
				{
					chances--;
					cout << answer << " is not in that word" << endl;
					cout << "You have " << chances << " chances remaining" << endl;
				}

		


				//chances = 0 and game ends
				if (chances == 0)
				{
					cout << "Game Over!  The secret word was " << secret << ". Thank you for playing!" << endl;
					break;
				}


		}


		//if they guess correctly a message is displayed 
			if (chances > 0)
				{
				cout << "Correct!  The word was " << secret << ". You had " << chances << " guesses remaining. Thanks for playing!" << endl;
				}
	


}