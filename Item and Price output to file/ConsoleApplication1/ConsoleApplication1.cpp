
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string item1, item2, item3, item4, item5;
	float price1, price2, price3, price4, price5;
	int quantity1, quantity2, quantity3, quantity4, quantity5;
	//Enter Items and there prices
	cout << "Please enter 5 items you would like to sell\n ";
	cout << "Item 1\n" ;
	cin >> item1;
	cout << "Enter the price of item 1\n";
	cin >> price1;
	cout << "how many items do you want?";
	cin >> quantity1; 
	cout << "Item 2\n" ;
	cin >> item2;
	cout << "Enter the price of item 2\n";
	cin >> price2;
	cout << "how many items do you want?";
	cin >> quantity2;
	cout << "Item 3\n" ; 
	cin >> item3;
	cout << "Enter the price of item 3\n";
	cin >> price3;
	cout << "how many items do you want?";
	cin >> quantity3;
	cout << "Item 4\n" ;
	cin >> item4;
	cout << "Enter the price of item 4\n";
	cin >> price4;
	cout << "how many items do you want?";
	cin >> quantity4;
	cout << "Item 5\n ";
	cin >> item5;
	cout << "Enter the price of item 5\n";
	cin >> price5;
	cout << "how many items do you want?";
	cin >> quantity5;

	
	item1 = item1 + "\n";
	item2 = item2 + "\n";
	item3 = item3 + "\n";
	item4 = item4 + "\n";
	item5 = item5 + "\n";
 
	ofstream outfile;
	
	//Opens the file
	outfile.open("C:\\Temp\\Item.txt");
	outfile << item1;
	outfile << item2;
	outfile << item3;
	outfile << item4;
	outfile << item5;
	
	//Closes the file 
	outfile.close();

	


	//Prices
	ofstream priceOut;
	priceOut.open("C://Temp//Price.txt");
	priceOut << price1 << endl;
	priceOut << price2 << endl;
	priceOut << price3 << endl;
	priceOut << price4 << endl;
	priceOut << price5 << endl;
	priceOut.close();
	
	ofstream quantityOut;
	quantityOut.open("C://Temp//Quantity.txt");
	quantityOut << quantity1 << endl;
	quantityOut << quantity2 << endl;
	quantityOut << quantity3 << endl;
	quantityOut << quantity4 << endl;
	quantityOut << quantity5 << endl;
	quantityOut.close();


	return 0;
}

