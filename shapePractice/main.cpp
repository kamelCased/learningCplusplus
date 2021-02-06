// Assignment: Practice making various shapes with loops
// Author: Kamel Gazzaz
// Date: 02/02/2021
#include <iostream>
using namespace std;

const char ASCII_DIFF = 'A';
const char ASCII_START = 'a';

int main() {

    /* ------------------- 1: Square of hashtags --------------------------*/

    int squareSize;
    cout << "1) Please enter the size of your square: ";
    cin >> squareSize;

    for (int lineCount = 1; lineCount <= squareSize; lineCount++) {
        for (int hashCount = 1; hashCount <= squareSize; hashCount++) {
            cout << "#";
        }
        cout << endl;
    }

    /* ------------------- 2: Right triangle of stars --------------------------*/

    int triangleSize;
    cout << endl << "2) Please enter the size of your triangle: ";
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {
        for (int starCount = 1; starCount <= lineCount; starCount++) {
            cout << "*";
        }
        cout << endl;
    }

    /* ------------------- 3: Right triangle of ordered numbers --------------------------*/

    cout << endl << "3) Please enter the size of your triangle: ";
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << numCount;
        }
        cout << endl;
    }

    /* ------------------- 4: Right triangle of line numbers --------------------------*/

    cout << endl << "4) Please enter the size of your triangle: ";
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << lineCount;
        }
        cout << endl;
    }

    /* ------------------ 5: Right triangle of next number -----------------------------*/

    cout << endl << "5) Please enter the size of your triangle: ";
    cin >> triangleSize;

    for (int lineCount = 1, outputNum = 1; lineCount <= triangleSize; lineCount++) {
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << outputNum << " ";
            outputNum++;
        }
        cout << endl;
    }

    /* ------------------ 6: Pyramid of next number ----------------------------- */
    int pyramidSize;
    cout << endl << "6) Please enter the size of your pyramid: ";
    cin >> pyramidSize;

    for (int lineCount = 1, outputNum = 1; lineCount <= pyramidSize; lineCount++) {
        for (int spaceCount = 0; spaceCount < (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << outputNum << " ";
            outputNum++;
        }
        cout << endl;
    }


    /* ------------------ 7: Pyramid of stars ----------------------------- */

    cout << endl << "7) Please enter the size of your star pyramid: ";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
        for (int spaceCount = 0; spaceCount < (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << "* ";
        }
        cout << endl;
    }

    /* ------------------ 8: Pyramid of line numbers ----------------------------- */

    cout << endl << "8) Please enter the size of your step pyramid: ";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
        for (int spaceCount = 0; spaceCount < (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }
        for (int numCount = 1; numCount <= lineCount; numCount++) {
            cout << lineCount << " ";
        }
        cout << endl;
    }

    /* ------------------ 9: Pyramid of odd star numbers ----------------------------- */

    cout << endl << "9) Please enter the size of your odd star pyramid: ";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
        for (int spaceCount = 0; spaceCount < (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }
        for (int numCount = 1; numCount <= (2 * lineCount - 1); numCount++) {
            cout << "*";
        }
        cout << endl;
    }

    /* ------------------ 10: Floyd's triangle ----------------------------- */

    cout << "10) Enter the size of your Floyd's triangle" << endl;
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {

        int floydsNumber = lineCount;

        for (int numCount = 1; numCount <=lineCount; numCount++, floydsNumber++) {
            cout << floydsNumber % 2;
        }

        cout << endl;
    }

    /* ------------------ 11: diamond ----------------------------- */

    int diamondSize;
    cout << "11) Enter the size of your diamond:" << endl;
    cin >> diamondSize;

    for (int lineCount = 1; lineCount <= diamondSize; lineCount++) {

        for (int spaceCount = 1; spaceCount <= (diamondSize-lineCount)+1; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= 2 * lineCount - 1; starCount++) {
            cout <<"*";
        }

        cout << endl;
    }

    for (int lineCount = diamondSize-1; lineCount > 0; lineCount--) {

        for (int spaceCount = 1; spaceCount <= (diamondSize - lineCount)+1; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= 2*lineCount-1; starCount++) {
            cout <<"*";
        }

        cout << endl;
    }

    /* ------------------ 12: Half numbered triangle ----------------------------- */

    cout << "12) Please enter the size of your triangle:" <<  endl;
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {

        for (int spaceCount = (triangleSize - lineCount); spaceCount > 0; spaceCount--) {
            cout << " ";
        }

        for (int firstHalf = 1; firstHalf <= (2 * lineCount + 1) / 2; firstHalf++) {
            cout << firstHalf;
        }

        for (int secondHalf = (2 * lineCount + 1) / 2 - 1; secondHalf > 0; secondHalf--) {
            cout << secondHalf;
        }

        cout << endl;
    }

    /* ------------------ 13: Lettered Pyramid  ----------------------------- */

    cout << "13) Input the number of Letters (less than 26) in the bases of the Pyramid:\n";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {

        for (int spaceCount = 1; spaceCount <= (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }

        for (int charCount = 0; charCount < 2*lineCount-1; charCount++) {
            char character = charCount + ASCII_DIFF;
            cout << character;
        }

        cout << endl;
    }

    /* ------------------ 14: Half lettered Pyramid  ----------------------------- */

    cout << "14) Input the number of Letters (less than 26) in the bases of the Pyramid:\n";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {

        for (int spaceCount = 1; spaceCount <= 2*(pyramidSize - lineCount)-1; spaceCount++) {
            cout << " ";
        }

        char lastChar;
        for (int charCount = 0; charCount < (2 * lineCount - 1) / 2; charCount++) {
            char character = charCount + ASCII_DIFF;
            cout << character << " ";
            lastChar = character;
        }

        for (char charCount = lastChar - 1; charCount >= ASCII_DIFF; charCount--) {
            cout << charCount << " ";
        }

        cout << endl;
    }

    /* ------------------ 15: Line numbered Pyramid ----------------------------- */

    cout << "15) Please enter the size of your line numbered pyramid:\n";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {

        for (int spaceCount = pyramidSize - lineCount; spaceCount > 0; spaceCount--) {
            cout << " ";
        }

        int lastNum;
        for (int numCount = 1, num = lineCount; numCount <= (2 * lineCount + 1) / 2; numCount++, num++) {
            cout << num;
            lastNum = num;
        }

        for (int numCount = lastNum - 1; numCount >= lineCount; numCount--) {
            cout << numCount;
        }

        cout << endl;
    }

    /* ------------------ 16: Reverse line Pyramid ----------------------------- */

    cout << "16) Please enter the size of your reverse line triangle:" << endl;
    cin >> triangleSize;

    for (int lineCount = 1; lineCount <= triangleSize; lineCount++) {
        for (int numCount = lineCount; numCount <= triangleSize; numCount++) {
            cout << numCount;
        }

        cout << endl;
    }

    /* ------------------ 17: Reverse line right justified triangle ----------------------------- */

    cout << "17) Please enter the size of your reverse line triangle:" << endl;
    cin >> triangleSize;

    for (int lineCount = 0; lineCount < triangleSize; lineCount++) {

        for (int spaceCount = 0; spaceCount <= lineCount; spaceCount++) {
            cout << " ";
        }

        for (int numCount = 1; numCount <= triangleSize - lineCount; numCount++) {
            cout << numCount;
        }

        cout << endl;
    }

    /* ------------------ 18: Lettered right justified triangle ----------------------------- */

    char inputLetter;
    cout << "18) Enter lowercase letter:" << endl;
    cin >> inputLetter;

    for (char lineCount = ASCII_START; lineCount <= inputLetter; lineCount++) {

        for (char spaceCount = lineCount; spaceCount <= inputLetter; spaceCount++) {
            cout << " ";
        }

        for (char charCount = ASCII_START; charCount <= lineCount; charCount++) {
            cout << charCount;
        }

        cout << endl;
    }

    /* ------------------ 19: Letter X ----------------------------- */

    int xSize;
    cout << "19) Please enter the size of your letter X:\n";
    cin >> xSize;

    for (int lineCount = 1; lineCount <= xSize; lineCount++) {
        for (int spaceCount = 1; spaceCount <= lineCount; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <=3; starCount++) {
            cout << "*";
        }

        for (int spaceCount = 0; spaceCount < 2*(xSize - lineCount); spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <=3; starCount++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int lineCount = 1; lineCount <= xSize; lineCount++) {
        for (int spaceCount = 1; spaceCount <= xSize - lineCount; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <=3; starCount++) {
            cout << "*";
        }

        for (int spaceCount = 0; spaceCount < 2*lineCount; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <=3; starCount++) {
            cout << "*";
        }

        cout << endl;
    }

    /* ------------------ 20: Letter V ----------------------------- */

    int vSize;
    cout << "20) Please enter the size of your letter V\n";
    cin >> vSize;

    for (int lineCount = 1; lineCount <= vSize; lineCount++) {
        for (int spaceCount = 1; spaceCount <= lineCount; spaceCount++) {
            cout << " ";
        }

        for (int hashCount = 1; hashCount <=3; hashCount++) {
            cout << "#";
        }

        for (int spaceCount = 0; spaceCount < 2*(vSize - lineCount); spaceCount++) {
            cout << " ";
        }

        for (int hashCount = 1; hashCount <=3; hashCount++) {
            cout << "#";
        }

        cout << endl;
    }

    /* ------------------ 21: Letter A with interior bar ----------------------------- */
    int aSize;
    cout << "21) Please enter the size of your letter A\n";
    cin >> aSize;

    for (int lineCount = 0; lineCount < aSize; lineCount++) {

        for (int spaceCount = 1; spaceCount <= aSize - lineCount; spaceCount++) {
            cout << " ";
        }

        if (lineCount == aSize / 2) {
            for (int horizBar = 1; horizBar <= aSize+2; horizBar++) {
                cout << "*";
            }
        }

        else {
            cout << "*";

            for (int spaceCount = 0; spaceCount < 2*lineCount; spaceCount++) {
                cout << " ";
            }

            cout << "*";

        }
        cout << endl;
    }

    /* ------------------ 22: Letter A with exterior bar ----------------------------- */

    cout << "22) Please enter the size of your letter A\n";
    cin >> aSize;

    for (int lineCount = 0; lineCount < aSize; lineCount++) {

        if (lineCount == aSize / 2) {
            for (int horizBar = 1; horizBar <= aSize+2; horizBar++) {
                cout << "* ";
            }
        }

        else {

            for (int spaceCount = 1; spaceCount <= aSize - lineCount; spaceCount++) {
                cout << " ";
            }
            cout << "*";

            for (int spaceCount = 0; spaceCount < 2*lineCount; spaceCount++) {
                cout << " ";
            }

            cout << "*";

        }
        cout << endl;
    }

    /* ------------------ 23: Powers of 2 pyramid ----------------------------- */

    cout << "23) Please enter the size of your powers of 2 pyramid:\n";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {

        for (int spaceCount = 1; spaceCount <= pyramidSize - lineCount; spaceCount++) {
            cout << " ";
        }

        for (int charCount = 1; charCount < pow(2, lineCount); charCount *= 2) {
            cout << charCount;
        }

        for (int charCount = pow(2, lineCount - 2); charCount > 0; charCount /= 2) {
            cout << charCount;
        }

        cout << endl;
    }

    /* ------------------ 24: Inverted numbered pyramid ----------------------------- */

    cout << "Please enter the size of your inverted numbered pyramid:\n";
    cin >> pyramidSize;

    for (int lineCount = 0; lineCount <= pyramidSize; lineCount++) {
        for (int spaceCount = lineCount; spaceCount > 0; spaceCount--) {
            cout << " ";
        }

        for (int numCount = 1; numCount <= (pyramidSize-lineCount); numCount++){
            cout << numCount;
        }

        for (int numCount = (pyramidSize-lineCount) - 1; numCount > 0; numCount--){
            cout << numCount;
        }

        cout << endl;
    }

    /* ------------------ 25: Barn Door ----------------------------- */
    
    int rows;
    cout << "25) Enter the size of your barn door:\n";
    cin >> rows;

    // Top frame
    for (int lineCount = 1; lineCount <= rows; lineCount++) {
      cout << "#";
    }

    cout << endl;

    int outer_space = 0;
    int inner_space = rows - 4;

    for (int lineCount = 1; lineCount <= rows -2; lineCount++) {
      
      // left frame
      cout << "#";
      
      // left spaces
      for (int spaceCount = 0; spaceCount < outer_space; spaceCount++) {
        cout << " ";
      }
      // left dollars
      cout << "$";

      // not middle row
      if (lineCount != rows / 2) {
        // middle spaces
        for (int spaceCount = 0; spaceCount < inner_space; spaceCount++) {
          cout << " ";
        }
        // right dollars
        cout << "$";
      }

      // right space
      for (int spaceCount = 0; spaceCount < outer_space; spaceCount++) {
        cout << " ";
      }

      // Right frame
      cout << "#";

      // Top half
      if (lineCount < rows / 2) {
        inner_space -= 2;
        outer_space += 1;
      }
      // Bottom half
      else {
        inner_space += 2;
        outer_space -= 1;
      }

      cout << endl;
    }

    // Bottom frame
    for (int lineCount = 1; lineCount <= rows; lineCount++) {
      cout << "#";
    }

    cout << endl;
    
    /* ------------------ 26: Xmas tree ----------------------------- */

    cout << "Input the size of the xmas tree:\n";
    cin >> pyramidSize;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
    
        for (int spaceCount = 1; spaceCount <= (pyramidSize - lineCount)+4; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 0; starCount < 2*lineCount-1; starCount++) {
            cout << '*';
        }

        cout << endl;
    }

    pyramidSize += 2;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
    
        for (int spaceCount = 1; spaceCount <= (pyramidSize - lineCount)+2; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 0; starCount < 2*lineCount-1; starCount++) {
            cout << '*';
        }

        cout << endl;
      }

    pyramidSize += 2;

    for (int lineCount = 1; lineCount <= pyramidSize; lineCount++) {
        
        for (int spaceCount = 1; spaceCount <= (pyramidSize - lineCount); spaceCount++) {
            cout << " ";
        }

        for (int starCount = 0; starCount < 2*lineCount-1; starCount++) {
            cout << '*';
        }

        cout << endl;
    }

    for (int lineCount = 1; lineCount <= pyramidSize/2; lineCount++) {
        
        for (int spaceCount = 0; spaceCount <= double(pyramidSize)/2+1; spaceCount++) {
            cout << " ";
        }

        for (int starCount = 0; starCount <= double(pyramidSize)/2; starCount++) {
            cout << '#';
        }

        cout << endl;
        
    }
    
    /* ------------------ 27: Octagon ----------------------------- */

    
    cout << "27) Please enter the size of your octagon (multiple of 3):" << endl;
    cin >> rows;

    int space = rows/3;
    int middleSpace = space;

    // Top Row
    for (int spaceCount = 0; spaceCount <= space; spaceCount++) {
      cout << "  ";
    }

    for (int hashCount = 0; hashCount <= space; hashCount++) {
      cout << "#  ";
    }
    
    cout << endl;

    // Second Part
    for (int lineCount = 0; lineCount < space; lineCount++) {

      for (int spaceCount = lineCount; spaceCount < space; spaceCount++) {
        cout << "  ";
      }

      cout <<"#";

      for (int spaceCount = middleSpace; spaceCount < rows; spaceCount++) {
        cout << "  ";
      }

      middleSpace -=2;

      cout <<"#";

      cout << endl;

    }

    // Third Part
    for (int lineCount = 0; lineCount <= space; lineCount++) {
      cout <<"#";

      for (int spaceCount = middleSpace; spaceCount < rows; spaceCount++) {
        cout << "  ";
      }

      cout <<"#";

      cout << endl;

    }

    // Fourth Part
    for (int lineCount = 0; lineCount < space; lineCount++) {

      for (int spaceCount = lineCount; spaceCount >= 0; spaceCount--) {
        cout << "  ";
      }

      cout <<"#";

      for (int spaceCount = middleSpace +2; spaceCount < rows; spaceCount++) {
        cout << "  ";
      }

      cout <<"#";

      middleSpace +=2;
      cout << endl;

    }

    // Bottom frame spaces
    for (int spaceCount = 0; spaceCount <= space; spaceCount++) {
      cout << "  ";
    }

    // Bottom frame
    for (int hashCount = 0; hashCount <= space; hashCount++) {
      cout << "#  ";
    }
    cout << endl;
    
    return 0;
}
