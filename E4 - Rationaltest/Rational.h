#pragma once
#include <ostream>
using std::ostream;
class Rational
{
public:
	Rational(int n = 0, int d = 1) : nominator(n), denominator(d) {};
	friend ostream& operator<<(ostream &os, Rational& r);
	~Rational();
private:
	/* making a remote change*/
	int nominator, denominator;
	int gcd(int n, int d);
};

inline ostream& operator<<(ostream &os, Rational &r) {
	int gcd = r.gcd(r.nominator, r.denominator);
	if (r.denominator == 1)
		return os << r.nominator;
	if (gcd == 1)
		return os << r.nominator << '/' << r.denominator;
	else
		return os << (r.nominator / gcd) << '/' << (r.denominator / gcd);
}

