/*********************************************************
* Summary: Demonstrates the creation of a function to randomly return
*          either heads or tails as many times as the user specifies.
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>
#include <cstdlib> // Allows rand() and srand()
#include <ctime>   // Allows time(0)

using namespace std;

string coinFlip() {
   string coinValue;
   int coinValueNumber = rand() % 2;
   
   if (coinValueNumber == 0) {
      coinValue = "Tails";
   }
   else {
      coinValue = "Heads";
   }
   
   return coinValue;
}

int main() {
   srand(2);
   
   int numRounds;
   cin >> numRounds;

   if (numRounds > 0) {
      for (int i = 0; i < numRounds; ++i) {
         cout << coinFlip() << endl;
      }
   }
   else {
      cout << numRounds << " is not a valid number of rounds." << endl;
   }

   return 0;
}
