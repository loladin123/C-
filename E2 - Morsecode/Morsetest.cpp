
#include "stdafx.h"
#include "morsecode.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
int main() {


	MorseCode mc;
	string text = "a man";
	cout << mc.encode(text) << endl;
	string code = ".... . .-.. .-.. --- .-- --- .-. .-.. -..";
	cout << mc.decode(code) << endl;


}

