#include "stdafx.h"
#include "Rational.h"


int Rational::gcd(int n, int d) {
	return d == 0 ? n : gcd(d, n % d);
}

void Rational::fix(int &n, int &d) {
	int gcd1 = gcd(n, d);
	if (gcd1 != 1)
		n = (n / gcd1), d = (d / gcd1);


}

Rational& Rational::operator=(const int a) {
	nominator = a;
	fix(nominator, denominator);
	return *this;
}

//Rational &Rational::operator+=(const Rational &other){
//	
//}

Rational Rational::operator+(const Rational &other) {
	Rational rat;
	if (rat.denominator == other.denominator) {
		rat.nominator = this->nominator + other.nominator;
		fix(rat.nominator, rat.denominator);
		return rat;
	}
	if (rat.denominator == 1) {
		rat.nominator = (this->nominator * other.denominator) + other.nominator;
		fix(rat.nominator, rat.denominator);
		return rat;
	}
	if (other.denominator == 1) {
		rat.nominator = (this->denominator * other.nominator) + this->nominator;
		fix(rat.nominator, rat.denominator);
		return rat;
	}
	if ((rat.denominator != other.denominator)) {
		int newnominator = (this->nominator * other.denominator) + (other.nominator * this->denominator);
		int newdenominator = this->denominator * other.denominator;
		rat.nominator = newnominator;
		rat.denominator = newdenominator;
		fix(rat.nominator, rat.denominator);
		return rat;
	}
}

Rational::~Rational()
{
}

