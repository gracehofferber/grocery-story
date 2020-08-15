// class header for grocery ifstream
//
// David John
// February 2019

//Updated for Lab6: April 2019 Grace Hofferber
#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>
#include <iostream>

using namespace std;

class groceryitem
{
  //friends input/output
  friend istream & operator>>(istream & IN, groceryitem & XXX);
	friend ostream & operator<<(ostream & OUT, const groceryitem & XXX);
  // class variables for an item in my grocery store
  private:
    string itemName;
    double itemUnitPrice;
    int itemInventory;
    //created by Grace Hofferber
    double itemTax;

  public:

    // default constructor to initialize an item
  groceryitem()
    {
      itemName = "";
      itemUnitPrice = 0.0;
      itemInventory = 0;
      //Created by Grace Hofferber
      itemTax = 0.0;
    }

    // alternate constructor to initialize an item
groceryitem(const string & iName, const double iUP, const int iInventory, const double iTax)
    {
      itemName = iName;
      itemUnitPrice = iUP;
      itemInventory = iInventory;
      //Created by Grace Hofferber
      itemTax = iTax;
    }

    // getters for each class variable
    string getName() const { return itemName;}

    double getUnitPrice() const { return itemUnitPrice;}

    int getInventory() const { return itemInventory; }


    // prototypes for methods to work with item inventory variable
    int increaseInventory(const int value);
    int decreaseInventory (const int value);

    //created by Grace Hofferber
    double getTax() const { return itemTax;}



};


#endif
