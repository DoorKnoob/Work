// This program stores employee work hours in an int array. It uses
// one loop to input the hours and another loop to display them.
#include <iostream>
using namespace std;

int main()
{
	const int NUM_MARKS = 5;
	int marks[NUM_MARKS];      // Holds hours worked for 6 employees
	int count;         
	double average = 0;
	double sum = 0;  
	int highMark = 0;
	int lowMark = 0;

	 // Input the hours worked by each employee
	cout << "Enter the marks you have recieved " << NUM_MARKS
		<< " marks: ";

	for (count = 0; count < NUM_MARKS; count++)
		cin >> marks[count];

	// Display the contents of the array
	for (count = 0; count < NUM_MARKS; count++)
	{
		sum += marks[count];
	}
		
	average = sum / NUM_MARKS;

	cout << "The average of the marks is " << average;

	cout << endl;
	system("pause");
	return 0;
}
