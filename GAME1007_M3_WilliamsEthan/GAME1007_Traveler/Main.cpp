#include <iostream>
#include <fstream>
#include <conio.h> // Sorry non-Windows users.
#include "Classes.h"
#include "SDL.h"
using namespace std;
#define ROWS 24
#define COLS 32

bool BuildMap(Level& l, string f) // Passing 2D array to function.
{
	ifstream inFile(f);
	if (inFile.is_open())
	{
		char temp;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> temp;
					l.map[row][col].SetBGTile(temp);
					if (temp == 'M' || temp == '#' || temp == 'B' || temp == 'O') //Obstacles
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
          if (row == l.doors[0].m_y && col == l.doors[0].m_x || row == l.doors[1].m_y && col == l.doors[1].m_x || row == l.doors[2].m_y && col == l.doors[2].m_x) {
            cout << l.doors[l.m_iNumDoors - 1].m_cOutput;
          }
          else
			if (row == p.m_y && col == p.m_x)
				cout << p.m_cOutput;

			else
				cout << l.map[row][col].m_cOutput;
		}
		cout << endl;
	}
}


void CheckDoor(Level& l, Player& p, int& c)
{
	for (int i = 0; i < l.m_iNumDoors; i++)
	{

    
		if (p.m_x == l.doors[i].m_x && p.m_y == l.doors[i].m_y)
		{
          if (c != 0 && l.doors[i].m_iToLevel == 0)
          {
            c = 0;
          }
			c = l.doors[i].m_iToLevel; 
			p.m_x = l.doors[i].m_iDestX; 
			p.m_y = l.doors[i].m_iDestY;
		}
	}
}



int main()
{
	Game game;
	game.init("GAME1007_M3_WilliamsEthan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	Level levels[5]; 

	SDL_Surface* tileSurf = IMG_Load("Tiles.png");
	SDL_Texture* tileText = SDL_CreateTextureFromSurface(game.GetRenderer(), tileSurf);
	SDL_Surface* playerSurf = IMG_Load("Player.png");
	SDL_Texture* playerText = SDL_CreateTextureFromSurface(game.GetRenderer(), playerSurf);
	
	if (BuildMap(levels[0], "Level1.txt", game.GetRenderer(), tileText) == 1)
		return 1;

	if (BuildMap(levels[1], "Level2.txt", game.GetRenderer(), tileText)) == 1)
		return 1;

	if (BuildMap(levels[2], "Level3.txt", game.GetRenderer(), tileText)) == 1)
		return 1;

	if (BuildMap(levels[3], "Level4.txt", game.GetRenderer(), tileText)) == 1)
		return 1;
	int currLevel = 0;
	Player player(COLS / 2, ROWS / 2, game.GetRenderer, playerText); 
	while (game.running())
	{
		game.handleEvents(); 
		if (game.tick())
		{
			game.update(levels[currLevel], player, currLevel);
			game.render(levels[currLevel], player);
		}
	}
	SDL_DestroyTexture(tileText);
	SDL_FreeSurface(tileSurf);
	SDL_DestroyTexture(playerText);
	SDL_FreeSurface(playerSurf);
	game.clean();
	system("pause");
	return 0;
	









	
	bool quit = false;
	Level levels[5]; // Single demention array 
	char input;
	int currLevel = 0;
	Player player(COLS / 2, ROWS / 2);
    //Doors for the first level
	levels[currLevel].AddDoor(17, 18, 1, 14, 1);
    levels[currLevel].AddDoor(21, 7, 2, 14, 1);

    if (BuildMap(levels[0], "Level1.txt") == 1)
      return 1;

	while (!quit)
	{
		PrintMap(levels[currLevel], player);
		//Doors for the second level
		if (currLevel == 1)
		{
			levels[currLevel].AddDoor(17, 18, 2, 14, 1);
			levels[currLevel].AddDoor(21, 3, 0, 14, 1);
		}
		//Doors for the third level
        if (currLevel == 2)
        {
          levels[currLevel].AddDoor(17, 18, 3, 0, 13);
          levels[currLevel].AddDoor(22, 16, 0, 14, 1);
        }

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
		

		if (levels[currLevel].map[player.m_y][player.m_x].m_bIsHazard == true)
		{
			quit = true;
			cout << "You have stepped in a puddle of bleach and died" << endl;
		}

			CheckDoor(levels[currLevel], player, currLevel);

		
		if (BuildMap(levels[0], "Level1.txt") == 1)
			return 1;
		
		if (BuildMap(levels[1], "Level2.txt") == 1)
			return 1;
		
		if (BuildMap(levels[2], "Level3.txt") == 1)
			return 1;

		if (BuildMap(levels[3], "Level4.txt") == 1)
			return 1;
        system("cls");
	}
	system("pause");
	return 0;
}