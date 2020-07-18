#pragma once
// Cristian Lopez
// 7-16-2020
// Lab 10

#include <iostream>
using namespace std;

class Fraction
{
	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.
	
private:
	int getGCD(int num1, int num2);
	int numerator, denominator;

public:
	Fraction();
	Fraction(int numer, int denom);
	void reduce();
	friend ostream& operator<< (ostream& out, const Fraction& fract);
	friend istream& operator>> (istream& in, Fraction& fract);

	const Fraction operator+(const Fraction rhs);
	const Fraction operator-(const Fraction rhs);
	const Fraction operator*(const Fraction rhs);
	const Fraction operator/(const Fraction rhs);
	bool operator==(const Fraction& rhs);
};

