// defintion of singly linked list node
//
// David John
// March 2019

//Updated for Lab6: April 2019 Grace Hofferber

#ifndef SLLNODE_H
#define SLLNODE_H

#include <iomanip>
#include <iostream>
#include <string>

#include "groceryitem.h"

using namespace std;

class SLLNode : public groceryitem
//everything in groceryitem is being inherited into SLLNode
{

	// overload the output operator
	friend ostream & operator<<(ostream & OUT,  const SLLNode & XXX);

	private:
		//All variables in groceryitem are here.

		SLLNode* Next;

	public:

	// default and alternate constructor
	SLLNode() : groceryitem() {Next=NULL;}

SLLNode(const string &iName, const double itemUnitPrice, const int iInventory, const double iTax,
	SLLNode* inext): groceryitem(iName,itemUnitPrice,iInventory,iTax){
		Next = inext;
	}
//copy constructor for groceryitem
SLLNode(const groceryitem & newItem, SLLNode* inext): groceryitem(newItem){ Next = inext;}



//	string getName() const {
//		return this->getName();}

	// getters
	SLLNode* getNext() const {	return Next;}

	void setNext(SLLNode* next){
		Next = next;
	}
};

#endif
