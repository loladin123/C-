#include "stdafx.h"
#include <iostream>
#include "list.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

List::List() {
	first = NULL;
}

List::~List() {
	while (first != NULL) {
		Node * n = first->next;
		delete first;
		first = n;
	}
}

bool List::exists(int d) const {
	Node* firstCopy = first;
	while (firstCopy != NULL) {
		if (firstCopy->value == d)
			return true;
		firstCopy = firstCopy->next;
	}
	return false;
	delete firstCopy;
}



void List::print() const {
	Node* firstCopy = first;
	while (firstCopy != NULL) {
		cout << firstCopy->value << " ";
		firstCopy = firstCopy->next;
	}	
	delete firstCopy;
}

int List::size() const {
	return sz;
}

bool List::empty() const {
	return sz == 0;
}

void List::add(int d) {
	if (size() == 0)
		first = new Node(d, NULL);
	else {
		Node* newnode = first;
		first = new Node(d, newnode);
	}
	sz++;
}

void List::remove(int d, DeleteFlag df) {
	Node *previous = nullptr;
	Node *current = first;
	int firstVal;
	
	switch (df) {
	case List::DeleteFlag::LESS:
		/* Unsure of how to delete last node*/
		while (current != NULL) {
			firstVal = first->value;
			/* Why can I not use current here? */
			if (firstVal == d) {
				Node *tobedeleted = first;
				first = first->next;
				delete tobedeleted;
				sz--;
				break;
			}
			else {
				/* Why can I not use first here? */
				if (current->value < d) {
					previous->next = current->next;
					delete current;
					current = previous;
					sz--;
				}
				else {
					previous = current;
					if (current->next == NULL) {
						sz--;
						break;
					}
						current = current->next;
				}
			}
		}
		break;
	case List::DeleteFlag::EQUAL:
		if (exists(d)) {
			firstVal = first->value;
			while (current != NULL) {
				/* Why can I not use current here? */
				if (firstVal == d) {
					Node *tobedeleted = first;
					first = first->next;
					delete tobedeleted;
					sz--;
					break;
				}
				else {
					/* Why can I not use first here? */
					if (current->value != d) {
						previous = current;
						current = current->next;
					}
					else {
						previous->next = current->next;
						delete current;
						current = previous;
						sz--;
					}
				}
			}
		}
		break;
	case List::DeleteFlag::GREATER:
		while (current != NULL) {
			/* Why can I not use current here? */
			firstVal = first->value;
			if (firstVal == d) {
				Node *tobedeleted = first;
				first = first->next;
				delete tobedeleted;
				sz--;
				break;
			}
			else {
				/* Why can I not use first here? */
				if (current->value > d) {
					previous->next = current->next;
					delete current;
					current = previous;
					sz--;
				}
				else {
					previous = current;
					current = current->next;
				}
			}
		}
		break;
	}
}

	


