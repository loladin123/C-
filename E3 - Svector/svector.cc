/*
 * Class SVector: implementation.
 */
#include "stdafx.h"
#include "svector.h"

SVector::SVector(size_t size) : n(size), v(new int[n]) {}

SVector::~SVector() {
	delete[] v;
}

/* Added and implemented a copy constructor explicitly*/
SVector::SVector(const SVector& sv) : n(sv.n), v(new int[sv.n]) {
	for (size_t i = 0; i != n; ++i) {
		v[i] = sv.v[i];
	}
}
/* Creating an explicit assignment operator is useful if we create a copy constructor */
SVector& SVector::operator=(const SVector& rhs) {
	if (this == &rhs)
		return *this;
	
	delete[] v;
	n = rhs.n;
	v = new int[n];
	for (size_t i = 0; i != n; ++i) {
		v[i] = rhs.v[i];
	}
	return *this;
}
size_t SVector::size() const {
	return n;
}

int SVector::get(size_t i) const {
	return v[i];
}

void SVector::set(size_t i, int value) {
	v[i] = value;
}

/*
* Class SVector: implementation.
*/

