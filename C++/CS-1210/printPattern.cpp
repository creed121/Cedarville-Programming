/*********************************************************
* Summary: Takes in a user-defined sequence and length.
*          Outputs n characters of the sequence where n is the row #.
*
* Author:  Christopher Reed
* Created: November 2023
*
********************************************************/

#include <iostream>
#include <string>

using namespace std;

void printPattern(int rows, string stringToPrint, string & sequence, int nextChar = 1) {

   cout << stringToPrint << endl;
   if (rows == 1) {
      return;   
   }

   printPattern (--rows, stringToPrint + 
                sequence.at(nextChar % sequence.size()),
                sequence, nextChar + 1);
   return;
}

int main() {
   string sequence = "";
   int    numRows = 0;

   // cout << "How many rows in your pattern? ";
   cin  >> numRows;

   // cout << "What characters should be used in the pattern? ";
   cin  >> sequence;

   printPattern(numRows, sequence.substr(0,1), sequence);

   return 0;
}
