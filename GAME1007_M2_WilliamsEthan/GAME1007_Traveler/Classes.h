#pragma once

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


class Door : public LOTile
{
public:



};

class Player : public LOTile
{
public:

	Player(int x, int y)
	:LOTile(x, y)
	{
		
		m_cOutput == '@'; 
	}
	
};

class BGTile : public Sprite
{

public:
	bool m_bIsObstacle;
	bool m_bIsHazard;

	BGTile()
	{
		m_bIsObstacle = false;
		 m_bIsHazard = false;
	}

};






