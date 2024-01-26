/*********************************************************
* Summary: Searches a pre-populated file for a user provided Bible reference.
*          If the reference does not exist, then an error message will be 
*          returned to the user. If it does exist, the program will return the
*          verse number and verse to both the user and an output file.
*
* Author:  Christopher Reed
* Created: October 2023
*
********************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

string getUserBook ();
string convertNumberedBooks (string book);
string entireToUpper (string userInput);
string convertSong (string book);
string convertProverb (string book);
bool isPsalm (string book);
bool checkBook (string book, string line);
bool checkChapter (string chapter, string line);
bool checkVerse (string verse, string line); 
void printReference (string book, string chapter, string verse);

int main() {

   ifstream inFS;
   inFS.open ("OT.txt");

   if (!inFS.is_open()) {
      cout << "Error opening OT.txt." << endl;
      return -1;
   }

   string userBook = getUserBook();

   string userChapter;
   if (!isPsalm (userBook)) {
      cout << "Please enter the chapter number you are searching for." << endl;
   }
   else {
      cout << "Please enter the psalm number you are searching for." << endl;
   }
   cin >> userChapter;

   string userVerse;
   cout << "Please enter the verse number you are searching for." << endl;
   cin >> userVerse;

   bool foundBook = false;
   bool foundChapter = false;
   bool foundVerse = false;
   string currentLine;

   while (!foundBook && !inFS.eof()) {
      getline (inFS, currentLine);
      foundBook = checkBook (userBook, currentLine);
   }
   if (!foundBook) {
      inFS.close();
      cout << userBook << " does not exist in the Old Testament." << endl;
      return 1;
   }

   const string THE_BOOK_OF_UNIQUE_IDENTIFIER = "THE";
   while (!foundChapter && !inFS.eof()) {
      getline (inFS, currentLine);
      if (checkBook (THE_BOOK_OF_UNIQUE_IDENTIFIER, currentLine)) {
         break;     //Short circuits if the next book is reached.
      }
      foundChapter = checkChapter (userChapter, currentLine);
   }
   if (!foundChapter) {
      inFS.close();
      cout << "Chapter " << userChapter << " does not exist in " << userBook
           << endl;
      return 1;
   }

   if (!isPsalm (userBook)) {
      const string CHAPTER_UNIQUE_IDENTIFIER = "PT";
      while (!foundVerse && !inFS.eof()) {
         getline (inFS, currentLine);
         if (checkChapter (CHAPTER_UNIQUE_IDENTIFIER, currentLine)) {
            break;  //Short circuits if the next chapter is reached.
         }
         foundVerse = checkVerse (userVerse, currentLine);
      }
   }
   else {
      const string PSALM_UNIQUE_IDENTIFIER = "LM";
      while (!foundVerse && !inFS.eof()) {
         getline (inFS, currentLine);
         if (checkChapter (PSALM_UNIQUE_IDENTIFIER, currentLine)) {
            break;  //Short circuits if the next Psalm is reached.
         }
         foundVerse = checkVerse (userVerse, currentLine);
      }
      if (!foundChapter) {
         inFS.close();
         cout << "Psalm " << userChapter << " does not exist." << endl;
         return 1;
      }
   }
   
   if (!foundVerse) {
      inFS.close();
      cout << "Verse " << userVerse << " does not exist in " << userBook
           << ' ' << userChapter << '.' << endl;
      return 1;
   }

   inFS.close();

   printReference(userBook, userChapter, userVerse);
   cout << currentLine << endl;

   ofstream outFS;
   outFS.open("verses.txt", ofstream::ate | ofstream::app);  
   if (!outFS.good()) {
      cout << "Error opening verses.txt." << endl;
      return -1;
   }
      
   outFS << currentLine << endl;
   outFS.close();
   
   return 0;
}

void printReference (string book, string chapter, string verse) {
   cout << book << ' ' << chapter << ':' << verse << endl;
   return;
}

bool checkBook (string book, string line) {
   string upperBook = entireToUpper (book);
   int bookIndex = line.find (upperBook);
   return (bookIndex != string::npos);
}

bool checkChapter (string chapter, string line) {
   const int GET_PAST_VERSES = 3;
   int chapterIndex = line.find (chapter, GET_PAST_VERSES);
   return (chapterIndex != string::npos);
}

bool checkVerse (string verse, string line) {
   int verseIndex = line.find (verse);
   return (verseIndex == 0);
}

bool isPsalm (string book) {
   string upperBook = entireToUpper (book);
   if ((upperBook == "PSALMS") || upperBook == ("PSALM")) {
      return true;
   }
   return false;
}

string getUserBook () {
   string userBook; 
   cout << "Please enter the book of the Old Testament you are searching for."
        << endl;
   getline (cin, userBook);
   
   userBook = convertNumberedBooks (userBook);
   userBook[0] = toupper(userBook[0]);

   return userBook;
}

string convertNumberedBooks (string inputBook) {
   const string FIRST_NUMERAL = "I ";
   const string SECOND_NUMERAL = "II";
   const string FIRST_ORDINAL = "1ST ";
   const string SECOND_ORDINAL = "2ND ";
   const string FIRST_SAMUEL_NUMERICAL = "1 S";
   const string SECOND_SAMUEL_NUMERICAL = "2 S";
   const string FIRST_KINGS_NUMERICAL = "1 K";
   const string SECOND_KINGS_NUMERICAL = "2 K";
   const string FIRST_CHRONICLES_NUMERICAL = "1 C";
   const string SECOND_CHRONICLES_NUMERICAL = "2 C";
   string book = entireToUpper (inputBook);

   bool firstFoundNumerical = (book.substr(0, 3) == FIRST_SAMUEL_NUMERICAL ||
                            book.substr(0, 3) == FIRST_KINGS_NUMERICAL ||
                            book.substr(0, 3) == FIRST_CHRONICLES_NUMERICAL);
   bool firstFoundNumeral = book.substr(0, 2) == FIRST_NUMERAL;
   bool firstFoundOrdinal = book.substr(0, 4) == FIRST_ORDINAL;

   bool secondFoundNumerical = (book.substr(0, 3) == SECOND_SAMUEL_NUMERICAL ||
                             book.substr(0, 3) == SECOND_KINGS_NUMERICAL ||
                             book.substr(0, 3) == SECOND_CHRONICLES_NUMERICAL);
   bool secondFoundNumeral = book.substr(0, 2) == SECOND_NUMERAL;
   bool secondFoundOrdinal = book.substr(0, 4) == SECOND_ORDINAL;
   
   bool numFound = (firstFoundNumerical || secondFoundNumerical ||
                    firstFoundNumeral   || secondFoundNumeral   ||
                    firstFoundOrdinal   || secondFoundOrdinal   );
   
   if (!numFound) {
      return inputBook;
   }
   else if (firstFoundNumeral || firstFoundNumerical) {
      inputBook.replace(0, 1, "First");
   }
   else if (secondFoundNumeral) {
      inputBook.replace(0, 2, "Second");
   }
   else if (secondFoundNumerical) {
      inputBook.replace(0, 1, "Second");
   }
   else if (firstFoundOrdinal) {
      inputBook.replace(0, 3, "First");
   }
   else if (secondFoundOrdinal) {
      inputBook.replace(0, 3, "Second");
   }
   return inputBook;
}
   
string entireToUpper (string userInput) {
   for (int i = 0; i < userInput.size(); ++i) {
      userInput[i] = toupper(userInput[i]);
   }
   userInput = convertSong (userInput);
   userInput = convertProverb (userInput);
   return userInput;
}

string convertSong (string book) {
   if (book == "SONG OF SONGS") {
      book = "SONG OF SOLOMON";
   }
   return book;
}

string convertProverb (string book) {
   if (book == "PROVERB") {
      book = "PROVERBS";
   }
   return book;
}
