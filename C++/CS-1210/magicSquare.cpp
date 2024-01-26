/*********************************************************
* Summary: This program takes in a NxN square from the user, where N is 
*          an input from the user. It then checks to see if this square is
*          a magic square. This means that it must include all integers from
*          1 to N*N, and the sums of each row, column, and diagonal must equal
*          the same value.
*
* Author:  Christopher Reed  
* Created: October 2023
*
********************************************************/

#include <iostream>
#include <iomanip> // Used to display user-defined square.

using namespace std;

int main() {
   
   int squareSize;

   // Gathers N (squareSize) from user input.
   cout << "How many rows/columns are in your square?" << endl;
   cin >> squareSize;
   
   // Tells how many numbers are in the matrix.
   int squareArea = squareSize * squareSize;
   int userSquare[squareSize][squareSize];
   
   // Initializes an array to true to indicate missing values.
   bool absentVariables[squareArea];
   for (int i = 0; i < squareArea; ++i) {
      absentVariables[i] = true;
   }

   // Gathers a number of individual values equal to squareArea.
   cout << "\nPlease enter the " << squareArea
        << " values of your magic square from left-right, top-bottom." << endl;

   for (int i = 0; i < squareSize; ++i) {
      for (int j = 0; j < squareSize; ++j) {
         cin >> userSquare[i][j];
      }
   }

   // Returns user-defined square.
   cout << "User's square:" << endl;   
   for (int i = 0; i < squareSize; ++i) {
      for (int j = 0; j < squareSize; ++j) {
         cout << setw(5) << userSquare[i][j];
      }
      cout << endl;
   }
         
   // Determine if all numbers [1, squareArea] inclusive are present.
   for (int i = 0; i < squareSize; ++i) {
      for (int j = 0; j < squareSize; ++j) {
         if ((userSquare[i][j] > 0) && (userSquare[i][j] <= squareArea)) {
            // Indicate that the current value is present.
            int currentValue = userSquare[i][j];
            absentVariables[currentValue - 1] = false;
         }

         // Out of bound number is present.
         else {
            cout << "\nAll numbers 1 to " << squareArea << " not present."
                 << "\n\nThe given matrix is not a magic square."
                 << "\nNot all expected numbers are present." << endl;

            return 0;
         }
      }
   }
   
   //Determine there are no repeats.
   for (int i = 0; i < squareArea; ++i) {
      if (absentVariables[i]) {
         cout << "\nAll numbers 1 to " << squareArea << " not present."
              << "\n\nThe given matrix is not a magic square."
              << "\nNot all expected numbers are present." << endl;

         return 0;
      }
   }

   cout << "\nAll numbers 1 to " << squareArea << " present." << endl;

   /* Create a universal sum to compare all lines to by finding the sum of the
      first row. */
   int universalSum = 0;
   for (int j = 0; j < squareSize; ++j) {
      universalSum += userSquare[0][j];
   }

   // Determine if row sums are equal.
   cout << "Row Check:" << endl;
   for (int i = 0; i < squareSize; ++i) {
      int rowSum = 0;
      for (int j = 0; j < squareSize; ++j) {
         rowSum += userSquare[i][j];
      }
      
      cout << "   Row " << i << " sum:  " << rowSum << endl;
      if (rowSum != universalSum) {
         cout << "The given matrix is not a magic square."
              << "\nRow sums differ." << endl;
         
         return 0;
      }
   }
   
   // Determine if column sums are equal.
   cout << "Column Check:" << endl;
   for (int i = 0; i < squareSize; ++i) {
      int columnSum = 0;
      for (int j = 0; j < squareSize; ++j) {
         columnSum += userSquare [j][i];
      }

      cout << "   Column " << i << " sum:  " << columnSum << endl;
      if (columnSum != universalSum) {
         cout << "The given matrix is not a magic square."
              << "\nColumn sums differ." << endl;

         return 0;
      }
   }

   // Determine if diagonal sums are equal.
   cout << "Diagonal Check:" << endl;
   int diagonalSum0 = 0;
   int diagonalSum1 = 0;
   for (int i = 0; i < squareSize; ++i) {
      diagonalSum0 += userSquare[i][i];
      diagonalSum1 += userSquare[i][squareSize - 1 - i];
   }         
            
   cout << "   Diagonal 0 sum:  " << diagonalSum0 << endl;
   cout << "   Diagonal 1 sum:  " << diagonalSum1 << endl;
   if (diagonalSum0 != diagonalSum1) {
      cout << "The given matrix is not a magic square."
           << "\nDiagonal sums differ." << endl;
      
      return 0;
   }
   
   // Passed all tests.
   cout << "\nThe given matrix is a magic square." << endl;

   return 0;
}
