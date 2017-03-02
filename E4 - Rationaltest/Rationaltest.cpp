// E4 - Rationaltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "rational.h"
#include <iostream>
using namespace std;

int main()
{
	Rational a(50, 75); // numerator / denominator
	Rational b(3);      // numerator / 1
	Rational c;         // 0 / 1

	cout << a << "\t(2/3)" << endl;
	cout << b << "\t(3)" << endl;
	cout << c << "\t(0)" << endl;

	c = 1;
	b += c;
	c = a + b;
	cout << a << "\t" << a.getN() << "\t" << a.getD() << "\t" << "A" << endl;
	cout << b << "\t" << b.getN() << "\t" << b.getD() << "\t" << "B" << endl;
	cout << c << "\t" << c.getN() << "\t" << c.getD() << "\t" << "C" << endl;

	/*cout << a + b + c << "\t(28/3)" << endl;
	cout << a + b + c + 1 << "\t(31/3)" << endl;*/

}
