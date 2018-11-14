#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(void)
{
	// Get a random number from 152 to 667 inclusive
	srand((unsigned)time(0));
	
	// min + rand() % ((max - min)+1) formula
	cout << 7 + rand() % ((24 - 7) + 1) << "\n";
	cout << 1 + rand() % ((100 - 1) + 1) << "\n";

	int coin = 1 + rand() % 2; 

	system("pause");
	return 0;
}