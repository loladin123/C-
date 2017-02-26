#include "stdafx.h"
#include "morsecode.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

MorseCode::MorseCode() {
}

string MorseCode::encode(const string& text) const {
	string encoded = "";
	for (auto b : text) {
		b = towlower(b);
		for (int i = 0; i < alpha.size(); i++) {
			if (b == alpha.at(i)) {
				encoded += morse.at(i);
			}
		}
	}

	return encoded;
}

string MorseCode::decode(const string& code) const {
	istringstream ss(code);
	int size = code.size() / 4;
	vector<string> vals(size);
	string result = "";

	for (int i = 0; i < size; i++)
		ss >> vals.at(i);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < alpha.size(); j++)
			if (vals.at(i) == morse.at(j))
				result += alpha.at(j);

	return result;

	
}

