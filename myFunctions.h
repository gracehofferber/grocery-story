// class header for myFunctions ifstream
//
// Grace Hofferber
// Date: 25.2.19

//Updated for Lab6: April 2019 Grace Hofferber
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <utility>
#include <cmath>
#include "groceryitem.h"
#include "SLLList.h"
#include "SLLNode.h"

using namespace std;

void dumpGroceryInformation(const SLLList GS);
void readGroceryInfo( SLLList & GS);
pair<double,double> buyGrocery(SLLList GS, istringstream& command);
void statusGrocery(istringstream & command, const SLLList GS);
double pay(double subTotal, double subTax);
string commandtoLower(string& myCommand);
string convertNametoLower(string& itemName);
double Discounts(double subTotal, double subTax);// Option 1
int returnGrocery(int itemUnits,const string & itemName, const SLLList & GS);//Option 2

//added for Lab 6.
void deleteNode(SLLList & GS);
void addNode(SLLList & GS);

#endif
