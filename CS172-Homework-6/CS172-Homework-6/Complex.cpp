#include"Complex.h"
#include<iomanip>

// constructs a complex number to 0+0i
Complex::Complex()
{
	real = 0;
	imaginary = 0;
}
// constructs a complex number with real part a and complex part 0
Complex::Complex(double a)
{
	real = a;
	imaginary = 0;
}
// constructs a complex number with the specified real and complex parts
Complex::Complex(double a, double b)
{
	real = a;
	imaginary = b;
}
// function for adding complex numbers
Complex Complex::add(Complex c)
{
	// create a double to hold the new real part, and set it to the value which is dictated by the complex addition formulas, and retrieves the second real value through the getRealPart function
	double a = real + c.getRealPart();
	// do the same for the new imaginary part
	double b = imaginary + c.getImaginaryPart();
	// create and return a complex number with the new parameters
	return Complex(a, b);
}
// function for subtracting complex numbers, acts the same as the addition function, but sets the values based on the subtraction formula
Complex Complex::subtract(Complex c)
{
	double a = real - c.getRealPart();
	double b = imaginary - c.getImaginaryPart();
	return Complex(a, b);
}
// function for multiplying complex numbers, acts the same as the addition function, but sets the values based on the multiplication formula
Complex Complex::multiply(Complex c)
{
	double a = real * c.getRealPart() - imaginary*c.getImaginaryPart();
	double b = imaginary * c.getRealPart() + real * c.getImaginaryPart();
	return Complex(a, b);
}
// function for dividing complex numbers. Works the same as the addition function, but uses four new variables to ease the typing inside the function
Complex Complex::divide(Complex n)
{
	double a = real, b = imaginary, c = n.getRealPart(), d = n.getImaginaryPart();
	double r = (a*c + b*d) / (c*c + d*d);
	double i = (b*c - a*d) / (c*c + d*d);
	return Complex(r, i);
}
// returns the absolute value of a complex number
double Complex::abs()
{
	// returns the square root of the components squared and added (from formula)
	return sqrt(real*real + imaginary*imaginary);
}
// turns the contents of a complex number into strings for output
string Complex::toString()
{
	// creates a string and begins with the open parantheses
	string value = "(";
	// appends the vale of the real part as a string
	value += to_string(real);
	// appends the plus sign
	value += " + ";
	// appends the string of the imaginary part
	value += to_string(imaginary);
	// appends the i and closed parentheses
	value += "i)";
	// returns this final string
	return value;
}
// returns the real component 
double Complex::getRealPart()
{
	return real;
}
// returns the imaginary component
double Complex::getImaginaryPart()
{
	return imaginary;
}
// overloaded += operator
void Complex::operator+=(Complex c)
{
	// sets the real part to that which it was before plus the real component of the argument
	real += c.getRealPart();
	// does the same for the imaginary part
	imaginary += c.getImaginaryPart();
}
// overloaded -= operator for complex numbers
void Complex::operator-=(Complex c)
{
	// sets real to that which it was before minus the real component of the argument
	real -= c.getRealPart();
	// does the same for the imaginary part
	imaginary -= c.getImaginaryPart();
}
// overloaded *= operator for complex numbers
void Complex::operator*=(Complex c)
{
	// assigns the new real number value according to the formulas
	real = real * c.getRealPart() - imaginary*c.getImaginaryPart();
	// same for imaginary
	imaginary = imaginary * c.getRealPart() + real * c.getImaginaryPart();
}
// overloaded /= operator for complex numbers
void Complex::operator/=(Complex n)
{
	// uses four new variables again to ease visuals
	double a = real, b = imaginary, c = n.getRealPart(), d = n.getImaginaryPart();
	// assigns real the new value based on formulas
	real = (a*c + b*d) / (c*c + d*d);
	// same for imaginary
	imaginary = (b*c - a*d) / (c*c + d*d);
}
// overloaded [] operator for complex class
double Complex::operator[](int i)
{
	// if they ask for complex[0], return the real part
	if (i == 0)
		return real;
	// if they ask for complex[1], return the imaginary part
	if (i == 1)
		return imaginary;
	// otherwise, they have input incorrctly
	else cout << "Invalid index value." << endl; return 0;
}

// overloaded math operators simply return the addition of the two complex numbers using the this-> pointer and the add(), subtract() etc functions
Complex Complex::operator+(Complex c)
{
	return this->add(c);
}
Complex Complex::operator-(Complex c)
{
	return this->subtract(c);
}
Complex Complex::operator*(Complex c)
{
	return this->multiply(c);
}
Complex Complex::operator/(Complex c)
{
	return this->divide(c);
}
