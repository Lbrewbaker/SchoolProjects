/******************************
Author: Luke Brewbaker
Date: 11/26/14
Modified: 11/26/14
File: geom.cpp

Overview:


Input:


Output:

*******************************/
#include <iostream>
 #include <string>
 #include <cmath>
 using namespace std;

class Point
{

private:
	double xCoord;
	double yCoord;

public:
	Point()
	{
		xCoord = 0;
		yCoord = 0;
	}


Point(double x, double y)
	{
		xCoord = x;
		yCoord = y;
	}


	double getX()
	{
		return xCoord;
	}
double getY()
	{
		return yCoord;
	}

double distanceTo(double p2)
	{
		double a, b, c, d;
		a = xCoord - getX();
		b = yCoord - getY();
		c = pow(a, 2) + pow(b, 2);
		d = sqrt(c);
		return d;
	}


};

 int main()
 {
	double x1, y1, x2, y2;

	Point pointone(x1, y1);
	Point pointtwo(x2, y2);

	cout << "Enter the coordinates for point 1." << endl;

	cout << "Point 1 x: ";
	cin >> x1;

	cout << "Point 1 y: ";
	cin >> y1;

	cout << "Enter the coordinates for point 2." << endl;
	cout << "Point 2 x: ";
	cin >> x2;

	cout << "Point 2 y: ";
	cin >> y2;

	cout << "The distance between your two points is: ";
	cout << pointone.distanceTo(pointtwo) << endl;

	return 0;
}
