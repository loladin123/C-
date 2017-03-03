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
	int gcd = r.gcd(r.nominator, r.denominator);
	if (r.denominator == 1)
		return os << r.nominator/1;
	if (gcd == 1)
		return os << r.nominator << '/' << r.denominator;
	else {
		return os << (r.nominator / gcd) << '/' << (r.denominator / gcd);
	}
}

