#include <iostream>
#include "Game.h"

Game* g_game = 0;

int main(int argc, char *args[]) // Main header must be this.
{
	g_game = new Game();
	g_game->init("My First Game Engine", 100, 100, 640, 480, 0);
	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	system ("pause");
	return 0;
}