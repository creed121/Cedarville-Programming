/*********************************************************
* Summary: Converts a user-provided positive integer to a binary list of
*          ones and zeros. Outputs the result. Can optionally be adjusted to
*          other bases by changing the DIVISOR variable.
*
* Author: Christopher Reed
* Created: 20 September 2023
*
********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

   const int DIVISOR = 2;
   const int PLACE_VALUE_ADJUSTER = 10;
   int placeValue = 0;
   int convertedBinary = 0;
   int dividend;
   int remainder;

   cin >> dividend;

   while (dividend > 0) {
      remainder = dividend % DIVISOR;
      dividend /= DIVISOR;
      convertedBinary += (remainder * pow(PLACE_VALUE_ADJUSTER, placeValue));
      ++placeValue;
   }
   
   cout << convertedBinary << endl;

   return 0;
}
