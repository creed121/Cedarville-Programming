/*********************************************************
* Summary: Converts a user-provided positive integer to a binary string of
*          ones and zeros from LSB to MSB. Outputs the result from MSB to LSB.
*          Can optionally be adjusted to other bases by changing the
*          DIVISOR variable.
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>

using namespace std;

string intToReverseBinary (int dividend) {
   const int DIVISOR = 2;
   string binaryReversed = "";
   while (dividend > 0) {
      int remainder = dividend % DIVISOR;
      binaryReversed += to_string (remainder);
      dividend /= DIVISOR;
   }

   return binaryReversed;
}

string stringReverse (string reverseBin) {
   string convertedBin = "";
   
   for (int i = (reverseBin.size() - 1); i >= 0; --i) {
      convertedBin.push_back(reverseBin[i]);
   }

   return convertedBin;
}

int main() {
   string reverseBinary;
   string properBinary;
   int userInt;
   cin >> userInt;

   if (userInt > 0) {
      reverseBinary = intToReverseBinary (userInt);
      properBinary = stringReverse (reverseBinary);
      cout << properBinary << endl;
   }
   else {
      cout << userInt << " is not a positive integer." << endl;
   }

   return 0;
}
