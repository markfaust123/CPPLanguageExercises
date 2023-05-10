#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "MyNode.h"

template <typename T> 
class MyList {
    private:

        MyNode<T>* head;

    public:

        class iterator {
            private: 
                MyNode<T>* ptr;

            public:

                iterator(MyNode<T>* ptr) : ptr(ptr) {}

                iterator& operator++() { ptr = ptr->next; return *this; }
                bool operator!=(const iterator& it) const { return ptr != it.ptr; }
                T& operator*() { return ptr->data; }

        };

        iterator begin() { return iterator(head);     }
        iterator end()   { return iterator(nullptr);  }

        class const_iterator {
            private: 
                MyNode<T>* ptr;

            public:

                const_iterator(MyNode<T>* ptr) : ptr(ptr) {}

                const_iterator& operator++() { ptr = ptr->next; return *this; }
                bool operator!=(const const_iterator& rhs) const { return ptr != rhs.ptr; }
                const T& operator*() const { return ptr->data; }

        };

        const_iterator cbegin() const { return const_iterator(head); }
        const_iterator cend()   const { return const_iterator(nullptr); }

        


        MyList<T>() : head(nullptr) { } // create empty linked list

        template <typename Itr>
        MyList<T>(Itr begin, Itr end) : head(nullptr) {
            for (Itr it = begin; it != end; it++) {
                this->insertAtTail(*it);
            }
        }
            
        ~MyList<T>();                   // deallocate all nodes

        void insertAtHead(const T& d);  // create new MyNode and add at head

        void insertAtTail(const T& d);  // create new MyNode and add at tail

        // get const pointer to head node
        const MyNode<T>* get_head() const { return head; }

};

#include "MyList.inc"

#endif