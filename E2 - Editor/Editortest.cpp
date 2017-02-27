#include "stdafx.h"
#include "editor.h"
#include <iostream>
#include <vector>leftB

using namespace std;


int main() {






	Editor ed("...(...(...[...]...)...)...{...}...");
	cout << "Left bracket of right bracket on pos 15 is on pos: " << ed.find_left_par(15) << "\t(11)" << endl;
	cout << "Left bracket of right bracket on pos 19 is on pos: " << ed.find_left_par(19) << "\t(7)" << endl;
	cout << "Left bracket of right bracket on pos 23 is on pos: " << ed.find_left_par(23) << "\t(3)" << endl;
	cout << "Left bracket of right bracket on pos 31 is on pos: " << ed.find_left_par(31) << "\t(27)" << endl;
	cout << ed.find_left_par(32) << "\t(18446744073709551615)" << endl;









}
