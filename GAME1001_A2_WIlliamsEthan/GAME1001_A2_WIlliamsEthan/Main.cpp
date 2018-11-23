#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;
#define NUM 5

void printMenu(void)
{
	cout << "\nBuy A Weapon [B]\nCheck Your Balance [C]\nExit The Store [X]\n\n Please Choose An Option: ";
}

void printMoney(const int& m)
{
	cout << "Balance: $" << m << endl;
}

void printBuy(const string* n, const int* c, const bool* o)
{
	for (int i = 0; i < NUM; i++)
	{
		cout << "\n" << "[" << i + 1 << "] " << n[i];
		cout << ": $" << c[i] << (o[i] == true ? " -Owned" : "");
	}
	cout << "\nReturn to Store [X]\n\nEnter Number to Buy: ";
}

int main()
{
	const int numberOfWeapons = 5;
	Weapons weapons[numberOfWeapons]; 
	bool wOwned[NUM] = { false };
	string wNames[NUM] = { "Pistol", "Shotgun", "SMG", "Rifle", "Bazooka" };
	string wActions[NUM] = { "BANG!", "BOOM!", "BRR-RAK-AK-AK-AK-AK-AK!", "RAT-TAT-TAT-TAT-TAT!", "FOOSSS-KABOOM!" };
	int wPrices[5] = { 100, 250, 500, 750, 1000 };

	bool buy, inStore = true;
	char optM, optB;
	int optI, numWeapons = 0, pMoney = 1000;

	while (inStore) // Store stage.
	{
		printMenu();
		cin >> optM;
		if (optM == 'b' || optM == 'B')
		{
			buy = true;
			while (buy == true)
			{
				printBuy(wNames, wPrices, wOwned);
				cin >> optB;
				if (optB == 'x' || optB == 'X')
					buy = 0;
				else
				{
					optI = optB - 49;
					if (wOwned[optI] == true) // Already has weapon
						cout << "Weapon already owned!" << endl;
					else if (wPrices[optI] > pMoney) // Can't afford weapon
						cout << "You cannot afford that weapon!" << endl;
					else
					{
						pMoney -= wPrices[optI];
						wOwned[optI] = true;
						numWeapons++;
						cout << "Weapon purchased!" << endl;
					}
				}
			}
		}
		else if (optM == 'c' || optM == 'C')
		{
			printMoney(pMoney);
		}
		else if (optM == 'x' || optM == 'X')
		{
			if (numWeapons > 0)
				inStore = false;
			else
				cout << "You cannot exit the store without buying one weapon!\n";
		}
	}
	cout << "\nGood-bye!" << endl;
	system("pause");
	return 0;





















	
}