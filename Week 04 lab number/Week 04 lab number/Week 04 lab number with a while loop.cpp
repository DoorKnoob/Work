
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//Variables
	int number, sum = 0;
	
	
	cout << "Please enter a positive number ";
	cin >> number;

	
	
if (number < 0)
	{
		number = -number; 
	}

	for (int i = 1; i <= number; i++)
	{
		sum += i; 
	}

cout << "The sum of the number from 1 to " << number << " is \n " << sum << endl;

return 0;
}

