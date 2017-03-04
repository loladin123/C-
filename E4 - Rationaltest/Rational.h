#pragma once
#include <ostream>
using std::ostream;
class Rational {
public:
	Rational(int n = 0, int d = 1) : nominator(n), denominator(d) { fix(nominator, denominator);  };
	friend ostream& operator<<(ostream &os, Rational& r);
	Rational& operator=(const int a);
	Rational& operator+=(const Rational &other);
	Rational operator+(const Rational &other);
	~Rational();
private:
	void fix(int &n, int &d);
	int gcd(int n, int d);
	int nominator, denominator;
	
};
/* the reason we don't define ostream operator is because it "comes from a different library"
and it causes some weird shit - I think */
inline ostream& operator<<(ostream &os, Rational &r) {
	if (r.denominator == 1)
		os << r.nominator;
	else
		os << r.nominator << '/' << r.denominator;
	return os;
}

