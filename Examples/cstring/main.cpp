#include <iostream>

using namespace std;

int main() {
  char texas[] {'T', 'e', 'x', 'a', 's', '\0'}; // ends with a sentinel value
  cout << texas << endl;
  char word[] {"A word"}; // array of size 7
  
  // get size
  int index = 0;
  while (word[index] != '\0') {
    index ++;
  }
  cout << "length is " << index << endl;
  
}