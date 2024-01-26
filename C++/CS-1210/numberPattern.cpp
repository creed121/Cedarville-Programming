/*********************************************************
* Summary: Uses a recursive function to print all numbers from the user input
*          to the first negative number, counting by a user-defined value.
*
* Author:  Christopher Reed
* Created: November 2023
*
********************************************************/

#include <iostream>

using namespace std;

void printNumPattern (int currentValue, int countByValue) {

   if (currentValue >= 0) {
      cout << currentValue << ' ';
      printNumPattern (currentValue - countByValue, countByValue);
   }
   cout << currentValue << ' ';
   return;
}

int main() {
   int num1;
   int num2;
   // cout << "Please enter your starting value." << endl;
   cin >> num1;
   // cout << "Please enter the value you wish to count by." << endl;
   cin >> num2;
   printNumPattern(num1, num2);
   cout << flush;
   
   return 0;
}
