#include <iostream>
#include <fstream>
#include <conio.h> // Sorry non-Windows users.
#include "Classes.h"
using namespace std;
#define ROWS 24
#define COLS 32

bool BuildMap(BGTile m[][COLS]) // Passing 2D array to function.
{
	ifstream inFile("Level.txt");
	if (inFile.is_open())
	{
		char temp;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> temp;
					m[row][col].m_cOutput = temp;
					if (temp == 'M' || temp == '#') //Obstacles
					m[row][col].m_bIsObstacle = true;
					if (temp == 'X') // Hazards
						m[row][col].m_bIsHazard = true;
			}
		}
		return 0;
	}
	return 1;
}

void PrintMap(BGTile m[][COLS], Player& p)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (row == p.m_y && col == p.m_x)
				cout << '@';
			else
				cout << m[row][col].m_cOutput;
		}
		cout << endl;
	}
}

int main()
{
	bool quit = false;
	BGTile map[ROWS][COLS]; // 2D array of characters.
	char input;
	Player player(COLS / 2, ROWS / 2);

	if (BuildMap(map) == 1)
		return 1;
	while (!quit)
	{
		PrintMap(map, player);
		input = _getch();
		switch (input)
		{
		case 'w':  // Up.
			if (player.m_y > 0 && !map[player.m_y - 1][player.m_x].m_bIsObstacle)
				if (player.m_y > 0) // How can we add to these checks to account for the '#' obstacles?
					player.m_y--;
			break;
		case 's': // Down.
			if (player.m_y < ROWS - 1 && !map[player.m_y + 1][player.m_x].m_bIsObstacle)
				player.m_y++;
			break;
		case 'a': // Left.
			if (player.m_x > 0 && !map[player.m_y][player.m_x - 1].m_bIsObstacle)
				player.m_x--;
			break;
		case 'd': // Right.
			if (player.m_x < COLS - 1 && !map[player.m_y][player.m_x + 1].m_bIsObstacle)
				player.m_x++;
			break;
		case 'q':
			quit = true;
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}