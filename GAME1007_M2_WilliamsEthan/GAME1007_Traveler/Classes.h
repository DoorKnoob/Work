#pragma once
#define ROWS 24
#define COLS 32

/* Important note: x coordinate is player's COLUMN position and
   y coordinate is player's ROW position. Don't mix these up! */

struct Sprite
{
public:
	char m_cOutput;
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


	void SetDoor(const int m_x, const int m_y, const int m_iToLevel, const int m_iDestX, const int m_iDestY)
	{

		 m_x;
		 m_y;
		 m_iToLevel;
		 m_iDestX;
		 m_iDestY;
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


