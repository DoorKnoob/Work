#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Player.h"
#define FPS 60

class Game
{
private:
	bool m_bRunning;
	// Added for W11
	bool m_bGotTick;
	bool m_bUpPressed;
	bool m_bDownPressed;
	bool m_bLeftPressed;
	bool m_bRightPressed;
	int m_iFPS;
	int m_iTickCtr = 0; // In-class initialization - okay for now.
	int m_iTickMax = 8; // Determines animation speed.
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_image;
	SDL_Texture* m_texture;
public:
	Game() :m_iFPS(FPS), m_bGotTick(false), m_bUpPressed(false),
		    m_bDownPressed(false), m_bLeftPressed(false), m_bRightPressed(false) {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width,
		      int height, int flags);
	bool running();
	bool tick();
	void update(Player& p);
	void handleEvents();
	void render(Player& p);
	void clean();
};
