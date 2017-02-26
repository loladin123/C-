#include "stdafx.h"
#include "editor.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	

	vector<int> pos_left_brackets;
	vector<int> pos_right_brackets;

	string text = "...(...(...(...)...)...)...(...)...";


	for (int i = 0; i < text.size(); i++) {
		switch (text.at(i)) {
		case '(':
			pos_left_brackets.push_back(i);
			break;
		case ')':
			pos_left_brackets.push_back(i);
			break;
	/*	case '[':
			pos_left_brackets.push_back(i);
			break;
		case ']':
			pos_right_brackets.push_back(i);
			break;
		case '{':
			pos_left_brackets.push_back(i);
			break;
		case '}':
			pos_right_brackets.push_back(i);
			break;*/
		}
	}
	cout << "Left"<< endl;
	for (auto e : pos_left_brackets)
		cout << e << endl;

	cout << "Right" << endl;

	for (auto b : pos_right_brackets)
		cout << b << endl;


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Editor ed("...(...(...[...]...)...)...{...}...");
	//cout << ed.find_left_par(15) << "\t(11)" << endl;
	//cout << ed.find_left_par(19) << "\t(7)" << endl;
	//cout << ed.find_left_par(23) << "\t(3)" << endl;
	//cout << ed.find_left_par(31) << "\t(27)" << endl;
	//cout << ed.find_left_par(32) << "\t(18446744073709551615)" << endl;
}
