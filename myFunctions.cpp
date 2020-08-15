/*This file holds the commands for the user.
Created by: Grace Hofferber
Date: 25.2.19
*/
//Updated for Lab6: April 2019 Grace Hofferber
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "groceryitem.h"
#include "myFunctions.h"
#include "SLLList.h"
#include "SLLNode.h"


using namespace std;


// function to dump out grocery store information
void dumpGroceryInformation(const SLLList GS)
{
  for(SLLNode* GSindex= GS.getFirst(); GSindex != NULL; GSindex= GSindex->getNext())
  {
    cout << setw(15) << GSindex->getName()
         << setw(8) << GSindex->getUnitPrice()
         << setw(8) << GSindex->getInventory()
         << setw(8) << GSindex->getTax() << endl;
  }


  return;

}

// function to read information about the grocery GroceryStore
// from a file into GS[] of size GSPS
void readGroceryInfo(SLLList & GS)
{
  // prompt and read for filename
string filename;
cout << "Enter grocery store filename: " << endl;
getline(cin,filename);//grabbing everything from the input file.

  // open file, stream data from file into array
  ifstream GSData;

  GSData.open(filename);

  // stream from the file into the SLLList.
  //Inserting to the back of the list.
  groceryitem temp;


  while(GSData >> temp){
    pair <long,long> addresses = GS.findFancy(temp.getName());
  	SLLNode* current = (SLLNode*) addresses.first;
  	SLLNode* lag = (SLLNode*) addresses.second;
    if(lag == NULL){
      GS.insertFront(temp);
    }
    else if(current == NULL){
      GS.insertBack(temp);
    }
    else{
      GS.insertBetween(temp,lag);
    }
  }
  // close the file
  GSData.close();
}

//function for buy command.
//grabs the item name and its units from the command line.
pair<double,double> buyGrocery(const SLLList GS, istringstream & command){
  string itemName = "";
  int itemUnits = 0;
  double itemPrice = 0.0;
  double totalPrice = 0.0;
  double itemTax = 0.0;
  double totalTax = 0.0;


  command >> itemName;
  command >> itemUnits;
  if(itemUnits <= 0){
    cerr << "Please also enter the amout of items you are trying to buy." << endl;
  }
  SLLNode* index = GS.find(itemName);
  if(index == NULL){ //name is not in the inventory.
    cerr<< "This item is not sold in the store. Please pick another item."<< endl;

  }
  else{ //if all correct info is given, decrease the units by the amount the user took.
        index->decreaseInventory(itemUnits);
        cout << "Are you sure you want to buy this?" << endl; //Set up for Option 1: return grocery items
        string userinput  = "";
        cin >> userinput;
        if(userinput == "no"){//set up for option 2.
          itemUnits = returnGrocery(itemUnits, itemName, GS);
    }
      else if (userinput == "yes"){
        index->decreaseInventory(itemUnits);
    }
    else{
      cerr << "Error. Try again."<< endl;
    }


  //Grabs the price and tax.
    itemPrice = index->getUnitPrice();
    itemTax = index->getTax();
    cout << "You have added " << itemUnits << " things of " << itemName << endl;

  //calculates the total of the item/items the user bought.
    totalPrice = itemPrice *itemUnits;
    totalTax = itemTax * itemUnits;
  //outputs to show price and tax.
    cout << endl; //cleaning up the output so its easier to read.
    cout << setw(20) << "The total price of " << itemName << " is " << totalPrice << endl;
    cout << setw(12) << "The tax of " << itemName << " is " << itemTax << endl;
    cout << endl;

  return pair<double,double>(totalPrice, totalTax);
}
}


//function to output the status of the inventory to the user.
void statusGrocery(istringstream & command, const SLLList GS){
  string itemName = "";
  command >> itemName;
  SLLNode* singleStatus = GS.find(itemName);

  if(singleStatus == NULL){ //if the user just enters 'status' into the command line
    dumpGroceryInformation(GS);
  }
  else{ //if there is a word after statusGrocery
    //cout the information:
    cout << setw(15) << singleStatus->getName()
    << setw(8) << singleStatus->getUnitPrice()
    << setw(8) << singleStatus->getInventory()
   << setw(8) << singleStatus->getTax() << endl;
  }
}

//function to pay.
double pay(double subTotal, double subTax){
  //print subtotal and subtax.
cout << setw(19) << "The Subtotal is: " << subTotal << "$" << endl;
cout << setw(18) << "The Subtax is : " << subTax << "$" << endl;
//Option one.
double discounts = Discounts(subTotal,subTax);

return 0.0;
}
//function to convert the command line to lowercase, incase the user enters an uppercase.
string commandtoLower(string& myCommand){
 int length = myCommand.length(); //getting length of myCommand.
  for(int i = 0; i < length ; i++){
    if(myCommand[i]>='A' && myCommand[i] <= 'Z'){ //checking to see if its an upper case letter from A-Z
      myCommand[i] = myCommand[i]+32;
    }
  }
  return myCommand;
}




//OPTION 1
//Function to add discounts the the total.
double Discounts(double subTotal, double subTax){
  double discountPrice = 0.0;
  double Total = 0.0;
  if(subTotal >= 20){ // if the total is greater than 15
    cout << setw(30) << "You get a suprise 20% discount!" << endl;
    discountPrice = subTotal * .2; //Applies 20% discount.
    //tell the user what their total is now with the discount.
    cout << setw(32) << "Here is the discounted price: " << discountPrice << "$" << endl;
    Total = round(((subTotal - discountPrice) + subTax) * 100)/100.00;
    //rounds the ammount to two decimal places.
  }
  else if(subTotal < 10){ // if its less than 10$
    cout << setw(35) << "You don't apply for a discount." << endl;
    Total = round((subTotal+ subTax) * 100)/100.00;
  }
  else {//if the total is from 10-19$
    cout << setw(50)<< "You get a suprise 10% discount!"<< endl;
    discountPrice = subTotal * .1; //Applys 10% discount.
    cout << setw(32) << "Here is the discounted price: " << discountPrice << "$" << endl;
    Total = round((discountPrice + subTax) * 100)/100.00; //making sure it stays in the .00 decimal range.
  }

  cout << setw(17) << "The total is : " << Total <<"$" << endl;
  cout << setw(35) << "If you are done shopping, please type 'close'" << endl;

  return 0.0;
}

//OPTION 2
//function to return items that the user doesn't want in their inventory.
int returnGrocery(int itemUnits, const string & itemName, const SLLList & GS){
  cout<< "How much would you like to return" << endl;
  int userinput = 0;
  cin >> userinput;
  int newitemUnits = itemUnits - userinput; //taking away the return amount from origional buy.

  for(SLLNode* GSindex = GS.getFirst(); GSindex != NULL; GSindex= GSindex->getNext()){
    if(GSindex->getName() == itemName){
      GSindex->increaseInventory(userinput); //returns what the user wants to return.
    }
}
return newitemUnits;
}
//deletes a single node that the user inputs.
void deleteNode(SLLList & GS){
  cout << "What do you want to delete"<< endl;
  string temp;
  cin>>temp;

  GS.remove(temp);
  return;

}

void addNode(SLLList & GS){
  string name;
  int inventory;
  double unitprice;
  double tax;
  cout << "What are you name?"<< endl;
  cin >> name;
  cout << "What are you units?"<< endl;
  cin >> unitprice;
  cout << "What are you inventory?"<< endl;
  cin >> inventory;
  cout << "What are you tax?"<< endl;
  cin >> tax;

//calling find fancy to find the current and the lag that the node that is being
//added goes between. Then splitting up current and lag to make them usable.
  pair <long,long> addresses = GS.findFancy(groceryitem(name,unitprice,inventory,tax).getName());
  SLLNode* current = (SLLNode*) addresses.first;
  SLLNode* lag = (SLLNode*) addresses.second;

  if(lag == NULL){
    //if lag is less than the new node that is being added, add it to the front.
    GS.insertFront(groceryitem(name,unitprice,inventory,tax));
  }
  else if(current == NULL){
    //if current is greater than the new node that is being added., add it behind.
    GS.insertBack(groceryitem(name,unitprice,inventory,tax));
  }
  else{
    //insert the new node between lag and current.
    GS.insertBetween(groceryitem(name,unitprice,inventory,tax),lag);
  }
return;
}
