#include <iostream>
using namespace std;
void ticketCost(int selection, double ticket);

int main()
{
	int selection;
	double basePrice = 20;

	cout << "Please make your selection from the menu below!\n";
	cout << "1. Adult [15 - 64]\n";
	cout << "2. Child [0 - 14]\n";
	cout << "3. Senior [65 - ]\n";
	cout << "4. Exit\n\n";
	cout << "And your selection is: ";

	cin >> selection;

}

void ticketCost(int selection, double ticket)
{
	return ticketCost(selection, ticket);

	if (selection == 1)
	{
		cout << "\n\nThe price for your ticket is $" << basePrice;
	}
	else if (selection == 2)
	{
		cout << "\nThe price for your ticket is $" << (basePrice * 0.5);
	}
	else if (selection == 3)
	{
		cout << "\nThe price for your ticket is $" << (basePrice * 0.8);
	}
	
	else if
	{
		return (-1);
	}
}