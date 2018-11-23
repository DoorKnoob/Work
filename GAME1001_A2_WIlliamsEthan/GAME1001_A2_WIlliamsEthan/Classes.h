#pragma once

class Weapons
{
public:
	bool m_owned; 
	string m_name;
	string m_sound; 
	
	Weapons() // Default Constructor
	{

	}

	Weapons(string name, string sound, bool owned) //Constructor
	{
		m_owned = owned;
		m_name = name;
		m_sound = sound;
	}



};

