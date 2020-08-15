// Implementations of methods and friend functions for singly linked list node
//
// David John
// March 2019

//Updated for Lab6: April 2019 Grace Hofferber

#include "SLLNode.h"

// overloaded output operator
ostream & operator<<(ostream & OUT, const SLLNode & XXX)
{
	OUT << setw(10) << XXX.getName()
		<< setw(5) << XXX.getUnitPrice()
		<< setw(5) << XXX.getInventory()
		<< setw(5) << XXX.getTax()
		<< setw(4) << " "
		<< setw(12) << hex << XXX.getNext() << endl;
	return OUT;
}
