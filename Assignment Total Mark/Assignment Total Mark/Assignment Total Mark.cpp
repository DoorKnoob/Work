

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	double finalExam;
	double midTerm; 
	double labs;
	double assignment1;
	double assignment2;
	

	cout << "What was your mark on the final exam?\n";
	cin >> finalExam;

	cout << "What was your mark on the mid term?\n";
	cin >> midTerm;

	cout << "What was your mark on the labs\n";
	cin >> labs;

	cout << "What was your mark on the first assignment?\n";
	cin >> assignment1;

	cout << "What was your mark on the second assignment?\n";
	cin >> assignment2;

	double finalMark = finalExam + midTerm + labs + assignment1 + assignment2;
	
	cout << "Your final mark is \n" << finalMark << endl;

	if (finalMark >= 90)
	{
		cout << "Your final grade is a A+";
	}

	else if (finalMark >=80 <90)
	{
		cout << "Your final grade is a A";
	}

	else if (finalMark >= 70 < 80)
	{
		cout << "Your final grade is a B";
	}

	else if (finalMark >= 60 < 70)
	{
		cout << "Your final grade is a C";
	}

	else if (finalMark >= 50 < 60)
	{
		cout << "Your final grade is a D";
	}

	else if (finalMark <50)
	{
		cout << "You have failed this course";
	}
}

