#include "stdafx.h"
#include "Rational.h"


int Rational::gcd(int n, int d) {
	return d == 0 ? n : gcd(d, n % d);
}

Rational::~Rational()
{
}
