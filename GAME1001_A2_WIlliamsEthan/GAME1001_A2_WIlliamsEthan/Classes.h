#pragma once
#include <string>
using namespace std; 
class Weapon
{
public:
	bool m_owned;
	string m_name;
	string m_sound; 

	Weapon() //Default Constructor
	{
		
	}
	
	Weapon(bool m_owned, string m_name, string m_sound) //Constructor
	{
		m_owned; 
		m_name;
		m_sound;
	}
};

