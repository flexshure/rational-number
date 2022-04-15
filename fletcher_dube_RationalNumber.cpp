#include <iostream>
#include "fletcher_dube_RationalNumber.h"

using namespace std;


int gcd(int a, int b)		//	calculate greatest common divisor for simplification
{							//	via euler's algorithm (recursive)
	if( b == 0)
		return a;
	return gcd(b, a % b);
}

void RationalNumber::printRational() const
{
	cout << numerator;
	if(denominator != 1)				//	if it's not a whole number, output the rest of the fraction
		cout << "/" << denominator;
}

RationalNumber::RationalNumber(int inNumerator , int inDenominator)
{
	if(inNumerator == 0)			//	check for special cases: if the numerator is 0, the value of the fraction will be 0 regardless
	{
		numerator = 0;
		denominator = 1;	
	} else if(inDenominator == 0)	//	div/0 error
	{
		denominator = 1;	//	set to garbage values and cout error msg
		numerator = 1;
		cout << "ERROR: 0 denominator!\n";
	} else
	{
		int inGcd = gcd(inNumerator, inDenominator);	//	to ensure the fraction is simplified, calculate the GCD of the two terms

		denominator = inDenominator/inGcd;				//	then divide each term by the GCD and set each respective member accordingly
		numerator = inNumerator/inGcd;
	}

	if(denominator < 0)		//	finally, if the denominator is less than 0 (negative), make the numerator negative and the denominator positive.
	{
		denominator *= -1;
		numerator *= -1;
	}
	
}


RationalNumber& RationalNumber::operator=(const RationalNumber& other)
{
	denominator = other.getDenominator();
	numerator = other.getNumerator();
	return *this;
}

RationalNumber RationalNumber::operator+(const RationalNumber& other)
{
	int thisNum = this->getNumerator() * other.getDenominator();	//	common denominator is the product of each denominator. Thus, the new numerator should be calculated by multiplying with opposite denominator.
	int thatNum = other.getNumerator() * this->getDenominator();

	RationalNumber sum(thisNum + thatNum, other.getDenominator() * this->getDenominator());

	return sum;
}

RationalNumber RationalNumber::operator-(const RationalNumber& other)
{
	int thisNum = this->getNumerator() * other.getDenominator();	//	see addition operator
	int thatNum = other.getNumerator() * this->getDenominator();

	RationalNumber difference(thisNum - thatNum, other.getDenominator() * this->getDenominator());

	return difference;
}

RationalNumber RationalNumber::operator*(const RationalNumber& other)
{
	int inNumerator = other.getNumerator() * this->getNumerator();
	int inDenominator = other.getDenominator() * this->getDenominator();

	RationalNumber product(inNumerator, inDenominator);

	return product;
}

RationalNumber RationalNumber::operator/(const RationalNumber& other)
{
	RationalNumber divisor(other.getDenominator(), other.getNumerator());
	RationalNumber quotient = *this * divisor;
	return quotient;
}

bool RationalNumber::operator<(const RationalNumber& other)
{
	if(*this == other)		//	if they're equal, this cannot be less than other
		return false;
	if(denominator == other.getDenominator())	//	if denominators are already alike, just compare the numerators
		return(this->getNumerator() < other.getNumerator());
	int thisNum = this->getNumerator() * other.getDenominator();	//	otherwise, convert the numerators to a like denominator, and then compare numerators
	int thatNum = other.getNumerator() * this->getDenominator();
	return thisNum < thatNum;
}

bool RationalNumber::operator>(const RationalNumber& other)
{
	if(*this == other)	//	if they're equal, this cannot be greater than other
		return false;
	return !(*this < other);	//	otherwise, just return the opposite of "less than"
}

bool RationalNumber::operator==(const RationalNumber& other)
{
	if(denominator == other.getDenominator())
		return(numerator == other.getNumerator());
	int thisNum = this->getNumerator() * other.getDenominator();
	int thatNum = other.getNumerator() * this->getDenominator();
	return thisNum == thatNum;
}

bool RationalNumber::operator<=(const RationalNumber& other)
{
	return (*this == other || *this < other);
}

bool RationalNumber::operator>=(const RationalNumber& other)
{
	return (*this == other || *this > other);
}

bool RationalNumber::operator!=(const RationalNumber& other)
{
	return !(*this == other);
}