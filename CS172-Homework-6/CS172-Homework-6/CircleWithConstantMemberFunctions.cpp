#include"CircleWithConstantMemberFunctions.h"

using namespace std;

// class definition as shown in listing 10.10
Circle::Circle()
{
	radius = 1;
	numberOfObjects++;
}
Circle::Circle(double newRadius)
{
	radius = newRadius;
	numberOfObjects++;
}
double Circle::getArea() const
{
	return 3.1415926535*radius*radius;
}
double Circle::getRadius() const
{
	return radius;
}
void Circle::setRadius(double newRadius)
{
	radius = (newRadius >= 0 ? newRadius : -1 * newRadius);
}
int Circle::getNumberOfObjects()
{
	return numberOfObjects;
}

// overloading each of the relatinal operators to return true if their respective radii fulfill the relationship and false otherwise
bool Circle::operator<(Circle c1)
{
	return (radius < c1.getRadius() ? true : false);
}
bool Circle::operator<=(Circle c1)
{
	return (radius <= c1.getRadius() ? true : false);
}
bool Circle::operator==(Circle c1)
{
	return (radius == c1.getRadius() ? true : false);
}
bool Circle::operator!=(Circle c1)
{
	return (radius != c1.getRadius() ? true : false);
}
bool Circle::operator>=(Circle c1)
{
	return (radius >= c1.getRadius() ? true : false);
}
bool Circle::operator>(Circle c1)
{
	return (radius > c1.getRadius() ? true : false);
}