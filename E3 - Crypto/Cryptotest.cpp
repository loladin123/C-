// E3 - Crypto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "crypto.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "Key:       ";
	unsigned key;
	cin >> key;
	cin.ignore();
	cout << "Text:      ";
	string s;
	getline(cin, s);
	string t = Crypto::encrypt(s, key);
	cout << "Encrypted: " << t << endl;
	cout << "Decrypted: " << Crypto::decrypt(t, key) << endl;
}
