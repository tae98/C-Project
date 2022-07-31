
#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists

template<typename T>
class Node {
public:
    //Three 'public' member variables
    T data;
    Node<T>* next;
    Node<T>* previous;

    //Constructor
    //takes an item of data, stores it in the node, and sets the two pointers to 'nullptr' 

    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

template<typename T>
class NodeIterator {

public:
    Node<T>* current;
    NodeIterator(Node<T>* currentIn) : current(currentIn) {
        //: To reset constructor
        //this->current = currentIn 
    }

    T& operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here
    // ++ operator
    //makes it point to the next node in the list
    void operator ++() {
        current = current->next;
    };


    // == operator 
    //Two iterators are the same if they point to the same Node

    bool operator ==(const NodeIterator& node) {
        if (this->current == (node.current))
            return true;
        else
            return false;
    }


    // != operator
    //Check if two iterators are different

    bool operator !=(const NodeIterator& node) {
        if (this->current != (node.current))
            return true;
        else
            return false;
    }

};

// do not edit below this line

#endif
