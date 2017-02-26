/*
* A program to check what happens upon memory-related execution
* errors.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

/*
* Addressing outside allocated memory.
* Trying to index number 10 but only 0 - 9 exists
*/
void f1() {
	int* v = new int[10];
	v[10] = 1;
}

/*
* Accessing unitialized memory.
* Pointers must be initialized
*/
void f2() {
	//int* v;
	//v[0] = 1;
}

/*
* Dereferencing null pointer.
* aka trying to add a value to a uninted nullpointer
*/
void f3() {
	int* v = nullptr;
	*v = 1;
}

/*
* Deleting stack-allocated memory.
*	Only use delete for dynamically allocated memory aka when ' = new type ' is used
*
*/
void f4() {
	int i = 1;
	int* p = &i;
	*p = 1;
	delete p;
}

/*
* Double delete.
* never delete twice
*/
void f5() {
	int* v = new int[10];
	v[0] = 1;
	delete[] v;
	delete[] v;
}
int main() {
	cout << "Check memory-related execution errors." << endl;
	cout << "Function number: ";
	int nbr;
	cin >> nbr;
	switch (nbr) {
	case 1:
		cout << "Addressing outside allocated memory." << endl;
		f1();
		break;
	case 2:
		cout << "Accessing unitialized memory." << endl;
		f2();
		break;
	case 3:
		cout << "Dereferencing null pointer." << endl;
		f3();
		break;
	case 4:
		cout << "Deleting stack-allocated memory." << endl;
		f4();
		break;
	case 5:
		cout << "Double delete." << endl;
		f5();
		break;
	default:
		cout << "... no such function" << endl;
		break;
	}
}
