#include "stdafx.h"
#include "bitbuffer.h"
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	
	unsigned char test = 10;
	unsigned char test2 = 24;
	unsigned char test3, test4;


	bitset<8> a(test);
	bitset<8> b(test2);
	cout << "A:  " << a << endl;
	cout << "B:  " << b << endl;
	cout << "&:  " << (a & b) << endl;
	cout << "^:  " << (a ^ b) << endl;
	cout << "|:  " << (a | b) << endl;
	
	test3 = (test << 1);
	bitset<8> c(test3);
	cout << "<<: " << c << endl;

	test4 = (test2 >> 1);
	bitset<8> d(test4);
	cout << ">>: " << d << endl;

	
	
	
	
	
	
	
	//BitBuffer buf(cout);
	//int n;
	//while (cin >> n) {
	//	buf.put(n != 0);
	//}
	//cout << endl;
}
