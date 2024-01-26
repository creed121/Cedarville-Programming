/**************************************
 * Author:  Christopher Reed
 * Created: January 2024
 * Description: Takes a provided file (of pre-collected bits) from the 
 *              command line and creates a queue of these bits. 
 *              Takes this queue and uses base64Conversion.cpp to interpret
 *              the hidden message.
**************************************/

#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include "base64Conversion.h"

using namespace std;

int main(int argc, char **argv) {
   const int LENGTH_OF_BINARY_STRING = 6;
   
   ifstream inFS;   
   inFS.open(argv[1]);
   if (!inFS.is_open()) {
      cout << "Error opening." << endl;
      return 1;
   }
   
   queue<char> fileTextQueue;
   while (!inFS.fail() && !inFS.eof()) {
      char currentBit;
      inFS >> currentBit;
      fileTextQueue.push(currentBit);
   }

   if (!inFS.eof()) {
      cout << "Error reading." << endl;
      inFS.close();
      return 1;
   }
   inFS.close();

   int lengthOfMessage;
   string secretMessage = "";
   cout << "How many characters are in the message?" << endl;
   cin >> lengthOfMessage;

   for (int i = 0; i < lengthOfMessage; ++i) {
      // currentBinaryString is an int because switch statements do not work for strings
      int currentBinaryString = 0;
      for (int i = 0; i < LENGTH_OF_BINARY_STRING; ++i) {
         if (i != 5) {
            currentBinaryString += pow(fileTextQueue.front(), 5 - i);
         }
         else {    // Avoid 0^0
            currentBinaryString += fileTextQueue.front();
         }
         fileTextQueue.pop();
      }
      secretMessage.push_back(base64Conversion(currentBinaryString));
   }
   cout << "The message is:\n" << secretMessage << endl;

   return 0;
}
