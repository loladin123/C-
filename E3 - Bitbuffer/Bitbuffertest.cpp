#include "stdafx.h"
#include "bitbuffer.h"
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	
	/* Just some testing of bit-wise operators using bitset library to display them as
	binary instead of decimal */
	//unsigned char test = 1;
	//unsigned char test2 = 24;
	//unsigned char test3, test4;
	//
	//bitset<8> a(test);
	//bitset<8> b(test2);
	//cout << "A:  " << a << endl;
	//cout << "B:  " << b << endl;
	//cout << "&:  " << (a & b) << endl;
	//cout << "^:  " << (a ^ b) << endl;
	//cout << "|:  " << (a | b) << endl;
	//
	//test3 = (test << 1);
	//bitset<8> c(test3);
	//cout << "<<: " << c << endl;

	//test4 = (test2 >> 1);
	//bitset<8> d(test4);
	//cout << ">>: " << d << endl;

	//int k = 0;
	//bool b = true;
	//b = 12;
	//cout << b; 
	//

	/* Actual task. The cout argument is passed so that every object has its
	own output stream. n is converted to 1 for all ints > 0 and 0 for 0 */
	BitBuffer buf(cout);
	int n;
	while (cin >> n) {
		buf.put(n);
	}
	cout << endl;
}
