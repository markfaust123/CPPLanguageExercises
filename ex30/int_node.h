#ifndef INT_NODE_H
#define INT_NODE_H

class int_node {
    private:
        int payload;
        int_node* next;
    public:
        // constructors
        int_node() : payload(0), next(nullptr) {}
        int_node(int payload) : payload(payload), next(nullptr) {}
        int_node(int payload, int_node* next) : payload(payload), next(next) {}
        
        // getters
        int get_data()       { return payload; }
        int_node* get_next() { return next;    }

        // setters
        void set_data(int data)           { payload = data; }
        void set_next(int_node* new_next) { next = new_next; }
};

#endif