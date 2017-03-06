#include "stdafx.h"
#include <iostream>
#include "list.h"

List::List() {

}

List::~List() {
}

bool List::exists(int d) const {
	return true;
}

int List::size() const {
	return sizze;
}

bool List::empty() const {
	return sizze == 0;
}

void List::insertFirst(int d) {
	Node *head = new Node(d, nullptr);
	head->next = 0;
	sizze++;

		
	
}

void List::remove(int d, DeleteFlag df) {

}

void List::print() const {
}

