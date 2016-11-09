#pragma once
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

class Complex
{
	double real, imaginary;
public:
	Complex();
	Complex(double);
	Complex(double, double);
	Complex add(Complex);
	Complex subtract(Complex);
	Complex multiply(Complex);
	Complex divide(Complex);
	double abs();
	string toString();
	double getRealPart();
	double getImaginaryPart();
	void operator+=(Complex);
	void operator-=(Complex);
	void operator*=(Complex);
	void operator/=(Complex);
	double operator[](int);
	friend ostream& operator << (ostream& str, Complex c)
	{
		str << c.toString();
		return str;
	}
	Complex operator+(Complex);
	Complex operator-(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);
};