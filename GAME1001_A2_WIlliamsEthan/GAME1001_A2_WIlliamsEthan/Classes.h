#pragma once
#include <string>
using namespace std; 
class Weapon
{
public:
	bool m_owned;
	string m_name;
	string m_sound; 
	int m_cost; 

	Weapon() //Default Constructor
	{
		
	}
	
	Weapon(bool m_owned, string m_name, string m_sound, int m_cost) //Constructor
	{
		this-> m_owned = m_owned; 
		this-> m_name = m_name;
		this->m_sound = m_sound;
		this->m_cost = m_cost;
	}

	string getName()
	{
		return m_name; 
	}

	int getCost()
	{
		return m_cost; 
	}

	string getSound()
	{
		return m_sound; 
	}

	bool getOwned()
	{
		return m_owned;
	}

	void setOwned(bool o)
	{
		m_owned = o; 
	}
};

