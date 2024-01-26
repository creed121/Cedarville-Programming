/*********************************************************
* Forsaken Code: Return if you dare!
* Summary: Uses a quick sort algorithm to sort a vector provided by the user.
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

//vector<int> createVector () {
   
void printVector (const vector<int> & toPrintVector, int vecLength) {
   for (int i = 0; i < vecLength; ++i) {
      cout << toPrintVector[i] << ',';
   }
   cout << endl;
   return;
}
void swapValues (int & firstVal, int & secondVal) {
   int holderVariable = firstVal;
   firstVal = secondVal;
   secondVal = holderVariable;
}
void partialSort (vector<int> & scrambledVector, int partStart, int partEnd) {
   if (partStart < partEnd) {            // Return size 1 vectors
      int subVectorLength = (partEnd - partStart + 1);
      int pivotIndex = subVectorLength / 2;     // Pivot in center
      int leftIndex = partStart - 1;
      int rightIndex = partStart;
      vector
cout << leftIndex << rightIndex << endl;
      int pivot = scrambledVector[pivotIndex];
      // Partition smaller and larger sides
      while (leftIndex != rightIndex) {
         int *leftValue = &scrambledVector[leftIndex];
         int *rightValue = &scrambledVector[rightIndex];
         if (*leftValue > pivot) {
            ++leftIndex;
cout << "lMore: " << leftIndex << endl;
         }
         if (*rightValue < pivot) {
               ++rightIndex;
cout << "rMore: " << rightIndex << endl;
         }
          {
            swapValues (*leftValue, *rightValue);
cout << "swap: " << *leftValue << ':' << *rightValue << endl;
         }
      }
   
   
      pivotIndex = rightIndex - 1;
      swapValues (scrambledVector[rightIndex], scrambledVector[pivotIndex]);
printVector (scrambledVector, scrambledVector.size());
cout << "retry: " << pivotIndex << rightIndex << partStart << partEnd << endl;
      partialSort (scrambledVector, partStart, pivotIndex - 1);
      partialSort (scrambledVector, pivotIndex + 1, partEnd);
   }

   return;
}
void sortVector (vector<int> & scrambledVector) {
   // Immediate call is to be able to recurse properly
   partialSort (scrambledVector, 0, scrambledVector.size() - 1);
   return;
}
int main() {
   int userVectorLength;
   vector<int> userVector;

   cin >> userVectorLength;
   for (int i = 0; i < userVectorLength; ++i) {
      int newestValue;
      cin >> newestValue;
      userVector.push_back(newestValue);
   }
   printVector (userVector, userVectorLength);
   sortVector (userVector);
   printVector (userVector, userVectorLength);
   return 0;
}
