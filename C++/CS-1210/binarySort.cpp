/*********************************************************
* Summary: Uses a bubble sort algorithm to sort a vector provided by the user.
*          Outputs the sorted vector.
*          Note: the length is also determined by the user.
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> createVector () {
   vector<int> newVector;
   int vectorLength;
   cin >> vectorLength;
   for (int i = 0; i < vectorLength; ++i) {
      int newestValue;
      cin >> newestValue;
      newVector.push_back(newestValue);
   }

   return newVector;
}
void printVector (const vector<int> & toPrintVector) {
   for (int i = 0; i < toPrintVector.size(); ++i) {
      cout << toPrintVector[i] << ',';
   }
   cout << endl;
   return;
}
void swapValues (int & firstVal, int & secondVal) {
   int holderVariable = firstVal;
   firstVal = secondVal;
   secondVal = holderVariable;
   return;
}
void sortVector (vector<int> & scrambledVector) {
   /* Inner loop moves the smallest value to the end of the vector, while
      outer loop repeats until the largest value is at the beginning of it. */
   for (int i = 0; i < scrambledVector.size(); ++i) {
      for (int j = 1; j < scrambledVector.size() - i; ++j) {
         int *leftVal = &scrambledVector.at(j - 1);
         int *rightVal = &scrambledVector.at(j);
         if (*leftVal < *rightVal) {
            swapValues (*leftVal, *rightVal);
         }
      }
   }
   return;
}

int main() {
   vector<int> userVector = createVector();
   sortVector (userVector);
   printVector (userVector);
   return 0;
}
