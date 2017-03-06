#include "stdafx.h"
#include "person.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric> 
#include <iterator>

using namespace std;

/*
* Collect some persons in a phone book (a vector), sort
* the phone book, print it.
*/

/*
* The error messages said it all:
* error: no match for `Person& < Person&' operator
* sort() needs to compare elements to be able to sort them.
* We can implement this operator or supply the sorting
* criterion (as a lambda) to the sort() call.
*/



int main() {

	//[capture list] (parameter list) return type { function body }
	

	


	vector<Person> phonebook;
	phonebook.push_back(Person("Petra", "046-12 13 14"));
	phonebook.push_back(Person("Anders", "040-96 97 98"));
	phonebook.push_back(Person("Bosse", "046-15 16 17"));
	phonebook.push_back(Person("Anna", "040-96 97 98"));
	phonebook.push_back(Person("Anders", "046-18 19 20"));

	cout << "Unsorted:" << endl;
	copy(phonebook.begin(), phonebook.end(),
		ostream_iterator<Person>(cout, "\n"));
	cout << endl;
	
	/* Sort does not function properly because it is not defined for objects of type Person 
       we need to overload the < operator */
	sort(phonebook.begin(), phonebook.end());

	cout << "Sorted:" << endl;
	copy(phonebook.begin(), phonebook.end(),
		ostream_iterator<Person>(cout, "\n"));
}
