
#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

int main(void)
{
	//Variables  
	string playerOne;
	int currentPlayer, computerChoice, playerOneChoice, tWins = 0, tLoses = 0, tTies = 0;
	int quitGame = 1;

	//Gets a random number between 1-3 
	srand((unsigned)time(0));
	computerChoice = 1 + rand() % 3;

	cout << "Welcome to Rock, Paper, Scissors." << endl;

	ofstream userOut;
	ifstream userIn;

	//Allows player to enter their name
	cout << "Enter your name. (Please don't use spaces and must be under 8 characters.) \n";
	cin >> playerOne;

	while (playerOne.length() > 8)
	{
		cout << "Sorry that name is too long. Please re-enter your name ";
		cin >> playerOne;
	}

	//Opens the file to read from the username
	userIn.open("C:\\Temp\\" + playerOne + ".txt");

	userIn >> tWins;
	userIn >> tLoses;
	userIn >> tTies;
	userIn.close();

	cout << "Wins: " << tWins << " Loses: " << tLoses << " Ties: " << tTies << endl;

	while (quitGame == 1)
	{

		srand((unsigned)time(0));
		computerChoice = 1 + rand() % 3;

		//Starts the game
		cout << "\n What do you choose. \n 1. Rock\n 2. Paper \n 3. Scissors\n";
		cin >> playerOneChoice;

		cout << "The computer chose " << computerChoice << endl;

		//Outcomes for the player winning
		if (playerOneChoice == 1 && computerChoice == 3)
		{
			cout << playerOne << "\nWins!!!!!!";
			++tWins;
		}

		if (playerOneChoice == 2 && computerChoice == 1)
		{
			cout << playerOne << "\nWins!!!!!!\n";
			++tWins;
		}

		if (playerOneChoice == 3 && computerChoice == 2)
		{
			cout << playerOne << "\nWins!!!!!!";
			++tWins;
		}

		//Outcomes for the player to lose
		if (playerOneChoice == 1 && computerChoice == 2)
		{
			cout << "Sorry you lose :( " << playerOne;
			++tLoses;
		}

		if (playerOneChoice == 2 && computerChoice == 3)
		{
			cout << "Sorry you lose :( " << playerOne;
			++tLoses;
		}

		if (playerOneChoice == 3 && computerChoice == 1)
		{
			cout << "Sorry you lose :( " << playerOne;
			++tLoses;
		}

		if (playerOneChoice == computerChoice)
		{
			cout << " \n It's a tie!!!";
			++tTies;
		}

		//Opens the user file 
		userOut.open("C:\\Temp\\" + playerOne + ".txt");

		userOut << tWins << endl;
		userOut << tLoses << endl;
		userOut << tTies << endl;

		//closes the file
		userOut.close();

		cout << "\nWould you like to play again? \n1. for yes \n2. for no\n ";
		cin >> quitGame;

		if (quitGame == 2)
		{
			cout << " \n Thank you for playing";
		}

	}
	return 0;
}
