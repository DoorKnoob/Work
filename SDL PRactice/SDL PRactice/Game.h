#ifndef __Game__
#define __Game__

class Game
{
public:

	Game() //Constructor
	{
	
	}

	~Game() //Deconstructor
	{
	
	}

	void init() { m_bRunning = true; }


	void render() {}
	void update() {}
	void handleEvents() {}
	void clean() {}

	//Function for accessing the private variable
	bool running() 
	{
		return m_bRunning;
	}

private:
	SDL_Window* m_pWindow; 
	SDL_Renderer* m_pRenderer; 

	bool m_bRunning;

	bool init(const char * title, int xpos, int ypos, int width, int height, int flags);

};

#endif //Defined __Game__

