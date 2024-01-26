/*********************************************************
* Summary: Examines a string for how many times a user-declared character
*          appears with case sensitivity. Displays the number of matches
*          along with the character searched for.
*
* Author: Christopher Reed
* Created: 20 September 2023
*
********************************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {

   char comparedChar;
   string examinedString;
   int numberOfMatches = 0;

   cin >> comparedChar;
   getline(cin, examinedString);

   for (int i = 0; i < examinedString.size(); ++i) {
      if (examinedString[i] == comparedChar) {
         ++numberOfMatches;
      }
   }

   cout << numberOfMatches << ' ' << comparedChar;
   if (numberOfMatches != 1) {
      cout << "\'s";
   }
   cout << endl;

   return 0;
}
