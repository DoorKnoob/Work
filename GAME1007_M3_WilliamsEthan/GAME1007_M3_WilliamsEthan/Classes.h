#pragma once
#define ROWS 24
#define COLS 32
/* Important note: x coordinate is player's COLUMN position and
   y coordinate is player's ROW position. Don't mix these up! */

struct Sprite
{
public:
	char m_cOutput;
	SDL_Rect m_rSrc; //Source Rectangle
	SDL_Rect m_rDst; //Destination Rectangle
	SDL_Texture* m_pTexture;
	SDL_Renderer* m_pRenderer;

	Sprite() //Default Constructor
	{

	}
	~Sprite()//Deconstructor
	{

	}

	void SetX(int x)
	{
		m_rDst.x = x * 32; 
	}

	void SetY(int y)
	{
		m_rDst.y = y * 32;
	}

	void SetImage(SDL_Renderer* r, SDL_Texture* t)
	{
		m_pRenderer = r;
		m_pTexture = t; 
	}
};


class LOTile : public Sprite
{

public:

	int m_x;
	int m_y;


	LOTile() //Default Constructor
	{


	}

	LOTile(int x, int y) // Non-Default Constructor
	{
		m_x = x;
		m_y = y;
		SetX(x);
		SetY(y); 
	}
};

class BGTile : public Sprite
{

public:
	bool m_bIsObstacle;
	bool m_bIsHazard;
	
	void SetBGTile(const char output)
	{
		m_cOutput = output;
		m_bIsObstacle = false;
		m_bIsHazard = false;
	}
	void SetRec()
	{
		if (m_cOutput == '.')
			m_rSrc = { 0, 0, 32, 32 };
		else if (m_cOutput == 'M')
			m_rSrc = { 32, 0, 32, 32 };
	}
	
	


};

class Player : public LOTile
{
public:

	int m_iSpeed;
	int m_iFrameCtr = 0;
	int m_iFrameMax = 6;
	bool m_bRight = true;

	void UpdateDst()
	{
		m_rDst.x = m_x;
		m_rDst.y = m_y;
	}

	Player(int x, int y, SDL_Renderer* r, SDL_Texture* t) : LOTile(x, y)

	{
		m_pRenderer = r; 
		m_rSrc = { 0, 0, 32, 32 };	
		SetImage(r, t); 
		m_rDst.w = 32;
		m_rDst.h = 32;
		m_cOutput = '@';
		UpdateDst();
	}

	void MoveX(int m)
	{
		m_x += m * m_iSpeed;
		UpdateDst();
	}
	void MoveY(int m)
	{
		m_y += m * m_iSpeed;
		UpdateDst();
	}
	const SDL_Rect* GetSrc() { return &m_rSrc; }
	const SDL_Rect* GetDst() { return &m_rDst; }
	void AdvanceAnim()
	{
		m_iFrameCtr++;
		if (m_iFrameCtr == m_iFrameMax)
		{
			m_iFrameCtr = 0; // Resetting frame counter.
		}
		m_rSrc.x = 44 * m_iFrameCtr; // Prints appropriate 'cell.'

	}
	void SetIdle()
	{
		m_iFrameCtr = 0;
		m_rSrc.x = 44 * m_iFrameCtr;
	}
};


class Door : public LOTile
{
public:
	int m_iToLevel;
	int m_iDestX;
	int m_iDestY;

	Door()
	{
		m_cOutput = 'D';
	}


	void SetDoor(const int x, const int y, const int iToLevel, const int iDestX, const int iDestY, SDL_Renderer* r, SDL_Texture* t)
	{

		m_x = x;
		m_y = y;
		m_iToLevel = iToLevel;
		m_iDestX = iDestX;
		m_iDestY = iDestY;
		SetX();
		SetY();
		SetImage(); 
	}

};


class Level
{
public:

	int m_iNumDoors;
	BGTile map[24][32];
	Door doors[3]; //Keeps track of doors in level

	Level()// Default Constructor
	{
		m_iNumDoors = 0;
	}

	void AddDoor(const int m_x, const int m_y, const int m_iToLevel, const int m_iDestX, const int m_iDestY, SDL_Renderer* r, SDL_Texture* t)
	{

		if (m_iNumDoors < 3)
		{
			doors[m_iNumDoors].SetDoor(m_x, m_y, m_iToLevel, m_iDestX, m_iDestY, r, t);
			m_iNumDoors++;
		}
	}
};


