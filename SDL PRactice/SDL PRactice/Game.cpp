#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	//Attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL Init succesful\n";

		//Init window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	}
}