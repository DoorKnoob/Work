
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
    //Variables
	int bread, milk, cheese;
	double subtotal, total, hst;

	cout << "How many pieces of bread would you like? \n";
	cin >> bread;

	cout << "How many cartons of milk are you buying? \n";
	cin >> milk;

	cout << "How many wheels of cheese are you buying \n";
	cin >> cheese;
	
	subtotal = bread * 1.99 + milk * 3.99 + cheese * 9.99;

	hst = subtotal * 0.13;

	total = subtotal + hst;

	cout << "Your subtotal is $" << subtotal;
	cout << "\nYour amount in tax is $" << hst;
	cout << " \nYour total is $" << total;

	return 0;
}

