// E3 - Countobj.cpp : Defines the entry point for the console application.
//
/*
* countobj.cc: count creation and destruction of objects. One class and
* several functions, all in this file.
*/
#include "stdafx.h"
#include <iostream>
#include <string>

class Counted {
public:
	Counted();
	Counted(const Counted&);
	~Counted();
	static int getNbrObj();
private:
	static int nbrObj;
};

int Counted::nbrObj = 0;

Counted::Counted() {
	nbrObj++;
}

Counted::Counted(const Counted&) {
	nbrObj++;
}

Counted::~Counted() {
	nbrObj--;
}

int Counted::getNbrObj() {
	return nbrObj;
}

/* 2 objects are created */
void first() {
	Counted c;
	Counted* pc = new Counted;
	delete pc;
}

/* Two objects are created, c1 is copied into c2 (by the copy constructor which does not increment nbrObj because it is default) */
void second() {
	Counted c1;
	Counted c2 = c1;
}
/* Two objects are created */
void third() {
	Counted c1;
	Counted c2;
	c2 = c1;
}

using namespace std;

void print_nbr_objects(const string& msg) {
	cout << msg << " -- number of objects: "
		<< Counted::getNbrObj() << endl;
}

int main() {
	print_nbr_objects("Program start, before first()");
	
	first();
	print_nbr_objects("After first(), before second()    ");

	second();
	print_nbr_objects("After second(), before third()    ");

	third();
	print_nbr_objects("After third(), program end   ");
}

