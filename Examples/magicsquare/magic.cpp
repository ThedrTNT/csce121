#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxSize = 9;

int loadMagicSquare(int magicSquare[maxSize][maxSize], int maxSize, ifstream& inData) {
  int size = 0;
  inData >> size;
  if (size > maxSize) {
    throw runtime_error("Not enough slots for magic square");
  }
  // Fill cells of square
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      inData >> magicSquare[row][col];
    }
  }
  return size;
}

void printMagicSquare(int magicSquare[maxSize][maxSize], int size) {
  for (int i=0; i<size; ++i) {
    for (int j=0; j<size; ++j) {
      cout << magicSquare[i][j] << "\t";
    }
    cout << endl;
  }
}

bool isMagicSquare(int magicSquare[maxSize][maxSize], int size) {
  int magicSum = 0;
  //check first diagonal to get magicSum
  for (int i = 0; i < size; ++i) {
    magicSum += magicSquare[i][i];
  }

  //Second diagonal
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += magicSquare[i][size-1-i];
  }
  if (sum != magicSum) {
    return false;
  }

  //check columns
  for (int col = 0; col < size; ++col) {
    sum = 0;
    for (int row = 0; row < size; ++row) {
      sum += magicSquare[row][col];
    }
    if (sum != magicSum) {
      return false;
    }
  }

  for (int row = 0; row < size; ++row) {
    sum = 0;
    for (int col = 0; col < size; ++col) {
      sum += magicSquare[row][col];
    }
    if (sum != magicSum) {
      return false;
    }
  }

  return true;
}

int main() {
  string filename;
  cout << "Input filename: ";
  cin >> filename;
  ifstream inMagic{filename};
  if (!inMagic.is_open()) { // if not open
    cout << "Unable to open file: " << filename << endl;
    return 1;
  }
  
  // define 2d array
  int magicSquare[maxSize][maxSize];
  
  // load 2d array
  //  - things to consider later... problems with data in file
  //           -- too many, not enough, invalid datatype
  
  int size;
  try {
    size = loadMagicSquare(magicSquare, maxSize, inMagic);
  }
  catch (runtime_error exc) {
    cout << exc.what() << endl;
    return 1;
  }
  
  // print out 2d array
  printMagicSquare(magicSquare, size);
  
  // check if it is a magic square
  if (isMagicSquare(magicSquare, size)) {
    cout << "is magic square" << endl;
  }
  else {
    cout << "is not magic square" << endl;
  }
  // output results
}