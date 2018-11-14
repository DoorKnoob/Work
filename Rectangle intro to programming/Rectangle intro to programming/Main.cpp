#include <iostream>
using namespace std;

class Rectangle
{
private:
	double length;
	double width;
public:

	Rectangle()
	{
		width = 1;
		length = 1;
	}

	Rectangle(double len, double wid)
	{
		width = len;
		length = wid; 
	}



	void setLength(double len)
	{
		length = len;
	}

	void setWidth(double wid)
	{
		width = wid;
	}

	double getLength()
	{
		return length;
	}

	double getWidth()
	{
		return width;
	}

	double getArea()
	{
		return length * width;
	}

	double getPerimeter()
	{
		return  2 * (length + width);
	}

	 
};

int main()
{
	Rectangle r1; 
	Rectangle r2(5,8); 
	double length;
	double width;

	cout << "the size of the rectangle is " << r1.getArea() << endl;
	cout << "the size of the rectangle is " << r1.getPerimeter() << endl;

	cout << "the size of the rectangle is " << r2.getArea() << endl;
	cout << "the size of the rectangle is " << r2.getPerimeter() << endl;

	system("pause");
	return 0;
}

