#include <iostream>
#include "Game.h"
using namespace std; 

Game* g_game = nullptr; // Pointer to a game object. Initialized to 'null'

int main(int argc, char* args[])
{
	Game game; //Defining game object 
	game.init(" ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	while (game.running())
	{
		game.handleEvents();
		game.update();
		game.render();
	}
	game.clean();
	system("pause");
	return 0; 
}