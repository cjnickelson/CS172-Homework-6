#include"Complex.h"
#include<iomanip>

Complex::Complex()
{
	real = 0;
	imaginary = 0;
}
Complex::Complex(double a)
{
	real = a;
	imaginary = 0;
}
Complex::Complex(double a, double b)
{
	real = a;
	imaginary = b;
}
Complex Complex::add(Complex c)
{
	double a = real + c.getRealPart();
	double b = imaginary + c.getImaginaryPart();
	return Complex(a, b);
}
Complex Complex::subtract(Complex c)
{
	double a = real - c.getRealPart();
	double b = imaginary - c.getImaginaryPart();
	return Complex(a, b);
}
Complex Complex::multiply(Complex c)
{
	double a = real * c.getRealPart() - imaginary*c.getImaginaryPart();
	double b = imaginary * c.getRealPart() + real * c.getImaginaryPart();
	return Complex(a, b);
}
Complex Complex::divide(Complex n)
{
	double a = real, b = imaginary, c = n.getRealPart(), d = n.getImaginaryPart();
	double r = (a*c + b*d) / (c*c + d*d);
	double i = (b*c - a*d) / (c*c + d*d);
	return Complex(r, i);
}
double Complex::abs()
{
	return sqrt(real*real + imaginary*imaginary);
}
string Complex::toString()
{
	string value = "(";
	value += to_string(real);
	value += " + ";
	value += to_string(imaginary);
	value += "i)";
	return value;
}
double Complex::getRealPart()
{
	return real;
}
double Complex::getImaginaryPart()
{
	return imaginary;
}
void Complex::operator+=(Complex c)
{
	real += c.getRealPart();
	imaginary += c.getImaginaryPart();
}
void Complex::operator-=(Complex c)
{
	real -= c.getRealPart();
	imaginary -= c.getImaginaryPart();
}
void Complex::operator*=(Complex c)
{
	real = real * c.getRealPart() - imaginary*c.getImaginaryPart();
	imaginary = imaginary * c.getRealPart() + real * c.getImaginaryPart();
}
void Complex::operator/=(Complex n)
{
	double a = real, b = imaginary, c = n.getRealPart(), d = n.getImaginaryPart();
	real = (a*c + b*d) / (c*c + d*d);
	imaginary = (b*c - a*d) / (c*c + d*d);
}
double Complex::operator[](int i)
{
	if (i == 0)
		return real;
	if (i == 1)
		return imaginary;
	else cout << "Invalid index value." << endl; return 0;
}

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
