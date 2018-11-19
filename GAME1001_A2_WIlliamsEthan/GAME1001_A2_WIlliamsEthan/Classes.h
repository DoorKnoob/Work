#pragma once

class Pistol 
{
public:
	bool m_owned; 
	string m_name;
	string m_sound; 
	
	Pistol() // Default Constructor
	{

	}

	Pistol(string name, string sound, bool owned) //Constructor
	{
		m_owned = owned;
		m_name = name;
		m_sound = sound;
	}



};

