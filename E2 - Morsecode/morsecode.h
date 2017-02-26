/*
 * MorseCode: translates letters a-z to/from Morse code. The code
 * definitions are in the file morse.def.
 */
#ifndef MORSECODE_H
#define MORSECODE_H
#include "stdafx.h"
#include <string>
#include <vector>

class MorseCode {
public:
	MorseCode();
	std::string encode(const std::string& text) const;
	std::string decode(const std::string& code) const;
private:
	std::vector<char> alpha{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	std::vector<std::string> morse{
		".-",
		"-...",
		"-.-.",
		"-..",
		".",
		"..-.",
		"--",
		"....",
		"..",
		".---",
		"-.-",
		".-..",
		"--",
		"-.",
		"---",
		".--.",
		"--.-",
		".-.",
		"...",
		"-",
		"..-",
		"...-",
		".--",
		"-.. -",
		"-.--",
		"--.."};

};

#endif
