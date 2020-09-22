#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include "functions.h"

using namespace std;

void resizeArray(int*& ary, unsigned int size, unsigned int& capacity) {
  if (capacity == 0) {
    capacity = 1;
  }
  else {
    capacity *= 2;
  }
  
  // make new array
  int* tempary = new int[capacity];
  
  // copy old to new
  for (unsigned int i=0; i<size; ++i) {
    tempary[i] = ary[i];
  }
  
  // avoid memory leak
  delete [] ary;
  
  ary = tempary;
  
  tempary=nullptr;
}

int* makeArray(unsigned int capacity) {
  int* temp = new int[capacity];
  return temp;
}

// we'll update to binary search eventually
unsigned int find(int num, const int nums[], unsigned int size) {
  /*for (unsigned int i=0; i<size; ++i) {
    if (num == nums[i]) {
      return i;
    }
  }*/

  int low = 0;
  int high = size - 1;
  int mid = low + (high - low) / 2;

  while (low <= high) {
    if (nums[mid] == num) {
      return mid;
    }
    if (nums[mid] < num) {
      low = mid + 1;
    }
    if (nums[mid] > num) {
      high = mid - 1;
    }

    mid = low + (high - low) / 2;
  }

  return size;
}

bool find(const int nums[], unsigned int size) {
  cout << "start find (int[], int)" << endl;
  int num = 0;
  num = getInteger("number to find", 0, 0);
  unsigned int index = find(num, nums, size);
  if (index == size) {
    cout << num << " is not on the list" << endl;
    return false;
  }
  cout << "The number " << num << " is at index " << index << endl;
  return true;
}


unsigned int removeNumber(int num, int nums[], unsigned int size) {
  cout << "start removeNumber(int, int[], int)" << endl;
  unsigned int index = find(num, nums, size);
  if (index == size) {
    return size;
  }
  // slide values up
  for (unsigned int i=index+1; i < size; ++i) {
    nums[i-1] = nums[i];
  }
  
  return --size; // -- must be on left
}

unsigned int removeNumber(int nums[], unsigned int size) {
  cout << "start removeNumber(int[], int)" << endl;
  int num = 0;
  num = getInteger("number to remove", 0, 0);
  try {
    size = removeNumber(num, nums, size);
  }
  catch (runtime_error exc) { // note size is not updated if exception thrown
    cout << "Unable to remove number: " << num << endl;
  }
  return size;
}

void insertNumber(int num, int*& nums, unsigned int& size, unsigned int& capacity) {
  cout << "start insertNumber(int, int[], int, int)" << endl;
  if (size+1 > capacity) {
    resizeArray(nums, size, capacity);
  }
  unsigned int i = 0;
  while (i < size && nums[i] < num) {
    ++i;
  }
  // i is index of where to put num
  // slide numbers over
  for (unsigned int j=size; j>i; --j) {
    nums[j] = nums[j-1];
  }
  // insert num
  nums[i] = num;
  
  // update size
  ++size;
}

void insertNumber(int*& nums, unsigned int& size, unsigned int& capacity) {
  cout << "start insertNumber(int[], int, int)" << endl;
  int num = 0;
  num = getInteger("number to add", 0, 0);
  insertNumber(num, nums, size, capacity); // can throw exception
}

bool isSorted(const int nums[], unsigned int size) {
  cout << "start isSorted" << endl;
  for (unsigned int i = 1; i <size; ++i) {
    if (nums[i-1] > nums[i]) {
      return false;
    }
  }
  return true;
}

void loadNumbers(istream& ifs, int*& nums, unsigned int& size, unsigned int& capacity) {
  cout << "start loadNumbers(istream&, int[], int)" << endl;
  // intput numbers from file
  // -- first number is number of elements to read
  // -- check for non-integer input
  // -- check if too many or not enough numbers
  
  // we might need to delete existing array;
  
  size = 0;
  ifs >> size;
  cout << "size: " << size << endl;
  if (!ifs.good()) {
    if (ifs.fail() && !ifs.bad()) { 
      throw runtime_error("size is not valid");
    }
    else {
      throw runtime_error("bad stream or end of file");
    }
  }
  capacity = size;
  nums = makeArray(capacity);
  if (nums == nullptr) {
    throw runtime_error("unable to make array");
  }
  /*
  if (size > capacity) {
    throw runtime_error("Not enough spots for all numbers");
  }*/
  for (unsigned int i=0; i<size; ++i) {
    ifs >> nums[i];
    //cout << "i: " << i << endl;
    //cout << "nums[i] " << nums[i] << endl;
    if (!ifs.good()) {
      if (ifs.eof()) {
        if (i < size-1) {
          throw runtime_error("Not enough numbers.");
        }
      }
      if (ifs.bad()) {
        throw runtime_error("Problem with the stream.");
      }
      if (ifs.fail()) {
        throw runtime_error("Input not an integer.");
      }
      // do stuff
    }
    
  }
  int temp;
  ifs >> temp;
  if (!ifs.fail()) {
    throw runtime_error("Too many numbers.");
  }

  //return size;
}

void loadNumbers(int*& nums, unsigned int& size, unsigned int& capacity) {
  cout << "start loadNumbers(int[], int)" << endl;
  string filename;
  cout << "Input filename: ";
  cin >> filename;
  ifstream ifs {filename};
  if (ifs.is_open()) {
    loadNumbers(ifs, nums, size, capacity); // call overloaded version
  }
  else {
    throw runtime_error("Unable to open file " + filename);
  }
}

void printNumbers(const int* nums, unsigned int size) {
  // print out numbers 10 per row
  if (size == 0) {
    cout << "Empty list" << endl;
    return;
  }
  
  for (unsigned int i=0; i<size; ++i) {
    cout << nums[i];
    if ((i+1)%10 == 0) {
      cout << endl;
    }
    else {
      cout << "\t";
    }
  }
  cout << endl;
}


int getInteger(string label, int min, int max) { 
  // if min and max are equal, do not prompt for a range
  // get value from user repeatedly until input matches requirements
  if (min > max) {
    throw runtime_error("Minimum value must be less than maximum value");
  }
  int num = 0;
  bool inRange = false;
  do {
    // ensure stream is ready to get input if there was a problem last time
    cin.clear(); // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    
    cout << "Please enter " << label;
    if (min != max) {
      cout << " (" << min << " - " << max << ")";
    }
    cout << ": ";
    cin >> num;
    if (min == max) { // all inputs are valid
      inRange = true;
    }
    else {
      inRange = num >= min && num <= max;
    }
  } while (!cin.good() || !inRange); // while input does not match requirements
  return num;
}