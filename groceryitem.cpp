// Implementation of some of the methods
// for the groceryitem class
//
// David John
// February 2019

//Updated for Lab6: April 2019 Grace Hofferber

#include "groceryitem.h"

// method to increase the number of items in the
// inventory of "this", returns the total number
// of items in the inventory
int groceryitem::increaseInventory(const int value)
{
  itemInventory += value;
  return itemInventory;
}

// method to decrease the number of items in the
// inventory.  Does not allow the inventory to
// become negative, and does not allow the decrease
// to be a negative.  On any error, the returned
// value is -1, otherwise the new inventory level.
int groceryitem::decreaseInventory (const int value)
{
  // do a sanity check on the parameter, if it makes
  // no sense then do not change inventory and return a
  // -1 as an error flag
  if ((value<0) || (itemInventory-value<0))
  {
    return -1;
  }

  // value makes sense, change inventory and return
  // new level
  itemInventory -= value;
  return itemInventory;
}

istream & operator>>(istream & IN, groceryitem & XXX){
  IN >> XXX.itemName;
  IN >> XXX.itemUnitPrice;
  IN >> XXX.itemInventory;
  IN >> XXX.itemTax;
  return IN;
}
ostream & operator<<(ostream & OUT, const groceryitem & XXX)
{
  OUT << XXX.itemName;
  OUT << XXX.itemUnitPrice;
  OUT << XXX.itemInventory;
  OUT << XXX.itemTax;
  return OUT;
}
