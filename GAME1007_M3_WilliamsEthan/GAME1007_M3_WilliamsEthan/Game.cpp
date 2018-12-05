#include <iostream>
#include "Game.h"
using namespace std;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	//Attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success\n";
		//Initialize the window 
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) //Window Initialize sucesses
		{
			cout << "window creation was successful\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) //Rendere Init Success 
			{
				cout << "renderer Creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				cout << "renderer initialize failed\n";
				return false; //Renderer init failed
			}
		}
		else
		{
			cout << "window initialize failed\n";
			return false; //Window init failed
		}

		IMG_Init(IMG_INIT_PNG); // Initializing image system.
		m_image = IMG_Load("Player.png");
		if (m_image == 0)
		{
			cout << "image load fail" << endl;
			return false;
		}

	}
	else
	{
		cout << "SDL initialize failed\n";
		return false; //SDL init failed
	}
	cout << "Initialize was a success\n";
	m_bRunning = true; //Everything is working. 
	return true;
}

bool Game::running()
{
	return m_bRunning;
}

void Game::update()
{
	//Empty for now
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		}
	}
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //Clears the screen to the draw colour
	SDL_RenderPresent(m_pRenderer); //Draw anew
}

void Game::clean()
{
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}