
/*
* Explain the output of the following program.
*/
#include "stdafx.h"
#include "point.h"
#include <iostream>

using namespace std;

int main() {

	Point p(1, 2);

	cout << "sizeof(p)      = " << sizeof(p) << endl; // Will be 16, the member variables are 8 bytes each


	Point* pp = new Point(1, 2);
	cout << "sizeof(pp)     = " << sizeof(pp) << endl; // sizeof the pointer is 8
	cout << "sizeof(*pp)    = " << sizeof(*pp) << endl; // sizeof the object being pointed to is 16, just like the first one

	delete pp;
}
