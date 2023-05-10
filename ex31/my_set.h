#ifndef MY_SET_H
#define MY_SET_H

#include <iostream>
#include "my_node.h"

template <typename T> 
class my_set {
    private:

        my_node<T>* head;
        int count;

        bool has(T data);

    public:

        // constructors
        my_set() : head(nullptr), count(0) {}
        my_set(my_node<T>* head) : head(head), count(1) {}
        my_set(const my_set& rhs) : head(nullptr), count(0) { *this = rhs; }
        ~my_set() { this->clear(); }

        // member functions
        bool add(T data);
        int get_size() { return count; }
        void clear();

        // operator overloading
        my_set& operator+=(T data);
        my_set& operator=(const my_set& rhs);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const my_set<U>& rhs);

};

#include "my_set.inc"

#endif