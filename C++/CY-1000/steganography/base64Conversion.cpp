/**************************************
 * Author:  Christopher Reed
 * Created: January 2024
 * Description: Convert a string of 6 binary bits to an alphanumeric character
 *              using a Base64 conversion table, with exceptions below.
 *              111110 = ' '
 *              111111 = '.'
**************************************/
#include <string>

using namespace std;

char base64Conversion (int sixBitBinary) {
   switch (sixBitBinary) {
      case 000000:
         return 'A';
      case 000001:
         return 'B';
      case 000010:
         return 'C';
      case 000011:
         return 'D';
      case 000100:
         return 'E';
      case 000101:
         return 'F';
      case 000110:
         return 'G';
      case 000111:
         return 'H';
      case 001000:
         return 'I';
      case 001001:
         return 'J';
      case 001010:
         return 'K';
      case 001011:
         return 'L';
      case 001100:
         return 'M';
      case 001101:
         return 'N';
      case 001110:
         return 'O';
      case 001111:
         return 'P';
      case 010000:
         return 'Q';
      case 010001:
         return 'R';
      case 010010:
         return 'S';
      case 010011:
         return 'T';
      case 010100:
         return 'U';
      case 010101:
         return 'V';
      case 010110:
         return 'W';
      case 010111:
         return 'X';
      case 011000:
         return 'Y';
      case 011001:
         return 'Z';
      case 011010:
         return 'a';
      case 011011:
         return 'b';
      case 011100:
         return 'c';
      case 011101:
         return 'd';
      case 011110:
         return 'e';
      case 011111:
         return 'f';
      case 100000:
         return 'g';
      case 100001:
         return 'h';
      case 100010:
         return 'i';
      case 100011:
         return 'j';
      case 100100:
         return 'k';
      case 100101:
         return 'l';
      case 100110:
         return 'm';
      case 100111:
         return 'n';
      case 101000:
         return 'o';
      case 101001:
         return 'p';
      case 101010:
         return 'q';
      case 101011:
         return 'r';
      case 101100:
         return 's';
      case 101101:
         return 't';
      case 101110:
         return 'u';
      case 101111:
         return 'v';
      case 110000:
         return 'w';
      case 110001:
         return 'x';
      case 110010:
         return 'y';
      case 110011:
         return 'z';
      case 110100:
         return '0';
      case 110101:
         return '1';
      case 110110:
         return '2';
      case 110111:
         return '3';
      case 111000:
         return '4';
      case 111001:
         return '5';
      case 111010:
         return '6';
      case 111011:
         return '7';
      case 111100:
         return '8';
      case 111101:
         return '9';
      case 111110:
         return ' ';
      case 111111:
         return '.';
      default:
         return '/';
   }
}
