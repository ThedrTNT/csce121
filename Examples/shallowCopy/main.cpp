#include <iostream>

using namespace std;

void loadAry(int vals[], int size, int multiplier) {
  for (int i=0; i<size; ++i) {
    vals[i] = (i+1)*multiplier;
  }
}

void printAry(int vals[], int size) {
  cout << "values" << endl;
  for (int i=0; i<size; ++i) {
    cout << vals[i] << endl;
  }
}

int main() {
  int a=7;
  int b=11;
  int size1 = 3;
  int* ary1 = new int[size1];
  loadAry(ary1, size1, size1);
  int size2 = 4;
  int* ary2 = new int[size2];
  loadAry(ary2, size2, size2);
  int size3 = 2;
  int*ary3 = new int[size3];
  loadAry(ary3, size3, size3);
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  printAry(ary1, size1);
  printAry(ary2, size2);
  printAry(ary3, size3);
  
  
  b = a;
  b++;
  
  
  // deep copy 
  delete[] ary3;
  ary3 = new int[size1];
  for (int i=0;i<size1; ++i) {
    ary3[i] = ary1[i];
  }
  size3 = size1;
  
  ary3[0] = -1;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  printAry(ary1, size1);
  printAry(ary2, size2);
  printAry(ary3, size3);
  
  ary2 = ary1; // shallow copy
  
  ary2[0] = -1;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  printAry(ary1, size1);
  printAry(ary2, size2);
  printAry(ary3, size3);
}