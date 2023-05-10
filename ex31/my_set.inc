template <typename T> 
bool my_set<T>::add(T data) {
    //first, abort if new_value would be a duplicate when added to set
    my_node<T>* cur = head;
    while (cur) {
        if (cur->get_data() == data) {
        return false;
        }
        cur = cur->get_next();
    }

    //next, create new node to hold the new value
    my_node<T>* new_node = new my_node<T>(data);
    if (!new_node) {  //allocation failed!
        return false; 
    }

    if (!head) { //list is currently empty
        head = new_node;
        count++;
        return true;
    }
    if (data < head->get_data()) { //new_node is smallest
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
    while (cur->get_next() && (cur->get_next()->get_data() < data)) {
        cur = cur->get_next();
    }
    new_node->set_next(cur->get_next());  //may be nullptr, but that's ok too
    cur->set_next(new_node);
    count++;
    return true;
} 

template <typename T>
void my_set<T>::clear() {
    my_node<T>* curr = head;
    while (curr != nullptr) {
        my_node<T>* next = curr->get_next();
        delete curr;
        curr = next;
    }
    head = nullptr;
    count = 0;
}

template <typename T>
my_set<T>& my_set<T>::operator+=(T data) {
    this->add(data);
    return *this;
}

template <typename T> 
my_set<T>& my_set<T>::operator=(const my_set<T>& rhs) {
    if (this != &rhs) {
        this->clear();
        for (my_node<T>* curr = rhs.head; curr != nullptr; curr = curr->get_next()) {
            this->add(curr->get_data());
        }
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const my_set<T>& rhs) {
    os << "{";
    for (my_node<T>* curr = rhs.head; curr != nullptr; curr = curr->get_next()) {
        if (curr->get_next() != nullptr) {
            os << curr->get_data() << ", ";
        } else {
            os << curr->get_data();
        }
    }
    return os << "}";
}