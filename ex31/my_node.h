#ifndef MY_NODE_H
#define MY_NODE_H

template <typename T>
class my_node {
    private:
        T data;
        my_node* next;
    
    public:
        // constructors
        my_node(T data) : data(data), next(nullptr) {}
        my_node(T data, my_node* next) : data(data), next(next) {}

        // getters
        T get_data() { return data; }
        my_node* get_next() { return next; }

        // setters
        void set_data(T data) { this->data = data; }
        void set_next(my_node* next) { this->next = next; }
};

#endif