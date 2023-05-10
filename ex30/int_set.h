#ifndef INT_SET_H
#define INT_SET_H

#include <iostream>
#include "int_node.h"

class int_set {
    private:

        int count;
        int_node* head;

        // helper method
        bool has(int data);

    public:

        // constructors 
        int_set() : count(0), head(nullptr) {}
        int_set(int_node* head) : count(1), head(head) {}
        int_set(const int_set& rhs);
        ~int_set();

        // member functions
        bool add(int data);
        int get_size() { return count; }
        void clear();

        // operator overloading
        int_set& operator+=(int data);
        int_set& operator=(const int_set& rhs);

        // output contents
        friend std::ostream& operator<<(std::ostream& os, const int_set& rhs);

};

#endif