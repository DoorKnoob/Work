#include <iostream>
#include <fstream>
#include "Game.h"
#include "SDL.h"
#include "Classes.h"
#include "SDL_image.h"

using namespace std;
#define ROWS 24
#define COLS 32
	

bool BuildMap(Level& l, const char* n, SDL_Renderer* r, SDL_Texture* t) // Passing 2D array to function.
{
	ifstream inFile(n);
	if (inFile.is_open())
	{
		char temp;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> temp;
				l.map[row][col].SetBGTile(temp);
				l.map[row][col].SetImage(r, t);
				l.map[row][col].m_rDst = { col * 32, row * 32, 32, 32 };
				SDL_RenderCopy(m_pRenderer, l.map[row][col].m_pTexture, &l.map[row][col].m_rSrc, &l.map[row][col].m_rDst);
				if (temp == 'M' || temp == '#' || temp == 'B' || temp == 'O' || temp == '%') //Obstacles
					l.map[row][col].m_bIsObstacle = true;
				if (temp == 'X') // Hazards
					l.map[row][col].m_bIsHazard = true;
			}
		}
		return 0;
	}
	return 1;
}

int main(int argc, char* args[])
{
	Game game; //Defining game object 
	game.init("GAME1007_M3_WilliamsEthan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	Level levels[5];
	int currLevel = 0;
	SDL_Surface* tileSurf = IMG_Load("Tiles.png");
	SDL_Texture* tileText = SDL_CreateTextureFromSurface(game.GetRenderer(), tileSurf);
	SDL_Surface* playerSurf = IMG_Load("Player.png");
	SDL_Texture* playerText = SDL_CreateTextureFromSurface(game.GetRenderer(), playerSurf);

	if (BuildMap(levels[0], "Level1.txt", game.GetRenderer(), tileText) == 1)
		return 1;

	if (BuildMap(levels[1], "Level2.txt", game.GetRenderer(), tileText) == 1)
		return 1;

	if (BuildMap(levels[2], "Level3.txt", game.GetRenderer(), tileText) == 1)
		return 1;

	if (BuildMap(levels[3], "Level4.txt", game.GetRenderer(), tileText) == 1)
		 
	Player player(COLS / 2, ROWS / 2, game.GetRenderer(), playerText);
	while (game.running())
	{
		game.handleEvents();
		if (game.tick())
		{
			game.update(l[currLevel], p, currLevel);
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
}