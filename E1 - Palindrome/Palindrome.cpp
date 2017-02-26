// Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string isPalindrome(string s) {
	int i = 0;
	int length = s.length() - 1;
	int counter = 0;
	string tf = "false";
	for (auto e : s) {
		if (e == s.at(length - i))
			counter++;
		i++;
	}

	if (counter == s.length())
		tf = "true";

	return tf;
}


int main()
{
	string s = "Anna";
	while (cin >> s)
		cout << "is palindrome: " << isPalindrome(s) << endl;

	return 0;
}

