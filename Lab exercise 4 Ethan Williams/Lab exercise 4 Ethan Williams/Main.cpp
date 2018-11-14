#include <iostream>
#include "Car.h" 
using namespace std; 

int main()
{
	Car car; // Creating object with the default constructor
	Car sportsCar("lamborghini", 400000, "vrooooooooom!!!");
	sportsCar.SetOwned(true);
	cout << "You start the " << sportsCar.GetName() << " and it makes a ";
	sportsCar.Start();
	system("pause");
	return 0;


	








}