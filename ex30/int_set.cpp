#include <iostream>
#include "int_set.h"

int_set::int_set(const int_set& rhs) : count(0), head(nullptr) {
    *this = rhs;
}

int_set::~int_set() {
    this->clear();
}

bool int_set::has(int data) {
    for (int_node* curr = head; curr != nullptr; curr = curr->get_next()) {
        if (curr->get_data() == data) {
            return true;
        }
    }
    return false;
}

//insert the given item into the set, provided it's not a duplicate
//return true if insertion successful, false otherwise
//RESTRICTION: use only < and == on the data within nodes (not <=, >, >=, !=)
bool int_set::add(int new_value) {

  //first, abort if new_value would be a duplicate when added to set
  int_node* cur = head;
  while (cur) {
    if (cur->get_data() == new_value) {
      return false;
    }
    cur = cur->get_next();
  }

  //next, create new node to hold the new value
  int_node* new_node = new int_node(new_value);
  if (!new_node) {  //allocation failed!
	return false; 
  }

  if (!head) { //list is currently empty
	head = new_node;
	count++;
	return true;
  }
  if (new_value < head->get_data()) { //new_node is smallest
        new_node->set_next(head);
	head = new_node;
	count++;
	return true;
  }

  //new_node should go somewhere after 1st node, so let's locate
  //first node whose data larger than new_node's.  But we must
  //be careful not to fall off end of list!
  cur = head;
  //So we'll stop looping when either cur is pointing to last node
  //in the list, or cur has advanced as far into this list as it can,
  //while still pointing to a node with a value smaller than new one
  while (cur->get_next() && (cur->get_next()->get_data() < new_value)) {
    cur = cur->get_next();
  }
  new_node->set_next(cur->get_next());  //may be nullptr, but that's ok too
  cur->set_next(new_node);
  count++;
  return true;
}


void int_set::clear() {
    int_node* curr = head;
    while (curr != nullptr) {
        int_node* next = curr->get_next();
        delete curr;
        curr = next;
    }
    head = nullptr;
    count = 0;
}

int_set& int_set::operator+=(int data) {
    this->add(data);
    return *this;
}

int_set& int_set::operator=(const int_set& rhs) {
    if (this != &rhs) {
        this->clear();
        for (int_node* curr = rhs.head; curr != nullptr; curr = curr->get_next()) {
            this->add(curr->get_data());
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const int_set& rhs) {
    os << "{";
    for (int_node* curr = rhs.head; curr != nullptr; curr = curr->get_next()) {
        if (curr->get_next() != nullptr) {
            os << curr->get_data() << ", ";
        } else {
            os << curr->get_data();
        }
    }
    return os << "}";
}