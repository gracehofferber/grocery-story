// Driver program to use with groceryitem class
//
// Grace Hofferber
// Date: 25.2.19

//Updated for Lab6: April 2019 Grace Hofferber
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>


#include "myFunctions.h"
#include "groceryitem.h"
#include "SLLList.h"
#include "SLLNode.h"

using namespace std;



int main()
{

  //Created by David John
  //declaring the list.
  SLLList GroceryStore;


//created by Grace Hofferber
  double subtotal = 0.0;
  double subtax = 0.0;
  string input = "";

  cout << "Please enter what you would like to do:" << endl;


  while(getline(cin,input)){
    //taking the user input and checking to see what they would like to do.
    istringstream command(input);
    bool check = false;
    string myCommand;
    command >> myCommand;
    string newCommand = commandtoLower(myCommand); //new myCommand.

    if(newCommand == "open"){
      check =true; //turn to true if user input is correct.
      // read grocery info from file
      readGroceryInfo(GroceryStore);

      cout << "Please enter what you would like to do:" << endl;
    }
    else if(newCommand == "close"){
      check =true;
      if(GroceryStore.getSize() > 0){
         cout << "Here is whats left of the products: " << endl;
         // dump out grocery store dumpGroceryInformation
         dumpGroceryInformation(GroceryStore);
        cout << "Thanks for shopping!" << endl;
        return 0;
    }
      else{
        cout << "You have not opened your inventory. Please open it." << endl;

        cout << "Please enter what you would like to do:" << endl;
    }
    exit(0); //exit the program when user calls close command
    }

    else if(newCommand == "buy"){
      check =true;
      pair<double,double> itemInfo = buyGrocery(GroceryStore,command);
     subtotal += itemInfo.first; //grabbing subtotal from the pair
      subtax += itemInfo.second;//grabbing subtax from the pair.
      cout<< setw(30) << "Your total at the moment is: " << subtotal + subtax << endl;

      cout << "Please enter what you would like to do:" << endl;
    }

    else if(newCommand == "status"){
      check =true;
      //print out the the items/item in grocery store.
    statusGrocery(command,GroceryStore);

      cout << "Please enter what you would like to do:" << endl;
    }

    else if(newCommand == "pay"){

      check = true;
      //calls the function that calculates the total
     pay(subtotal,subtax);

      cout << "Please enter what you would like to do:" << endl;
    }
    else if(newCommand == "delete"){
      check = true;
      //calls function to delete a node from the list.
      deleteNode(GroceryStore);

      cout << "Please enter what you would like to do:" << endl;
    }
    else if(newCommand == "add"){
      check = true;
      //calls function to add a node to the list.
      addNode(GroceryStore);

      cout << "Please enter what you would like to do:" << endl;
    }
    else if (check = false){ //if what they entered isn't one of the key terms above.
        cerr << "Invalid command. Please try again." << endl;
        cout << "Please enter what you would like to do:" << endl;
    }

  }
  return 0;
}
//1st Option: Discounts!
//2nd Option: Return items.
