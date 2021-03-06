#ifndef TEXT_ITERATOR_H
#define TEXT_ITERATOR_H

#include <string>
#include <vector>

class TextIterator {
public:
	/* Creates a vector with string pointers, current_line is just lines.at(pos) */
	TextIterator(std::vector<std::string>* l, size_t cl): lines(l), current_line(cl), current_pos(0) {}
	
	/* Overloads the != operator compares two vector containers, compares if they are on the same line
	and compares if they are on the same position on that line */
	bool operator!=(const TextIterator& rhs) const {
		return lines != rhs.lines || current_line != rhs.current_line ||
		current_pos != rhs.current_pos;
	}
	

	char& operator*() const { return (*lines)[current_line][current_pos]; }
	
	TextIterator& operator++() {
		if (current_pos != (*lines)[current_line].size() - 1) {
			++current_pos;
		} else {
			current_pos = 0;
			++current_line;
		}
		return *this;
	}
private:
	std::vector<std::string>* lines;
	size_t current_line;
	std::string::size_type current_pos;
};

#endif
