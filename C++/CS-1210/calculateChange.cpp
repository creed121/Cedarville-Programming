/*********************************************************
* Summary: Uses a recursive function to calculate the smallest number of
*          coins for a user-provided input of money.
*
* Author:  Christopher Reed
* Created: November 2023
*
********************************************************/

#include <iostream>
#include <vector>

using namespace std;

void printChange(int amount, const vector<int> &coinTypes, int currentCoin) {

   if (currentCoin > 5) {
      return;
   }
   cout << amount / coinTypes.at(currentCoin) << " @ " <<
           coinTypes.at(currentCoin) << endl;
   printChange(amount % coinTypes.at(currentCoin), coinTypes, currentCoin + 1);
}

int main() {
   vector<int> denominations = {100, 50, 25, 10, 5, 1};
   int amt = 0;

   // cout << "What amount (in cents) would you like to make change for? ";
   cin  >> amt;

   printChange(amt, denominations, 0);

   return 0;
}
