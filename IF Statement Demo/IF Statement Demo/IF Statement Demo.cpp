
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	double hoursWorked, hourlyRate;
	double regularPay, overtimePay = 0, totalPay;

	cout << "Enter number of hours worked ";
	cin >> hoursWorked;

	cout << "\n Enter number of hourly rate ";
	cin >> hourlyRate;

	
	if (hoursWorked <= 40)
	{
		regularPay = hourlyRate * hoursWorked;

	}
	else
	{
		regularPay = hourlyRate * 40;
		overtimePay = (hoursWorked - 40) * hourlyRate *1.5;
	}
	
	totalPay = regularPay + overtimePay;

	cout << "Your regular pay is $" << regularPay;
	cout << "\nYour overtime pay is $" << overtimePay;
	cout << "\nYour total pay is $" << totalPay;
	
	
	return 0;
}

