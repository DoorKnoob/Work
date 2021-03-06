//#pragma once
#ifndef _CLASSES_H_
#define _CLASSES_H_

/* Important note: x coordinate is player's COLUMN position and
   y coordinate is player's ROW position. Don't mix these up! */

struct Sprite
{
	//Add a lot more stuff for M3
public:
	char m_cOutput;
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


class Player
{
public:
	int m_x;
	int m_y;
	Player(int x, int y) : m_x(x), m_y(y) // Note the initializers for the properties and empty {}.
	{
		// Nothing needed in here.
	}
};



#endif

