/*********************************************************
* Summary: Outputs the number of days in February in any
*          valid user-provided year, by calculating leap years.
*
* Author:  Christopher Reed
* Created: October 2023
*
* Source of Gregorian and Julian Calendar Information:
*        https://en.wikipedia.org/wiki/Julian_calendar
*
********************************************************/

#include <iostream>

using namespace std;

int daysInFeb (int userYear) {
   const int FOUR_HUNDRED_YEARS = 400;
   const int ONE_HUNDRED_YEARS = 100;
   const int FOUR_YEARS = 4;
   int monthLength = 29;

   if ((userYear % FOUR_HUNDRED_YEARS) != 0) {
      if ((userYear % ONE_HUNDRED_YEARS) != 0) {
         if ((userYear % FOUR_YEARS) != 0) {
            monthLength = 28;
         }
      }
      else {
         monthLength = 28;
      }
   }

   return monthLength;
}
void printOutput (int userYear, int febLength) {
   const int CREATION_OF_GREGORIAN_CALENDAR = 1582;
   const int CREATION_OF_JULIAN_CALENDAR = -45;
   if (userYear >= CREATION_OF_GREGORIAN_CALENDAR) {
      cout << userYear << " has " << febLength << " days in February." << endl;
   }
   else if (userYear >= CREATION_OF_JULIAN_CALENDAR) {
      cout << userYear << " has " << febLength << " days in February." << endl;
      cout << "The Gregorian Calendar was invented in 1582 A.D. The major "
           << "change between the Gregorian calendar and the Julian calndar "
           << "is that the Gregorian calendar has an additional stipulation "
           << "for leap years. If it is the turn of a century when the year "
           << "is not divisible by 400, a leap year does not occur; if the "
           << "year is divisible by 400, then a leap year does occur. For "
           << "this reason, the number of days in February may be calculable, "
           << "but should not be considered reliable." << endl;
   }
   else {
      cout << "The Julian Calendar was adopted in 45 B.C., and with it the "
           << "concept of leap years. Before this time, the lengths of months "
           << "varied from what is the current standard. Additionally, leap "
           << "years were not measured. Beyond this, the month of February "
           << "did not exist. Therefore, the number of days in the month of "
           << "February is incalculable." << endl;
   }
   return;
}

int main() {
   int userYear;
   cin >> userYear;
   
   int februaryLength = daysInFeb (userYear);
   printOutput (userYear, februaryLength);

   return 0;
}
