#include <iostream>
#include <fstream>
#include <conio.h> // Sorry non-Windows users.
#include "Classes.h"
using namespace std;
#define ROWS 24
#define COLS 32

bool BuildMap(Level& l, const char* n) // Passing 2D array to function.
{
	ifstream inFile("Level1.txt");
	ifstream inFile("Level2.txt"); 
	if (inFile.is_open())
	{
		char temp;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> temp;
					l.map[row][col].m_cOutput = temp;
					if (temp == 'M' || temp == '#') //Obstacles
					l.map[row][col].m_bIsObstacle = true;
					if (temp == 'X') // Hazards
						l.map[row][col].m_bIsHazard = true;
			}
		}
		return 0;
	}
	return 1;
}

void PrintMap(Level& l, Player& p)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (row == p.m_y && col == p.m_x)
				cout << '@';

			else
				cout << l.map[row][col].m_cOutput;
		}
		cout << endl;
	}
}


void checkDoor(Level, Player)
{
	
}

int main()
{
	bool quit = false;
	Level levels[5]; // Single demention array 
	char input;
	int currLevel = 0;
	Player player(COLS / 2, ROWS / 2);

	if (BuildMap(levels[0], "Level1.txt") == 1)
		return 1;
	levels[0].AddDoor(18, 18, 1, 15, 2); 

	if (BuildMap(levels[1], "Level2.txt") == 1)
		return 1;
	
		while (!quit)
	{
		PrintMap(levels[0], player);
		input = _getch();
		switch (input)
		{
		case 'w':  // Up.
			if (player.m_y > 0 && levels[currLevel].map[player.m_y - 1][player.m_x].m_bIsObstacle != true)
				if (player.m_y > 0) 
					player.m_y--;
			break;
		case 's': // Down.
			if (player.m_y < ROWS - 1 && levels[currLevel].map[player.m_y + 1][player.m_x].m_bIsObstacle != true)
				player.m_y++;
			break;
		case 'a': // Left.
			if (player.m_x > 0 && levels[currLevel].map[player.m_y][player.m_x - 1].m_bIsObstacle != true)
				player.m_x--;
			break;
		case 'd': // Right.
			if (player.m_x < COLS - 1 && levels[currLevel].map[player.m_y][player.m_x + 1].m_bIsObstacle != true)
				player.m_x++;
			break;
		case 'q':
			quit = true;
			break;
		}
		system("cls");

		if (levels[currLevel].map[player.m_y][player.m_x].m_bIsHazard == true)
		{
			quit = true;
			cout << "You have stepped in a puddle of bleach and died" << endl;
		}

		if (levels[currLevel].map[player.m_y][player.m_x].m_cOutput == 'D')
		{
			 
		}

	}
	system("pause");
	return 0;
}