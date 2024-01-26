/*********************************************************
* Summary: Takes in a user-provided string and determine if it is a valid
*          integer. Displays whether or not the string is a valid integer,
*          and if so, displays it as an integer with no commas.
*          A valid integer is one which is both non-negative and has either
*          no commas or commas which are properly placed after every third
*          digit.
*
* Author: Christopher Reed
* Created: 21 September 2023
*
********************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
   const char COMMA = ',';
   const int COMMA_PLACEMENT = 4;
   string runningInt = "";
   string userString;
   int numberOfCommas = 0;
   bool validInt = true;
   int finalInt;
   
   cin >> userString;
   const int INT_LENGTH = userString.size();

   for (int i = 0; i < INT_LENGTH; ++i) {
      
      int commaValue = (INT_LENGTH - i) % COMMA_PLACEMENT;
      if (!isdigit(userString[i])) {
         if ((userString[i] == COMMA) && (commaValue == 0)) {
            if ((i == (INT_LENGTH - 1)) || (i == 0)) {
               validInt = false;
            }
            ++numberOfCommas;
         }
         else {
            validInt = false;
            break;
         }
      }
         
      else {
         runningInt += userString[i];
         if ((numberOfCommas > 0) && (commaValue == 0)) {
            validInt = false;
            break;
         }
      }
   }

   int correctNumberOfCommas = (runningInt.size() - 1)/3;
   if ((numberOfCommas > 0) && (numberOfCommas != correctNumberOfCommas)) {
      validInt = false;
   }
   
   if (validInt) {
      finalInt = stoi(runningInt);
      cout << "yes ";
   }
   else {
      finalInt = 0;
      cout << "no ";
   }

   cout << finalInt << endl;

   return 0;
}
