#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
ostream& operator<<(ostream& os, const vector<string>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		os << *it << " ";
	}
	return os;
}

bool reverseSort(string a, string b) {
	if (a > b)
		return true;
	else
		return false;
}

bool lengthSort(string a, string b) {
	if (a.size() < b.size())
		return true;
	else
		return false;
}




int main() {
	vector<string> v = { "Mary", "had", "a", "little", "lamb", "and", "some",
		"olives", "on", "the", "side" };

	 //print the words: Mary had a little lamb and some olives on the side
	cout << v << endl;

	// sort in alphabetical order: Mary a and had lamb little olives on side some the
	sort(v.begin(), v.end());
	cout << v << endl;

	// in reverse order: the some side on olives little lamb had and a Mary
	reverse(v.begin(), v.end());
	cout << v << endl;

	// by ascending length: a on the and had Mary lamb side some olives little
	sort(v.begin(), v.end(), lengthSort);
	cout << v << endl;

	// sort in alphabetical order again, print three-letter words: and had the
	for_each(v.begin(), v.end(),
		[](const string& s) { if (s.length() == 3) { cout << s << " "; }});
	cout << endl;

	// remove words with <= three letters: Mary lamb little olives side some
	auto it = remove_if(v.begin(), v.end(), [](const string& a) { return a.length() <= 3; });
	v.erase(it, v.end());
	cout << v << endl;
	
}