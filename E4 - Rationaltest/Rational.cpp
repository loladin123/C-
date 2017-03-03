#include "stdafx.h"
#include "Rational.h"


int Rational::gcd(int n, int d) {
	return d == 0 ? n : gcd(d, n % d);
}

void Rational::fix(int &n, int &d) {
	int gcd1 = gcd(n, d);
	if (d == 1)
		n = n / 1;
	if (gcd1 != 1)
		n = (n / gcd1), d = (d / gcd1);

}

Rational& Rational::operator=(const int a) {
	nominator = a;
	return *this;
}

Rational &Rational::operator+=(const Rational &other){
	if (denominator == other.denominator) {
		nominator = nominator + other.nominator;
		return *this;
	}
	//if (denominator == 1) {
	//	nominator = (nominator * other.denominator) + other.nominator;
	//	return *this;
	//}
	//if (other.denominator == 1) {
	//	nominator = (denominator * other.nominator) + nominator;
	//	return *this;
	//}
	if ((denominator != other.denominator)) {
		int newnominator = (nominator * other.denominator) + (other.nominator * denominator);
		int newdenominator = denominator * other.denominator;
		nominator = newnominator;
		denominator = newdenominator;
		return *this;
	}	
}

Rational Rational::operator+(const Rational &other) {
	Rational rat;
	if (rat.denominator == other.denominator) {
		rat.nominator = this->nominator + other.nominator;
		return rat;
	}
	if (rat.denominator == 1) {
		rat.nominator = (this->nominator * other.denominator) + other.nominator;
		return rat;
	}
	if (other.denominator == 1) {
		rat.nominator = (this->denominator * other.nominator) + this->nominator;
		return rat;
	}
	if ((rat.denominator != other.denominator)) {
		int newnominator = (this->nominator * other.denominator) + (other.nominator * this->denominator);
		int newdenominator = this->denominator * other.denominator;
		rat.nominator = newnominator;
		rat.denominator = newdenominator;
		return rat;
	}
}

Rational::~Rational()
{
}

