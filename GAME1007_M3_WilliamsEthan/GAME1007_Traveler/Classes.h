#pragma once
#define ROWS 24
#define COLS 32
#include "SDL.h"
/* Important note: x coordinate is player's COLUMN position and
   y coordinate is player's ROW position. Don't mix these up! */

struct Sprite
{
public:
	char m_cOutput;
	SDL_Rect m_rSrc; 
	SDL_Rect m_rDst; 
	SDL_Texture* m_pTexture; 
	SDL_Renderer* m_pRenderer; 

	Sprite() //Default Constructor
	{

	}
	
	~Sprite()
	{

	}

	void SetX(int x)
	{
		m_rDst.x = x * 32; 
	}

	void Sety(int y)
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
	int SetX(int x); 
	int SetY;
	
	LOTile() //Default Constructor
	{


	}

	LOTile(int x, int y) // Non-Default Constructor
	{
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

};

class Player : public LOTile
{
public:

	Player(int x, int y) : LOTile(x, y)

	{
		m_cOutput = '@';
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


	void SetDoor(const int x, const int y, const int iToLevel, const int iDestX, const int iDestY)
	{

		 m_x = x;
		 m_y = y;
		 m_iToLevel = iToLevel;
		 m_iDestX = iDestX;
		 m_iDestY= iDestY;
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

	void AddDoor(const int m_x, const int m_y, const int m_iToLevel, const int m_iDestX, const int m_iDestY)
	{

		if (m_iNumDoors < 3)
		{
			doors[m_iNumDoors].SetDoor(m_x, m_y, m_iToLevel, m_iDestX, m_iDestY);
			m_iNumDoors++; 
		}
	}
};


