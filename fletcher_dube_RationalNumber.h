#include <iostream>
using namespace std;

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber
{
	int numerator;
	int denominator;
public:
	RationalNumber(int, int);
	RationalNumber() {};	//	default constructor w/ no params
	~RationalNumber() {};

	void printRational() const;

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	void setNumerator(int a) { numerator = a; }
	void setDenominator(int a) { denominator = a; }

	RationalNumber operator+(const RationalNumber&);
	RationalNumber operator-(const RationalNumber&);
	RationalNumber operator*(const RationalNumber&);
	RationalNumber operator/(const RationalNumber&);
	RationalNumber& operator=(const RationalNumber&);

	bool operator<(const RationalNumber&);
	bool operator>(const RationalNumber&);
	bool operator<=(const RationalNumber&);
	bool operator>=(const RationalNumber&);
	bool operator==(const RationalNumber&);
	bool operator!=(const RationalNumber&);

	friend int gcd(int, int);	//	greatest common denominator function for simplification
};

#endif