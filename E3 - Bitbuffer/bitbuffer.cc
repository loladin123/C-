#include "stdafx.h"
#include "bitbuffer.h"
#include <iostream>
#include <cassert>
#include <bitset>

BitBuffer::BitBuffer(std::ostream& out) : os(out), n_bits(0) { }

void BitBuffer::put(bool b) {
	
	/* Pushes bitwise to the left <-- to "make room" for new bits. os.put converts to char
	and outputs. */
	byte = (byte << 1) | b;
	if (n_bits == 7)
	os.put(byte), n_bits = 0;
	else
		n_bits++;
}
