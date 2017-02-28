/* 
 * Class SVector: an integer vector class with basic functionality
 * (get and set operations).
 */

#ifndef SVECTOR_H
#define SVECTOR_H

#include <cstdlib>

class SVector {
public:
	explicit SVector(size_t size); // a vector with 'size' elements, it disallows implicit conversion
	SVector(const SVector& sv);
	~SVector();                // deallocate the vector
	SVector& operator=(const SVector& rhs);
	size_t size() const;           // number of elements
	int get(size_t i) const;       // number at index i
	void set(size_t i, int value); // change the number at index i
private:
	size_t n; // the size of the vector
	int* v;   // an array to hold the numbers
};

#endif
