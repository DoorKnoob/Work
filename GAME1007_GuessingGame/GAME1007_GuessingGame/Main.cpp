//Main.cpp
//Author: Ethan Williams
//Created: 18/09/2018

#include<iostream> 
#include<string>  //For the string type.
#include<ctime>   //For the time() function.
using namespace std; 

int main(void)
{
	//Variables
	string playerOne, playerTwo;
	int randomNumber, guess, currentPlayer;
	bool quitGame = false;

	//Generates a random number between 1 and 100.
	srand((unsigned)time(0)); //Seeding random bumber sequence.

	randomNumber = 1 + rand() % 100; //Gets 1 to 100.                             

	//Get player names
	cout << "Enter name for player one: ";
	cin >> playerOne;
	cout << "Enter name for player two: ";
	cin >> playerTwo;

	//randomize who goes first
	currentPlayer = 1 + rand() % 2; //Gets 1 to 2.

	//Start the game
	while (quitGame == false) // Quits game. 
	{
		//Current player makes their guess
		cout << (currentPlayer == 1 ? playerOne : playerTwo) << ", enter your guess: ";
		cin >> guess;
		if (guess > randomNumber)
			cout << "Your guess is too high...\n";

		else if (guess < randomNumber)
			cout << "Your guess was too low...\n";

		if (guess == randomNumber)

		{
			cout << (currentPlayer == 1 ? playerOne : playerTwo) << "Wins!!!";	
			quitGame = true;
		}
	
	}
	system("pause");
	return 0;
}