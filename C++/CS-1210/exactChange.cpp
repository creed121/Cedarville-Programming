/*********************************************************
* Summary: Take in a user defined input and convert it to minimum coin values.
*          Return the values with the respective coin types.
*
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>
#include <vector> 

using namespace std;

void exactChange (int userTotal, vector<int> & coinVals) {
   const int CHANGE_PER_QUARTER = 25;
   const int CHANGE_PER_DIME = 10;
   const int CHANGE_PER_NICKEL = 5;

   coinVals[3] = userTotal / CHANGE_PER_QUARTER;
   userTotal %= CHANGE_PER_QUARTER;

   coinVals[2] = userTotal / CHANGE_PER_DIME;
   userTotal %= CHANGE_PER_DIME;

   coinVals[1] = userTotal / CHANGE_PER_NICKEL;
   userTotal %= CHANGE_PER_NICKEL;

   coinVals[0] = userTotal;      // Find pennies

   return;
}
void printOutput (vector<int> properChange, int totalChange) {
   int numPennies = properChange[0];
   if (numPennies > 0) {
      string pennyString = (numPennies == 1) ? " penny" : " pennies";
      cout << numPennies << pennyString << endl;
   }

   int numNickels = properChange[1];
   if (numNickels > 0) {
      cout << numNickels << " nickel" << endl;
   }

   int numDimes = properChange[2];
   if (numDimes > 0) {
      string dimeString = (numDimes == 1) ? " dime" : " dimes";
      cout << numDimes << dimeString << endl;
   }

   int numQuarters = properChange[3];
   if (numQuarters > 0) {
      string quarterString = (numQuarters == 1) ? " quarter" : " quarters";
      cout << numQuarters << quarterString << endl;
   }

   if (totalChange <= 0) {
      cout << "no change" << endl;
   }

   return;
}

int main() {
   int inputVal;
   vector<int> changeAmount(4); 
   
   //cout << "Please enter how much change (in cents) is required." << endl;
   cin >> inputVal;

   exactChange (inputVal, changeAmount);
   printOutput (changeAmount, inputVal);

   return 0;
}
