#include <iostream>
using namespace std; 


int main()
{
	char option[10];
	cout << "Please enter a word. Must be a maximum of 10 characters ";
	cin.getline(option, 10); 

	cout << endl << strlen(option) << endl;
	for (int i = strlen(option); - i >=0; i--)
	{
		cout << option[1]; 
	}


	int vowlCount = 0;

	for (int i = 0; i < strlen(option); i++)
	{
		option[i] == 'e', option[i] == 'i', option[i] == 'o', option[i] =='u', option[i] == 'y', vowlCount++;
	}

	cout <<"The amount of vowels are " vowlCount << endl;


	system("pause");
	return 0;
}