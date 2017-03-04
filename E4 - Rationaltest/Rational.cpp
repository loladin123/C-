#include "stdafx.h"
#include "Rational.h"

/* Private gcd function */
int Rational::gcd(int n, int d) {
	return d == 0 ? n : gcd(d, n % d);
}
/* Private function that finds gcd and makes de nom/denom small as possible */
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

Rational &Rational::operator+=(const Rational &other){
	return *this = *this + other;
}
/* No '&' here because if a = b + c, we don't want to change b we only want to copy it */
Rational Rational::operator+(const Rational &other) {
	Rational rat;
	rat.nominator = this->nominator;
	rat.denominator = this->denominator;
	rat.nominator = (rat.nominator * other.denominator) + (other.nominator * rat.denominator);
	rat.denominator = rat.denominator * other.denominator;
	fix(rat.nominator, rat.denominator);
	return rat;
}

Rational::~Rational()
{
}

