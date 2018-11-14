#include <iostream>
using namespace std; 

void printBoard(char* b)
{
	cout << endl << (b[0] == '.' ? '0' : b[0]) << '|' << (b[1] == '.' ? '1' : b[1]) << '|' << (b[2] == '.' ? '2' : b[2]) << endl;
	cout << "-----" << endl;
	cout << (b[3] == '.' ? '3' : b[3]) << '|' << (b[4] == '.' ? '4' : b[4]) << '|' << (b[5] == '.' ? '5' : b[5]) << endl;
	cout << "-----" << endl;
	cout << (b[6] == '.' ? '6' : b[6]) << '|' << (b[7] == '.' ? '7' : b[7]) << '|' << (b[8] == '.' ? '8' : b[8]) << endl << endl;
}

int main()
{
	printBoard();
	bool newGame = true;
	bool gameOn = true;
	bool validInput;
	int playerIndex = 0;
	char choice;
	char pieces;
	char pieces[2] = { '0' , 'X' };
	char board[9];

	while (newGame == true)
	{
		for (int i = 0; i < 9; i++)
			board[i] = '.';
		while (gameOn == true)
		{
			validInput = false; 
			while (validInput == false)
			{
				printBoard(board); 
			}
		}
		
	}

	
	
	
	
	
	
	
	
	
	
	system("pause");
	return 0;

 }












	