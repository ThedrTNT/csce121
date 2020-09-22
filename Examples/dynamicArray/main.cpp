#include <iostream>

using namespace std;

void loadArray(int* ary, int n) {
  for (int i = 0; i < n; ++i) {
    cin >> ary[i];
  }
}

void printArray(const int* ary, int n) {
  cout << "values " << endl;

  for (int i = 0; i < n; ++i) {
    cout << ary[i] << endl;
    //ary[i] = i;
  }
}

int main() {
  
  cout << "enter size ";
  int size;
  cin >> size;
  
  int* nums = new int[size];

  loadArray(nums, size);
  printArray(nums, size);

  cout << "enter new size ";
  int newSize;
  cin >> newSize;

  // create new array
  int* temp = new int[newSize];

  // copy old values to new values;
  for (int i = 0; i < size; ++i) {
    temp[i] = nums[i];
  }

  for (int i = size; i < newSize; ++i)
  {
    temp[i] = rand()%25;
  }

  // delete memory
  delete[] nums;

  //update original array
  nums = temp;
  size = newSize;

  temp = nullptr;



  int otherNums[2];
  int otherSize = 2;

  loadArray(otherNums, otherSize);
  printArray(otherNums, otherSize);

  delete[] nums;
}