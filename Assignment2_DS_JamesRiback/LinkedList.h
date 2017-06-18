#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
//All header definitions below
/* struct NODE ====================*/
template <class T>
struct Node {
	T data;
	//pointers
	Node<T> *next;
	Node<T> *prev;
	Node(T data)//initialize node with user data and set ptrs to null
		:data(data), next(nullptr), prev(nullptr) {};
};

/* ====== Class LINKED LIST  ========*/
template <class T>
class LinkedList{
private:
	unsigned nodes;
	Node<T> *Head;
	Node<T> *Tail;
	//Helper functions
	void addRoot(T value);
	Node<T> *getNode(T value);
public:
	void printList();
	LinkedList();
	bool isEmpty();
	bool insertBefore(T currVal, T value);
	bool insertAfter(T currVal, T value);
	void deleteElement(T currVal);
	unsigned size();
	void addFront(T value);
	void addBack(T value);
	//indexes
	int find(T value);
	int indexEnd();
	int indexBegin();
};
#endif

/* class definition ===============*/
//Default Constructor
template<class T>
LinkedList<T>::LinkedList()
{
	nodes = 0;
	Node<T>	*dummyHead = new Node<T>(NULL);
	Node<T> *dummyTail = new Node<T>(NULL);
	dummyHead->next = nullptr;
	dummyTail->prev = nullptr;
	Head = nullptr;
	Tail = nullptr;

}
template<class T>
void LinkedList<T>::printList()
{
	if (isEmpty())
	{
		cout << "List is empty~" << endl;
		return;
	}
	//set a pointer to the head
	Node<T>*p = this->Head;
	//Traverse to the end of the list
	//printing values as we go
	while (p != nullptr)
	{
		cout << p->data << endl;
		p = p->next;
	}

}
template<class T>
bool LinkedList<T>::isEmpty()
{
	return nodes == 0;
}

template<class T>
unsigned LinkedList<T>::size()
{
	return nodes;
}
template<class T>
void LinkedList<T>::addFront(T value)
{
	//If the list is empty add a root
	if (isEmpty())
	{
		addRoot(value);
	}
	else
	{
		//Create a new node and set the data using node constructor
		Node<T> *n = new Node<T>(value);
		//point our new node's next ptr to the head
		n->next = Head;
		//attatch the next nodes previous to the new node
		n->next->prev = n;
		//point head to new node
		Head = n;
		nodes++;
			
	}

}

template<class T>
void LinkedList<T>::addBack(T value)
{
	if (isEmpty())
	{
		addRoot(value);
	}
	else
	{
		//Create a new node and set the data using node constructor
		Node<T> *n = new Node<T>(value);
		//set the nodes previous to point to tail
		n->prev = Tail;
		//attatch the previous node's next to the new node
		n->prev->next = n;
		//point tail to new node
		Tail = n;
		nodes++;
	}
}
//return the index of where node is located and -1 if it is not in the list
template<class T>
int LinkedList<T>::find(T value)
{
	int index = 0;
	Node<T> *curr = Head;
	while (curr != nullptr) {
		if (curr->data == value)
			return index;
		++index;
		curr = curr->next;
	}
	//if node not found
	return -1;
}
//Returns the index of the last element of the LL
template<class T>
int LinkedList<T>::indexEnd()
{
	int index = 0;
	Node<T> *curr = Head;
	while (curr != nullptr)
	{
		index++;
		curr = curr->next;
	}
	return index-1;
}

template<class T>
int LinkedList<T>::indexBegin()
{
	if (isEmpty())
		return -1;
	else
		return 0;
}
	
template<class T>
bool LinkedList<T>::insertBefore(T currVal, T value) {
	//find the node to insert before
	Node<T> *curr = getNode(currVal);
	if (curr != nullptr) {
		//create new new node
		Node<T> *n = new Node<T>(value);
		//attatch new node inbetween prev node and curr
		n->prev = curr->prev;
		n->next = curr;
		curr->prev->next = n;
		curr->prev = n;

		nodes++;
		return true;
	}
	return false;
}
template<class T>
bool LinkedList<T>::insertAfter(T currVal, T value) {
	// find the node to insert after
	Node<T> *curr = getNode(currVal);
	if (curr != nullptr) {
		// create new new node
		Node<T> *n = new Node<T>(value);
		// attach new node inbetween curr and next node
		n->next = curr->next;
		n->prev = curr;
		curr->next->prev = n;
		curr->next = n;

		nodes++;
		return true;
	}
	return false;
}
//Descr: You can only use this function to delete nodes 
//that are not the very first or very last node
template<class T>
void LinkedList<T>::deleteElement(T currVal)
{
	if (size() == 1)
	{
		Node<T> *p = Head;
		Head = nullptr;
		Tail = nullptr;
		delete p;
		nodes--;
	}
	//If the currVal = first node or last node
	else if (find(currVal) == indexBegin())
	{
		Node<T> *p = Head;
		//disconnect garbage node
		p->next->prev = nullptr;
		Head = p->next;
		delete p;
		nodes--;
	}
	else if (find(currVal) == indexEnd())
	{
		Node<T> *p = Tail;
		p->prev->next = nullptr;
		p->prev = Tail;
		delete p;
		nodes--;
	}
	else
	{
		Node<T> *p = Head;
		//Stop at the node before the one you want to delete
		while (p->next->data != currVal)
		{
			p = p->next;
		}
		//set up the next node for deletion
		Node<T> *delptr = p->next;
		//reset pointers
		p->next = p->next->next;
		p->next->prev = p; //disconnect garbage node
		//delete garbage node
		delete delptr;
		nodes--;
	}
}

/* Class helper function definitions =========================== */
template<class T>
void LinkedList<T>::addRoot(T value) {
	// create new node
	Head = new Node<T>(value);
	// create Tail, bloop
	Tail = Head;
	nodes++;
}
template<class T>
Node<T> *LinkedList<T>::getNode(T value) {
	Node<T> *curr = Head;
	while (curr != nullptr) {
		if (curr->data == value)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}