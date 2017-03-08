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

void List::insertFirst(int d) {
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
	/* This node was the issue, I was never updating current so it used the old list */
	Node *current = first;
	int firstVal;
	switch (df) {
	case List::DeleteFlag::LESS:
		while (current != NULL) {
			firstVal = first->value;
			if (firstVal < d) {
				Node *tobedeleted = first;
				first = first->next;
				delete tobedeleted;
				sz--;
				current = first;
			}
			else if (current->value < d) {
				previous->next = current->next;
				delete current;
				current = previous;
				sz--;
			}
			else {
				previous = current;
				if (current->next == NULL) break;
				current = current->next;
			}
		}
		break;
	case List::DeleteFlag::EQUAL:
		if (exists(d)) {
			while (current != NULL) {
				firstVal = first->value;
				if (firstVal == d) {
					Node *tobedeleted = first;
					first = first->next;
					delete tobedeleted;
					sz--;
					current = first;
				}
				else if (current->value == d) {
					previous->next = current->next;
					delete current;
					current = previous;
					sz--;
				}
				else {
					previous = current;
					if (current->next == NULL) break;
					current = current->next;
				}
			}
			break;
		}
		break;
	case List::DeleteFlag::GREATER:
		while (current != NULL) {
			firstVal = first->value;
			if (firstVal > d) {
				Node *tobedeleted = first;
				first = first->next;
				delete tobedeleted;
				sz--;
				current = first;
			}
			else if (current->value > d) {
				previous->next = current->next;
				delete current;
				current = previous;
				sz--;
			}
			else {
				previous = current;
				if (current->next == NULL) break;
				current = current->next;
			}
		}
		break;
	}
}

	


