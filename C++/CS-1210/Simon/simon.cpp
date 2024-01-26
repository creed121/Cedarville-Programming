/***************************************
* Summary: Play a maximum of 15 rounds of the game "Simon," by taking user
*          input and comparing it to a random, hidden, predetermined sequence.
*          Each round users must match a set number of characters displayed
*          briefly before being hidden. The number of characters corresponds to
*          the current round number. A message is displayed to the user when
*          they either win or lose. A user wins after completing the entire
*          sequence, which can be as long as 15 characters.
*
* Author: Christopher Reed (with template code provided
*         by Cedarville Univerity professors until line 52)
* 
* Created: September 2023
*
***************************************/
#include <iostream>                     // for I/O
#include <cstring>                      // for strlen()
#include <cstdlib>                      // for random numbers
#include <unistd.h>                     // for sleep()
#include "ZyLab.h"                      // for ZyLab Setup
using namespace std;

int main(int argc, char **argv) {

   const int DEFAULT_NUMBER_OF_ROUNDS = 15;
   int       numRounds = DEFAULT_NUMBER_OF_ROUNDS;

   // if a command line argument is given, use that string to init the
   // "random" sequence and set the number of rounds to play the game
   if (argc == 2) {
      numRounds = strlen(argv[1]);
   }

   string    s;                         // A string used to pause the game
   char      c;                         // The player's typed characters
   char     *seq = new char[numRounds]; // Sequence of numRounds colors to match
   char      colors[] = "RGBY";         // Allowable colors
   bool      lost = false;              // Indicates whether we win or lose
   int       round;                     // Indicates the current round

   // Initialize random number generator
   srand(time(0));

   // Determine the random color sequence using either argv[1] or
   // randomly determined letters from 'R', 'G', 'B', and 'Y'
   for (int j = 0; j < numRounds; j++) {
      seq[j] = (argc == 2) ? argv[1][j] : colors[rand() % 4];
   }

   // Wait until the player is ready
   cout << "Welcome to Simon, press enter to play .... ";
   getline(cin, s, '\n');

   char userChars[numRounds];           // C-string to hold user input

   // Run the game for numRounds
   for (int i = 0; i < numRounds; ++i) {
      round = i + 1;
      system(string("clear")); // Clears screen

      //Output current sequence
      cout << endl << "Simon says:  ";
      for (int j = 0; j < round; ++j) {         
         cout << seq[j] << flush;
         sleep(1);
         cout << "\010." << flush;
      }
      cout << endl;

      // Request and collect user input
      cout << "Please enter " << round << " character";
      if (i != 0) {
         cout << 's';                   // Don't print s for single character
      }
      cout << " to match:  ";
      cin >> userChars;

      // Compare each character of input to the sequence
      for (int j = 0; j < round; ++j) {
         userChars[j] = toupper(userChars[j]);
         if ((userChars[j] != seq[j]) || (strlen(userChars) != round)) {
            lost = true;
            break;
         }

      }

      cout << endl;

      // Escapes if game is lost
      if (lost) {
         break;
      }
   }
   
   // Lost Scenario
   if (lost) {
      cout << "Aww, you lost." << endl << "The correct sequence was:  ";
      for (int i = 0; i < round; ++i) {
         cout << seq[i];
      }
      cout << endl;
   }
   // Win Scenario
   else {
      cout << "Congratulations, you win!!" << endl;
   }

   return 0;
}
