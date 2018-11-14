#include <iostream>
#include "Weapon.h"
using namespace std; 

int main()
{
	Weapon pistol; 
	pistol.SetSound ("Bang!");
	pistol.Use();
	system("pause");
	return 0;
}