#include "stdafx.h"
#include "editor.h"
#include <string>
#include <vector>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {

	vector<int> leftB;
	vector<int> rightB;
	vector<int> newb;
	int index = -1;

	/* Collect all brackets and put them in their respective container*/
	for (int i = 0; i < text.size(); i++) {
		switch (text.at(i)) {
		case '(':
			leftB.push_back(i);
			break;
		case ')':
			rightB.push_back(i);
			break;
		case '[':
			leftB.push_back(i);
			break;
		case ']':
			rightB.push_back(i);
			break;
		case '{':
			leftB.push_back(i);
			break;
		case '}':
			rightB.push_back(i);
			break;
		}
	}

	/* Reverse the right bracket container into a new one */
	for (int i = rightB.size() - 1; i >= 0; i--) {
		newb.push_back(rightB.at(i));
	}

	/* Assigns the index to index*/
	for (int i = 0; i < newb.size(); i++)
			if (newb.at(i) == pos)
				index = i;
	/* If index is -1 aka unchanged return npos*/
	if (index == -1)
		return string::npos;

	/* If index is 0, wrap it around to the beginning else decrement*/
	if (index == 0)
		index = newb.size() - 1;
	else
		index--;

	return leftB.at(index);



}
