#include "pch.h"
#include <iostream>
using namespace std;

//Function prototypes
double sumCalc(double n1, double n2, double n3);
double prodCalc(double n1, double n2, double n3);
double avgCalc(double n1, double n2, double n3);
double powCalc(int base, int power);

int main()
{
	//Declares the variables
	double num1, num2, num3, base;
	int power;
	//Prompts the user to enter three numbers
	cout << "Enter the first number\n";
	cin >> num1;

	cout << "Enter the second number\n";
	cin >> num2;

	cout << "Enter the third number\n";
	cin >> num3;

	cout << "The sum of the three numbers is  " << sumCalc(num1, num2, num3) << endl;
	cout << "The product of the three numbers is  " << prodCalc(num1, num2, num3) << endl;
	cout << "The average of the three numbers is  " << avgCalc(num1, num2, num3) << endl;

	cout << "Enter the base";
	cin >> base;

	cout << "Enter the power";
	cin >> power;

	cout << "the power is " << power << "is equal to " << powCalc(base, power);

	return 0;
}

//Functions
double sumCalc(double n1, double n2, double n3)
{
	return n1 + n2 + n3;
}

double prodCalc(double n1, double n2, double n3)
{
	return n1 * n2 * n3;
}
double avgCalc(double n1, double n2, double n3)
{
	return sumCalc(n1, n2, n3) / 3; 
}

double powCalc(int base, int power)
{
	double result = 1;

	for (int i = 1; i <= power; i++)
	{
		result * = base; 
	}

}

