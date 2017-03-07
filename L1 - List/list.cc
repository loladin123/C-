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
		cout << firstCopy->value << endl;
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
		first = new Node(d, NULL), sz++;
	else {
		Node* newnode = first;
		first = new Node(d, newnode);
		sz++;
	}
}

void List::remove(int d, DeleteFlag df) {
	Node *previous = nullptr;
	Node *current = first;
	int firstval = first->value;
	while(current != NULL){
		/* works outside of while but with first instead of current*/
		if (d == firstval) {
			Node *tobedeleted = current;
			current = current->next;
			delete tobedeleted;
			break;
		}
		if (current->value == 10) {
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



	//switch (df) {
	//case List::DeleteFlag::LESS:
	//	break;
	//case List::DeleteFlag::EQUAL:
	//	if (exists(d)) {
	//		while (first != NULL) {
	//			if (first->value == d)
	//				delete first;
	//			else
	//				first = first->next;
	//		}
	//	}
	//	break;
	//case List::DeleteFlag::GREATER:
	//	if (exists(d)) {
	//		while (first != NULL) {
	//			if (first->value >= d)
	//				delete first;
	//			else
	//				first = first->next;
	//		}
	//	}
	//	break;
	//}


}

	
	



