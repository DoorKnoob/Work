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


Employee findHigh(Employee list[], int size);
Employee findLow(Employee list[], int size);
void sortEmployeesASC(Employee list[], int size);
void sortEmployeesDSC(Employee list[], int size);
double avgWage(Employee list[], int size);
int aboveAvg(Employee list[], int size);
double belowAvg(Employee list[], int size);
Employee* searchEmployee(Employee list[], int size, int empID);
void printEmployee(Employee list[], int size);

int main()
{
	const int NUM_EMPLOYEES = 4;
	int empID;

	Employee list[NUM_EMPLOYEES];
	list[0] = Employee(1, "John", 40, 25);
	list[1] = Employee(2, "Mary", 30, 40);
	list[2] = Employee(3, "Grace", 35, 30);
	list[3] = Employee(4, "Mark", 45, 20);

	void printEmployee(Employee list[], int size);

	cout << "Employee with the highest wage is: " << findHigh(list, NUM_EMPLOYEES).getEmpData();
	cout << "Employee with the lowest wage is: " << findLow(list, NUM_EMPLOYEES).getEmpData();


	sortEmployeesASC(list, NUM_EMPLOYEES);

	for (int i = 0; i < NUM_EMPLOYEES; i++)
	{
		cout << list[i].getEmpData();
	}

	cout << endl << "The average wage of employees is: " << avgWage(list, NUM_EMPLOYEES);

	cout << endl << "The number of employees above average wage is: " << aboveAvg(list, NUM_EMPLOYEES);

	cout << endl << "The number of employees below average wage is: " << belowAvg(list, NUM_EMPLOYEES);

	cout << endl << endl << "Please enter an employee ID number: ";
	cin >> empID;

	Employee * emp = searchEmployee(list, NUM_EMPLOYEES, empID);

	if (emp != NULL)
	{
		cout << endl << endl << "Employee successfully found. This is the information:" << endl;
		cout << emp->getEmpData();
	}
	else
	{
		cout << endl << endl << "Employee Not Found!";
	}

	system("pause");
	return 0;
}

Employee findHigh(Employee list[], int size)
{

	Employee high = list[0];
	for (int i = 0; i < size; i++)
		if (list[i].getWage() > high.getWage())
		{
			high = list[i];
		}
	return high;
}

Employee findLow(Employee list[], int size)
{

	Employee low = list[0];
	for (int i = 0; i < size; i++)
		if (list[i].getWage() < low.getWage())
		{
			low = list[i];
		}
	return low;
}

void sortEmployeesASC(Employee list[], int size)
{
	Employee emp;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (list[i].getWage() > list[j].getWage())
			{
				emp = list[i];
				list[i] = list[j];
				list[j] = emp;
			}
}

void sortEmployeesDSC(Employee list[], int size)
{
	Employee emp;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (list[i].getWage() < list[j].getWage())
			{
				emp = list[i];
				list[i] = list[j];
				list[j] = emp;
			}
}

double avgWage(Employee list[], int size)
{
	double avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += list[i].getWage();
	}

	return avg / size;

}

int aboveAvg(Employee list[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].getWage() > avgWage(list, size))
		{
			++count;
		}
	}
	return count;
}

double belowAvg(Employee list[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].getWage() < avgWage(list, size))
		{
			++count;
		}
	}
	return count;
}

Employee* searchEmployee(Employee list[], int size, int empID)
{
	Employee* emp = NULL;
	bool found = false;
	int i = 0;
	while (!found && i < size)
	{
		if (list[i].getEmpNumber() == empID)
		{
			found = true;
			emp = &list[i];
		}
		i++;
	}
	return emp;
}

void printEmployee(Employee list[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << list[i].getEmpData();
	}
}