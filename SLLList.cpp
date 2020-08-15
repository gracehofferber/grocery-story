// Implementations for methods and friend functions
// for SLLList class
//
// David John
// March 2019

//Updated for Lab6: April 2019 Grace Hofferber
#include "SLLList.h"
#include "SLLNode.h"

using namespace std;

// find
SLLNode* SLLList::find(const string & name) const
{
	SLLNode* current;

	// sequentially search the list, from the first to the end
	for(current = first;current != NULL;current = current->getNext())
	{
		// if name is found then return the location of the match
		if(current->getName() == name)
		{
			return current;
		}
	}
	// no match for name so return NULL pointer
	return NULL;
}

//edited by Grace Hofferber
// insert at front of list
void SLLList::insertFront(const groceryitem & newGroceryItem)
{
	// create a new node that fits at the front of the list, and
	// increment the size of the list
	//created by Grace Hofferber
SLLNode* temp = new SLLNode(newGroceryItem,first);
	if(size == 0){ //checks to see if its 0.
		first = temp; //setting the new inserted node to the front of the list.
	}
	else{
		first = temp;
		last = temp;
	}
	last = temp;//updating last.
	size++;
}

//Created by Grace Hofferber
//insert back of list.
void SLLList::insertBack(const groceryitem & newGroceryItem){
		//going to the very end so it has to point to null

	//	SLLNode* temp = new SLLNode(newName,1,NULL);
	SLLNode* temp = new SLLNode(newGroceryItem,NULL);
		if(last == NULL){
			//if last is the last node set both first and last to temp.
			first = temp;
			last = temp;
		}
	else{
		//calling set next which sets the next node to temp which points to null.
		last->setNext(temp);
	}
	last = temp;
	size++;
}
// inserts the node between two nodes.
void SLLList::insertBetween(const groceryitem & newGroceryItem, SLLNode* lag){

	SLLNode* temp = new SLLNode(newGroceryItem,lag->getNext());
	lag->setNext(temp);
	size++;

}

pair <long, long> SLLList::findFancy(const string & target){
	//Seachers through the list, from first to end. If the name is found then the
	//first address where the match was found and the second is the node that calls
	// it or is null. If the name isn't found first = null.
	SLLNode* current;
	SLLNode* lag;
	for(current = first, lag = NULL; current!= NULL; lag = current, current = current->getNext()){
		if(current -> getName() == target){//if name is found return the location.
			break;
		}
			else if(target < current-> getName()){ //if the target is less than current.
				return pair <long,long> ((long)current,(long)lag);
		}
		}
			return pair <long,long> ((long)current,(long)lag);
	}


//removing from the list.
void SLLList::remove(const string & target){
	pair <long,long> addresses = findFancy(target);

//its not in the list.
	if((SLLNode*) addresses.first == NULL){
		return;
	}
	//splitting the pair apart so it can be used.
	SLLNode* current = (SLLNode*) addresses.first;
	SLLNode* lag = (SLLNode*) addresses.second;

	if(lag == NULL){ //deleteing first node.
		first = current -> getNext();
		if(size == 1){
			last = NULL;
		}
	}
	else{ //deleting other nodes.
			lag ->setNext(current->getNext());
		}
		//reduce size and delete current.
		size --;
		delete current;
		return;
	}




// overload output operator
ostream & operator<<(ostream & OUT, const SLLList & mylist)
{

	// print size of list and then step through the list and
	// print information about each node
	OUT << endl << "List has size: " << mylist.size << endl;
	for(SLLNode* current = mylist.first;
		current != NULL;
		current = current->getNext())
	{
		OUT << "<" << hex << current << "> : ";
		OUT << *current;
	}
	OUT << endl;

	return OUT;

}
