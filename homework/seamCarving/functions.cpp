#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
  int* returnArry = new int[length];
  for (int i = 0; i < length; ++i) {
    returnArry[i] = 0;
  }
  return returnArry;
}

void deleteSeam(int* seam) {
  delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
  ifstream inFile(filename);

  if(!inFile.is_open()) {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }

  char fileType[3];
  inFile >> fileType;
  if ((toupper(fileType[0]) != 'P') || (fileType[1] != '3')) {
    cout << "Error: type is " << fileType << " instead of P3" << endl;
    return false;
  }

  int w = 0;
  inFile >> w;
  if (inFile.fail()) {
    cout << "Error: read non-integer value";
    return false;
  }
  if (w != width) {
    cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
    return false;
  }
  int h = 0;
  inFile >> h;
  if (inFile.fail()) {
    cout << "Error: read non-integer value";
    return false;
  }
  if (h != height) {
    cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
    return false;
  }

  int maxColorVal = 0;
  inFile >> maxColorVal;
  if (inFile.fail()) {
    cout << "Error: read non-integer value";
    return false;
  }
  if (maxColorVal != 255) {
    cout << "Error: file is not using RGB color values" << endl;
  }

  int red = 0, blue = 0, green = 0;
  for (int col = 0; col < height; ++col) {
    for (int row = 0; row < width; ++row) {
      inFile >> red;
      if (inFile.fail()) {
        if (inFile.eof()) {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value";
        return false;
      }
      inFile >> green;
      if (inFile.fail()) {
        if (inFile.eof()) {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value";
        return false;
      }
      inFile >> blue;
      if (inFile.fail()) {
        if (inFile.eof()) {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value";
        return false;
      }

      if (red > 255 || red < 0) {
        cout << "Error: invalid color value " << red << endl;
        return false;
      }
      if (green > 255 || green < 0) {
        cout << "Error: invalid color value " << green << endl;
        return false;
      }
      if ( blue > 255 || blue < 0) {
        cout << "Error: invalid color value " << blue << endl;
        return false;
      }

      Pixel p = {red, green, blue};
      image[row][col] = p;
    }
  }

  int test = 0;
  inFile >> test;
  if (inFile.good()) {
    cout << "Error: too many color values" << endl;
    return false;
  }

  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
  cout << "Outputting image..." << endl;
  // declare/define and open output file stream
  ofstream outFile(filename);
  // check if output stream opened successfully
  if (!outFile.is_open()) {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }
  // output preamble
  outFile << "P3" << endl;
  outFile << width << " ";
  outFile << height << endl;
  outFile << "255" << endl;
  // output pixels
  for (int col = 0; col < height; ++col) {
    for (int row = 0; row < width; ++row) {
      Pixel p = image[row][col];
      outFile << p.r << endl;
      outFile << p.g << endl;
      outFile << p.b << endl;
    }
  }
  outFile.close();
  return true;
}

int energy(Pixel** image, int x, int y, int width, int height) { 
  int xEnergy = 0;
  int leftX = x - 1;
  int rightX = x + 1;

  if (x == 0) {
    leftX = width - 1;
  }
  if (x == width - 1) {
    rightX = 0;
  }

  Pixel leftPix = image[leftX][y];
  Pixel rightPix = image[rightX][y];

  int red = abs(leftPix.r - rightPix.r);
  int blue = abs(leftPix.b - rightPix.b);
  int green = abs(leftPix.g - rightPix.g);

  xEnergy = pow(red, 2) + pow(blue, 2) + pow(green, 2);

  int yEnergy = 0;
  int topY = y - 1;
  int bottomY = y + 1;

  if (y == 0) {
    topY = height - 1;
  }
  if (y == height - 1) {
    bottomY = 0;
  }

  Pixel topPix = image[x][topY];
  Pixel bottomPix = image[x][bottomY];

  red = abs(topPix.r - bottomPix.r);
  blue = abs(topPix.b - bottomPix.b);
  green = abs(topPix.g - bottomPix.g);

  yEnergy = pow(red, 2) + pow(blue, 2) + pow(green, 2);
  int energy = xEnergy + yEnergy;
  return energy;
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  seam[0] = start_col;
  int currentCol = start_col;
  int leftEnergy = 0;
  int centerEnergy = 0;
  int rightEnergy = 0;
  int totalEnergy = energy(image, currentCol, 0, width, height);
  for (int i = 1; i < height; ++i) {
    if (currentCol != 0) { 
      leftEnergy = energy(image, currentCol - 1, i, width, height);
    } else {
      leftEnergy = -1;
    }
    centerEnergy = energy(image, currentCol, i, width, height);
    if (currentCol != width - 1) {
      rightEnergy = energy(image, currentCol + 1, i, width, height);
    } else {
      rightEnergy = -1;
    }

    if ((centerEnergy <= rightEnergy && leftEnergy == -1) || (centerEnergy <= leftEnergy && rightEnergy == -1) || (centerEnergy <= leftEnergy && centerEnergy <= rightEnergy)) {
      seam[i] = currentCol;
      totalEnergy += centerEnergy;
      continue;
    }
    if (rightEnergy != -1 && rightEnergy <= centerEnergy && (rightEnergy <= leftEnergy || leftEnergy == -1)) {
      currentCol++;
      seam[i] = currentCol;
      totalEnergy += rightEnergy;
      continue;
    }
    if (leftEnergy != -1 && leftEnergy <= centerEnergy && (leftEnergy <= rightEnergy || rightEnergy == -1)) {
      currentCol--;
      seam[i] = currentCol;
      totalEnergy += leftEnergy;
      continue;
    }
  }
  return totalEnergy;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  seam[0] = start_row;
  int currentRow = start_row;
  int leftEnergy = 0;
  int centerEnergy = 0;
  int rightEnergy = 0;
  int totalEnergy = energy(image, currentRow, 0, width, height);
  for (int i = 1; i < width; ++i) {
    if (currentRow != 0) { 
      leftEnergy = energy(image, currentRow - 1, i, width, height);
    } else {
      leftEnergy = -1;
    }
    centerEnergy = energy(image, currentRow, i, width, height);
    if (currentRow != height - 1) {
      rightEnergy = energy(image, currentRow + 1, i, width, height);
    } else {
      rightEnergy = -1;
    }

    if ((centerEnergy <= rightEnergy && leftEnergy == -1) || (centerEnergy <= leftEnergy && rightEnergy == -1) || (centerEnergy <= leftEnergy && centerEnergy <= rightEnergy)) {
      seam[i] = currentRow;
      totalEnergy += centerEnergy;
      continue;
    }
    if (rightEnergy != -1 && rightEnergy <= centerEnergy && (rightEnergy <= leftEnergy || leftEnergy == -1)) {
      currentRow++;
      seam[i] = currentRow;
      totalEnergy += rightEnergy;
      continue;
    }
    if (leftEnergy != -1 && leftEnergy <= centerEnergy && (leftEnergy <= rightEnergy || rightEnergy == -1)) {
      currentRow--;
      seam[i] = currentRow;
      totalEnergy += leftEnergy;
      continue;
    }
  }
  return totalEnergy;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  int* seam = createSeam(height);
  int minEnergy = loadVerticalSeam(image, 0, width, height, seam);
  int minSeam = 0;

  for (int i = 1; i < width; ++i) {
    int test = loadVerticalSeam(image, i, width, height, seam);
    if (test < minEnergy) {
      minEnergy = test;
      minSeam = i;
    }
  }
  loadVerticalSeam(image, minSeam, width, height, seam);
  return seam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  int* seam = createSeam(width);
  int minEnergy = loadHorizontalSeam(image, 0, width, height, seam);
  int minSeam = 0;

  for (int i = 1; i < height; ++i) {
    int test = loadHorizontalSeam(image, i, width, height, seam);
    if (test < minEnergy) {
      minEnergy = test;
      minSeam = i;
    }
  }
  loadHorizontalSeam(image, minSeam, width, height, seam);
  return seam;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
  for (int col = 0; col < height; ++col) {
    Pixel temp = image[verticalSeam[col]][col];
    for (int row = verticalSeam[col]; row < width - 1; ++row) {
      image[row][col] = image[row + 1][col];
    }
    image[width - 1][col] = temp;
  }
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
  for (int row = 0; row < width; ++row) {
    Pixel temp = image[row][horizontalSeam[row]];
    for (int col = horizontalSeam[row]; col < height - 1; ++col) {
      image[row][col] = image[row][col + 1];
    }
    image[row][height - 1] = temp;
  }
}
