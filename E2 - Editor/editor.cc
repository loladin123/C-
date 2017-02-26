#include "stdafx.h"
#include "editor.h"
#include <string>
#include <vector>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	vector<int> pos_left_brackets;
	vector<int> pos_right_brackets;

	for (int i = 0; i < text.size(); i++) {
		switch (text.at(i)) {
		case '(' :
			pos_left_brackets.push_back(i);
			break;
		case ')' :
			pos_right_brackets.push_back(i);
			break;
		}
	}









	return 3;
}
