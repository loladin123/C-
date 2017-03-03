#pragma once
#include <ostream>
using std::ostream;
class Rational
{
public:
	Rational(int n = 0, int d = 1) : nominator(n), denominator(d) {};
	Rational(const Rational& other) : nominator(other.nominator), denominator(other.denominator) {};
	friend ostream& operator<<(ostream &os, Rational& r);
	Rational& operator=(const int a);
	Rational& operator+=(const Rational &other);
	Rational operator+(const Rational &other);
	~Rational();
	int getN() { return nominator;  }
	int getD() { return denominator; }
	void fix(int &n, int &d);
	int gcd(int n, int d);
private:

	int nominator, denominator;
	
};
/* the reason we don't define ostream operator is because it "comes from a different library"
and it causes some weird shit */
inline ostream& operator<<(ostream &os, Rational &r) {

}

