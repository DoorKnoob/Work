// This program demonstrates the use of a structure. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
private:
	int    empNumber;  // Employee number
	string name;       // Employee name
	double hours,      // Hours worked
		payRate;    // Hourly pay rate
public:
	Employee(int empN, string n, double h, double p)
	{
		empNumber = empN;
		name = n;
		hours = h;
		payRate = p;
	}

	Employee()
	{
		empNumber = 0;
		name = "No Name";
		hours = 0;
		payRate = 0;
	}
	void setEmpNumber(int number)
	{
		empNumber = number;
	}

	void setName(string n)
	{
		name = n;
	}

	void setPayRate(double rate)
	{
		payRate = rate;
	}

	void setHours(double h)
	{
		hours = h;
	}

	int getEmpNumber()
	{
		return empNumber;
	}

	string getName()
	{
		return name;
	}

	double getHours()
	{
		return hours;
	}

	double getPayRate()
	{
		return payRate;
	}

	double getWage()
	{
		return payRate * hours;
	}

	string getEmpData()
	{
		string data = "\nEmployee ID Number ===> " + to_string(empNumber);
		data += "\nEmployee Name ========> " + name;
		data += "\nHours Worked =========> " + to_string(hours);
		data += "\nPay Rate =============> " + to_string(payRate);
		data += "\nTotal Wage ===========> " + to_string(getWage());
		data += "\n";

		return data;
	}



};

int main()
{
	Employee emp1(1, "John", 40, 25);  // Employee is a PayRoll structure
	double hours, rate, grossPay;   // Gross amount the employee earned this week
	int empNumber;
	string name;
	//Get the employee's data

	cout << "Enter the employee's number: ";
	cin >> empNumber;
	emp1.setEmpNumber(empNumber);

	cout << "Enter the employee's name: ";
	cin.ignore();	   // Skip the '\n' character left in the input buffer
	getline(cin, name);
	emp1.setName(name);

	cout << "Hours worked this week: ";
	cin >> hours;
	emp1.setHours(hours);

	cout << "Employee's hourly pay rate: ";
	cin >> rate;
	emp1.setPayRate(rate);



	// Display the results
	cout << "\nHere is the emp1 data:\n";
	cout << emp1.getEmpData();

	Employee emp2;
	emp2.setEmpNumber(1);
	emp2.setName("John");
	emp2.setHours(35);
	emp2.setPayRate(20);

	// Display the results
	cout << "\nHere is the emp2 data:\n";
	cout << emp2.getEmpData();

	if (emp1.getWage() > emp2.getWage())
	{
		cout << "The employee below made more money last week:\n";
		cout << emp1.getEmpData();
	}
	else if (emp2.getWage() > emp1.getWage())
	{
		cout << "The employee below made more money last week:\n";
		cout << emp2.getEmpData();
	}
	else
	{
		cout << "Both employees made the same amount of money!";
	}

	system("pause");
	return 0;
}