#ifndef PERSON_H
#define PERSON_H

#include <string>

/*
 * A person with a name and a phone number.
 */
using std::string;
using std::ostream;
class Person {
public:
	Person(const string& n, const string& p) :
	name(n), phone(p) {}
	string get_name() const { return name; }
	string get_phone() const { return phone; }
	bool operator<(const Person& p2) const {
		return get_name() < p2.get_name() ||
			(get_name() == p2.get_name() && get_phone() < p2.get_phone());
	}
private:
	string name;
	string phone;
};

ostream& operator<<(ostream& os, const Person& p);

#endif
