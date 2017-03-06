#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include "textiterator.h"

using std::string;
using std::vector;


class Text {
public:
	using iterator = TextIterator;
	iterator begin() { return iterator(&lines, 0); }
	iterator end() { return iterator(&lines, lines.size()); }
	void addLine(const string& line) { lines.push_back(line); }

private:
	vector<string> lines;

	
};

#endif
