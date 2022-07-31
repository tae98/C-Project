
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template<typename T>

class LinkedList {

private:
	Node<T>* head;
	Node<T>* tail;
	int count;

	//vector<T> list;
public:

	LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->count = 0;
	}

	LinkedList(std::initializer_list<T> list) {
		this->head = nullptr;
		this->tail = nullptr;
		this->count = 0;

		for (T node : list) {
			push_back(node);
		}
		int a = 0;

	}
	//Function : push_front(T data)
	//returns a reference to the data inside the head node

	void push_front(T data) {

		/* Create added node */
		Node<T>* node = new Node<T>(data);

		if (head == nullptr) {	/* If LinkedList size == 0 */
			head = node;
			tail = node;
		}
		else {

			//*add from the from, hence connect node to head 
			node->next = head;
			head = node;

		}

		count++;
	}


	// Function : front()
	//returns a reference to the data inside the head node

	T& front() {
		return head->data;
	}


	//Function : push_back(T data)
	//takes an item and pushes it onto the back of the list

	void push_back(T data) {

		/* Create added node */
		Node<T>* node = new Node<T>(data);

		if (head == nullptr) {	/* If LinkedList size == 0 */
			head = node;
			tail = node;
		}
		else {
			// add from the back, hence connect node to tail 
			Node<T>* temp = tail;

			temp->next = node;
			node->previous = tail;
			tail = node;

		}
		count++;
	}


	// Function : back()
	//returns a reference to the data inside the tail node

	T& back() {
		return tail->data;
	}


	//Function : size()
	//returns the count of how many elements are in the list

	int size() {
		return count;
	}


	//Function : begin()
	//returns an iterator pointing to the head of the list

	NodeIterator<T> begin() const {
		NodeIterator<T> ni=head;
		return ni;

	}


	// Function : end()
	//returns an iterator pointing to 'nullptr'

	NodeIterator<T> end() const {
		NodeIterator<T> ni=nullptr;
		return ni;
	}


	// Function : destructor
	//'delete's every node in the list.
	~LinkedList() {

		//remove nodes from head
		while (head != nullptr)
		{
			Node<T>* temp;

			temp = head;
			head = head->next;
			delete temp;
			count--;
		}

	}

	// Function : reverse
	//reverses the order of the nodes in the list
	//it doesn't make new nodes, it should re-order the existing nodes

	void reverse() {

	}

	//Function : insert

	NodeIterator<T> insert(NodeIterator<T> ni, T data) {

		/* Create added node */
		Node<T>* node = new Node<T>(data);
		Node<T>* temp = ni.current->previous;
		ni.current->previous->next = node;
		node->next = ni.current;
		node->previous = temp;
		ni.current->previous = node;
		if (head == ni.current) {
			head = node;
		}
		else {
			ni.current = ni.current->previous;
		}
		++count;
		return ni;
	}

	//Function : erase

	NodeIterator<T> erase(NodeIterator<T> ni)
	{

		if (ni.current == tail) {
			ni.current->previous = tail;
		}
		else if (ni.current->data == head->data) {
			ni.current->next = head;
		}
		else {
			ni.current->previous->next = ni.current->next;
			ni.current->next->previous = ni.current->previous;
		}
		Node<T>* temp = ni.current->next;
		delete ni.current;
		--count;
		return temp;


	}
};


// do not edit below this line

#endif
