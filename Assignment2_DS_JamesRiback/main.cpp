#include <iostream>
#include <string>
#include <sstream>
#include "Pair.h"
#include "PairList.h"
#include "LinkedList.h"
using namespace std;
int main()
{
	Pair<std::string, int> social("James", 7321);
	Pair<std::string, double> cost("Game", 59.95);
	social.setFirst("Mark");
	cout << social.getFirst() << " " << social.getSecond() << endl;
	cout << cost.getFirst() << " " << cost.getSecond() << endl;

	LinkedList<int> mylist;
	mylist.addBack(24);
	mylist.addFront(42);
	mylist.addBack(33);
	mylist.printList();
	cout << endl;
	cout << "33 is at position " <<  mylist.find(33) << " in our Linked List." << endl;
	cout << endl;
	cout << "Beggining index: " <<  mylist.indexBegin() << " Ending index: " << mylist.indexEnd() << endl;
	mylist.deleteElement(42);
	mylist.deleteElement(33);
	mylist.deleteElement(24);
	cout << endl;
	cout << "After Deleting element(s): " << endl;
	mylist.printList();
	cout << "=================PAIR LIST====================" << endl;
	
	return 0;
}