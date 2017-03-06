#include "stdafx.h"
#include "person.h"
#include <iostream>

using std::ostream;

ostream& operator<<(ostream& os, const Person& p) {
	return os << p.get_name() << " " << p.get_phone();
}
