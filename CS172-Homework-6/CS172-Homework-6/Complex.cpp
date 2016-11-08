#include"Complex.h"

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
	return string(real << " + " << imaginary << "i");
}
double Complex::getRealPart()
{
	return real;
}
double Complex::getImaginaryPart()
{
	return imaginary;
}
Complex Complex::operator+=(Complex c)
{

}
Complex Complex::operator-=(Complex c)
{

}
Complex Complex::operator*=(Complex c)
{

}
Complex Complex::operator/=(Complex c)
{

}
double Complex::operator[](Complex c)
{

}
ostream& Complex::operator<<(ostream&, Complex c)
{

}
ostream& Complex::operator >> (ostream&, Complex c)
{

}
Complex Complex::operator++(int r)
{

}
Complex Complex::operator--(int r)
{

}