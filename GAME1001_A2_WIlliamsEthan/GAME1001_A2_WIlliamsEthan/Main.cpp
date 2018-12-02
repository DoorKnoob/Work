#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

void printMoney(const int& m)
{
	cout << "Balance: $" << m << endl;
}

int main()
{
	Weapon weapon[5] = { Weapon(false, "Pistol", "Bang Bang!!!", 100),
	 Weapon(false, "Rifle", "Bratata!!", 200 ),
	 Weapon(false, "Sword", "Shiiiiiiiiiinggg!", 300),
	 Weapon(false, "Shotgun", "BOOM Chk Chk!!!", 500),
	 Weapon(false, "Rocket Launcher", "Booooooom!!!", 750) };
	

	bool inStore = true, viewStore, inSimulation = true;
	char option;
	int numWeapons = 0, pMoney = 1000;
	



	while (inStore == true) // Store stage.
	{
		viewStore = true;
		cout << "Hello and welcome to the store. What would you like to do?\n Buy a Weapon (B), check your balance (C), or exit the store and proceed to the simulation? (X)";
		cin >> option; 
		
		if (option == 'B' || option == 'b') // this checks for lower and uppercase
		{
			
			while (viewStore == true)
			{
				for (int i = 0; i < 5; i++)
				{
					cout << weapon[i].getName() << "\t $" << weapon[i].getCost() << endl;
				}

				cout << "Please select the weapon you would like to buy or, press E if you would like to leave.\n";
				cin >> option;



				if (option == '1')
				{
					if (pMoney < weapon[0].getCost())
					{
						cout << "Sorry you don't have enough for that weapon\n";
					}
					else if (pMoney >= weapon[0].getCost())
					{
						weapon[0].setOwned(true);
						pMoney -= weapon[0].getCost();
						cout << weapon[0].getName() << " purchased" << endl;
					}
				}

				else if (option == '2')
				{
					if (pMoney < weapon[1].getCost())
					{
						cout << "Sorry you don't have enough for that weapon\n";
					}
					else if (pMoney >= weapon[1].getCost())
					{
						weapon[1].setOwned(true);
						pMoney -= weapon[1].getCost();
						cout << weapon[1].getName() << " purchased" << endl;
					}
				}

				else if (option == '3')
				{
					if (pMoney < weapon[2].getCost())
					{
						cout << "Sorry you don't have enough for that weapon\n";
					}
					else if (pMoney >= weapon[2].getCost())
					{
						weapon[2].setOwned(true);
						pMoney -= weapon[2].getCost();
						cout << weapon[2].getName() << " purchased" << endl;
					}
				}

				else if (option == '4')
				{
					if (pMoney < weapon[3].getCost())
					{
						cout << "Sorry you don't have enough for that weapon\n";
					}
					else if (pMoney >= weapon[3].getCost())
					{
						weapon[3].setOwned(true);
						pMoney -= weapon[3].getCost();
						cout << weapon[3].getName() << " purchased" << endl;
					}
				}

				else if (option == '5')
				{
					if (pMoney < weapon[3].getCost())
					{
						cout << "Sorry you don't have enough for that weapon\n";
					}
					else if (pMoney >= weapon[4].getCost())
					{
						weapon[4].setOwned(true);
						pMoney -= weapon[4].getCost();
						cout << weapon[4].getName() << " purchased" << endl;
					}
				}

				else if (option == 'E' || 'e')
				{
					viewStore = false; 
				}
			}
		}

		if (option == 'C' || option == 'c')
		{
			cout << "\nYour current balance is $" << pMoney << endl;
		}

		if (option == 'X' || option == 'x')
		{

			if (!weapon[0].getOwned() && !weapon[1].getOwned() && !weapon[2].getOwned() && !weapon[3].getOwned() && !weapon[4].getOwned())
			{
				cout << "You don't own any weapons yet!" << endl;
			}
			else
			{
				inStore = false;
				cout << "Have fun!" << endl;
			}
		}
	}

	while (inSimulation == true)
	{
		//system("cls");
		cout << "Welcome to the simulation. Please select the weapon that you would like to equip." << endl;

		for (int i = 0; i < 5; i++)
		{
			if (weapon[i].getOwned())
			{
				cout << weapon[i].getName() << endl;
			}
		}
		cin >> option; 

		if (option == '1')
		{
			cout << "You have chosen the pistol. Press E to shoot.\n"; 

		}


		if (option == '2')
		{
			cout << "You have chosen the rifle. Press E to shoot.\n";
		}

		if (option == '3')
		{
			cout << "You have chosen the sword. Press E to shoot.\n";
		}

		if (option == '4')
		{
			cout << "You have chosen the shotgun. Press E to shoot.\n";
		}

		if (option == '5')
		{
			cout << "You have chosen the rocket launcher. Press E to shoot.\n";
		}



	}












	system("pause");
	return 0;
}