
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//Variables
	int number1, number2, sum = 0;

	cout << "Please enter two numbers\n If it is negative exit\n";
	cin >> number1 >> number2;

	while (number1 + number2 >= 0)
	{

		sum += number1 + number2;
		cout << "Please enter a number. If it is negative then exit\n";
		cin >> number1 >> number2;
	}

	cout << "The sum of the numbers you have just entered is\n" << sum; 
 

	return 0;
}