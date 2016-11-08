#pragma once

using namespace std;

// class header as outlined in listing 10.9
class Circle
{
	double radius;
	static int numberOfObjects;
public:
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();
	bool operator<(Circle);
	bool operator<=(Circle);
	bool operator==(Circle); 
	bool operator!=(Circle); 
	bool operator>=(Circle); 
	bool operator>(Circle);
};