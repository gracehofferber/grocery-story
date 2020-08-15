// Define a singly linked list
//
// David John
// March 2019

//Updated for Lab6: April 2019 Grace Hofferber
#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <string>
#include <cmath>

#include "SLLNode.h"
#include "groceryitem.h"

using namespace std;

class SLLList
{

	// overload output stream operator
	friend ostream & operator<<(ostream & OUT, const SLLList & mylist);

	private:
		SLLNode* first;
		SLLNode* last;
		int size;

	public:

	// default constructor
	SLLList() { first=NULL;last=NULL;size=0;}

	int getSize() const {return size;}
	SLLNode* getFirst() const {return first;}

	// prototypes for methods
	SLLNode* find(const string & name)const;
	void insertFront(const groceryitem & newGroceryItem);
	void insertBack(const groceryitem & newGroceryItem);
	void insertBetween(const groceryitem & newGroceryItem, SLLNode* lag);

void remove(const string & target);
pair <long, long> findFancy(const string & target);
void add(const string & target, const groceryitem& newGroceryItem);


};



#endif
