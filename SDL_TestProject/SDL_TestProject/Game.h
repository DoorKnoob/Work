#pragma once
#include "SDL.h"

class Game
{
private:
	bool m_bRunning; // Control variable
	SDL_Window* m_pWindow; // Pointer to an SDL window
	SDL_Renderer* m_pRenderer; // Pointer to an SDL rendere

public:

	Game() {}  // Game's Constructor. Gets called upon object creation
	~Game() {} // Game's Destructor. Gets called upon de-allocation

	bool init() {} // Used for engine initialization
	bool running() {} // Used in the main while loop
	void update() {} // Entire game broken down here
	void handleEvents() {} // User input and event handling
	void render() {} // Outputs changes in game to user
	void clean() {} // Final call to cleanup
}; 