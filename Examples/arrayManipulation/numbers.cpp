#include <iostream>
#include "functions.h"

using namespace std;

void printMenu();

int main() {
  unsigned int capacity = 0;
  int* numbers = nullptr;
  unsigned int size = 0;
  
  char menuChoice = ' '; // selected menu option
  do {
    printMenu();
    cin >> menuChoice;
    switch (toupper(menuChoice)) { // use toupper so user can input upper or lower case choices
      case 'L':
        try {
          loadNumbers(numbers, size, capacity);
        }
        catch (runtime_error exc) {
          cout << exc.what() << endl;
        }
        break;
      case 'P':
        printNumbers(numbers, size);
        break;
      case 'F':
        find(numbers, size);
        break;
      case 'I':
        try {
          insertNumber(numbers, size, capacity);
        }
        catch (runtime_error exc) {
          cout << exc.what() << endl;
        }
        break;
      case 'R':
        try {
          size = removeNumber(numbers,size);
        }
        catch (runtime_error exc) {
          cout << exc.what() << endl;
        }
        break;
      case 'Q': // does nothing but needed or default will execute
        break;
      default:
        cout << endl << "'" << menuChoice << "' is not a valid option'" << endl << endl;
    }
  } while (toupper(menuChoice) != 'Q'); // use toupper so user can input upper or lower case choices
}

/*  Function printMenu
 *  Return value: none
 */
void printMenu() {
  cout << "--------------------------" << endl;
  cout << " 'L': Load numbers from file" << endl;
  cout << " 'P': Print numbers to screen" << endl;
  cout << " 'F': Find number" << endl;
  cout << " 'I': Insert number" << endl;
  cout << " 'R': Remove number" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "--------------------------" << endl;
  cout << endl << "Please enter your choice: ";
}

