/**************************************
* Summary
*
* Author: Christopher Reed
* Created: 8 September 2023
*
**************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {

   string origText;
   string expandedText;
   int choice;

   cout << "Enter text:" << endl;
   getline(cin, origText);
   cout << "You entered: " << origText << endl;

   expandedText = origText;
   
   cout << "Which abbreviation do you want to replace (enter a number)\n";
   cout << "  1. BFF\n  2. IDK\n  3. JK\n  4. TMI\n  5. TTYL\n  6. Quit Program\n  > ";
   cin  >> choice;
   while (choice >= 1 && choice <= 5) {
      string abbr = "";
      string phrase = "";
      int    len = 0;
      bool   abbrPresent = false;
      
      switch (choice) {

         /* Your code goes here */
	 case 1:
            abbr = "BFF";
	    phrase = "best friend forever";
	    len = 3;
	    abbrPresent = true;
	    break;
         case 2:
	    abbr = "IDK";
	    phrase = "I don't know";
	    len = 3;
	    abbrPresent = true;
	    break;
	 case 3:
	    abbr = "JK";
	    phrase = "just kidding";
	    len = 2;
	    abbrPresent = true;
	    break;
	 case 4:
	    abbr = "TMI";
	    phrase = "too much information";
	    len = 3;
	    abbrPresent = true;
	    break;
	 case 5:
	    abbr = "TTYL";
	    phrase = "talk to you later";
	    len = 4;
	    abbrPresent = true;
	    break;
	 default:
	    break;
      }
      
      if (abbrPresent) {
         expandedText.replace(expandedText.find(abbr), len, phrase);
      }
      
      cout << "  > ";
      cin  >> choice;
   }

   cout << endl << "Expanded: " << expandedText << endl;

   return 0;
}
