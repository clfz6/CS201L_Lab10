// Cristian Lopez
// 7-16-2020
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int numer, int denom)
{
	numerator = numer;
	denominator = denom;
}

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

istream& operator>> (istream& in, Fraction& fract)
{
	char slash;
	in >> fract.numerator >> slash >> fract.denominator;

	return in;
}

ostream& operator<< (ostream& out, const Fraction& fract)
{
	char slash = '/';
	out << fract.numerator << slash << fract.denominator;

	return out;
}

const Fraction Fraction::operator+(const Fraction rhs)
{
	Fraction add((numerator * rhs.denominator + rhs.numerator * denominator)
		, (denominator * rhs.denominator));
	add.reduce();
	
	return add;
}
const Fraction Fraction::operator-(const Fraction rhs)
{
	Fraction subract((numerator * rhs.denominator - rhs.numerator * denominator)
		, (denominator * rhs.denominator));
	subract.reduce();

	return subract;
}
const Fraction Fraction::operator*(const Fraction rhs)
{
	Fraction multiply((numerator * rhs.numerator)
		, (denominator * rhs.denominator));
	multiply.reduce();

	return multiply;
}
const Fraction Fraction::operator/(const Fraction rhs)
{
	Fraction divide((numerator * rhs.denominator)
		, (denominator * rhs.numerator));
	divide.reduce();

	return divide;
}
bool Fraction::operator==(const Fraction& rhs)
{
	bool equal;
	Fraction compare = rhs;
	compare.reduce();
	reduce();
	if (numerator == rhs.numerator && denominator == rhs.denominator)
	{
		equal = true;
	}
	else
	{
		equal = false;
	}

	return equal;
}

/*
General pattern for overloaded operators:
   1. Declare new object as local variable
   2. Assign values as needed--in this case, to numerator & denominator
   3. return new object
Note that for most operators, the return type is a const object or const reference to object.
That's so this:

A + B = C;

isn't legal, but

C = A + B;

is.
*/
