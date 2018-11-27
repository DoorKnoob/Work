#include <iostream>
#include <string>
#define NUM 5 // In C++11 we can also use constexpr, but it's different.
using namespace std;

void printMenu(void)
{
	cout << "\nBuy Weapon [B]\nCheck Balance [C]\nStart Simulation [X]\n\nEnter Option: ";
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
	cout << "\nReturn to Menu [X]\n\nEnter Number to Buy: ";
}

int main()
{
	bool wOwned[NUM] = { false };
	string wNames[NUM] = { "Pistol", "Shotgun", "SMG", "Rifle", "Bazooka" };
	string wActions[NUM] = { "BANG!", "BOOM!", "BRR-RAK-AK-AK-AK-AK-AK!", "RAT-TAT-TAT-TAT-TAT!", "FOOSSS-KABOOM!" };
	int wCosts[5] = { 100, 250, 500, 750, 1000 };

	bool buy, inStore = true;
	char optM, optB;
	int optI, numWeapons = 0, pMoney = 1000;

	//While loop for the store. 
	while (inStore) // Store stage.
	{
		printMenu();
		cin >> optM;
		if (optM == 'b' || optM == 'B')
		{
			buy = true;
			while (buy == true)
			{
				printBuy(wNames, wCosts, wOwned);
				cin >> optB;
				if (optB == 'x' || optB == 'X')
					buy = 0;
				else
				{
					optI = optB - 49;
					if (wOwned[optI] == true) // Already has weapon
						cout << "Weapon already owned!" << endl;
					else if (wCosts[optI] > pMoney) // Can't afford weapon
						cout << "You cannot afford that weapon!" << endl;
					else
					{
						pMoney -= wCosts[optI];
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
				cout << "Welcome to the simulation. Please choose a weapon that you'd like to use. or press X to quit. \n";
			else
				cout << "You cannot start the simulation without a weapon!\n";
		}
	}
	cout << "\nGood-bye!" << endl;
	system("pause");
	return 0;
}