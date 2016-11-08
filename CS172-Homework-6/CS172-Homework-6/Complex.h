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
	Complex operator+=(Complex);
	Complex operator-=(Complex);
	Complex operator*=(Complex);
	Complex operator/=(Complex);
	double operator[](Complex);
	friend ostream& operator << (ostream&, Complex);
	friend ostream& operator >> (ostream&, Complex);
	Complex operator++(int);
	Complex operator--(int);
};

Complex operator+(Complex);
Complex operator-(Complex);
Complex operator*(Complex);
Complex operator/(Complex);