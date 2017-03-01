#include "stdafx.h"
#include "crypto.h"
#include <string>
#include <random>

using namespace std;
/* Char is auto-wrapped if > 255 or < 0, so no need for extra checks */
std::string Crypto::encrypt(const string& text, unsigned int key) {
	string encrypted = text;
	int random = 0;
	for (int i = 0; i < encrypted.size(); i++)
			encrypted.at(i) += key;

	return encrypted;
}

std::string Crypto::decrypt(const string& crypt, unsigned int key) {
	string decrypted = crypt;
	for (int i = 0; i < decrypted.size(); i++)
			decrypted.at(i) -= key;

	return decrypted;

}

