#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Car
{

private:
	int m_cost;
	bool m_owned; 
	string m_name;
	string m_sound; 

public:
	Car() // Defualt Constructor
	{

	}
		
	Car(string name, int cost, string sound) // Non Default Constructor
	{
		m_name = name;
		m_cost = cost;
		m_sound = sound;
	}
	
	string GetSound() // Getter
	{
		return m_sound; 
	}

	string& GetName() // Getter
	{
		return m_name;
	}

	void SetOwned(bool owned) // Setter
	{
		m_owned = owned;
	}

	void Start()
	{
		cout << m_sound << endl;
	}
};
