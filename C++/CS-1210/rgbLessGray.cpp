/**************************************
* Summary: This program parses an RGB color code and removes the gray from it
*          by finding the lowest value and subtracting it from all values.
*
* Author: Christopher Reed
* Created: September 2, 2023
*
* Changelog: September 6, 2023: Added Failstate
*            September 8, 2023: Streamlined reduction process
**************************************/
#include <iostream>
using namespace std;

int main() {

   int redValue;
   int greenValue;
   int blueValue;
   int grayValue;

   cin >> redValue;
   cin >> greenValue;
   cin >> blueValue;
   grayValue = 0;

   if ((redValue < 0) || (redValue > 255) || (greenValue < 0) || (greenValue > 255) || (blueValue < 0) || (blueValue > 255)) {
      cout << "Please try again and insert a proper RGB value. RGB values must be integers between 0-255.";
   }
   else {
      if (redValue < greenValue) {

         if (redValue < blueValue) {
            grayValue = redValue;
         }
         else {
            grayValue = blueValue;
         }

      }
      else {
         if (greenValue < blueValue) {
            grayValue = greenValue;
         }
         else {
            grayValue = blueValue;
         }
      }
      redValue -= grayValue;
      greenValue -= grayValue;
      blueValue -= grayValue;
      cout << redValue << ' ' << greenValue << ' ' << blueValue << endl;
   }

   return 0;
}
