/*********************************************************
* Summary: Removes non-alphabetic characters from a user-provided input,
*          including spaces.
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>

using namespace std;

string removeNonAlpha (string userString) {
   string alphaString = "";
   for (int i = 0; i < userString.size(); ++i) {
      if (isalpha(userString.at(i))) {
         alphaString.push_back(userString.at(i));
      }
   }

   return alphaString;
}

int main() {
   string inputString;
   getline (cin, inputString);
   cout << removeNonAlpha (inputString) << endl;

   return 0;
}
