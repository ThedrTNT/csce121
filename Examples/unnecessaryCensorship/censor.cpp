#include <iostream>
#include <fstream>
#include <string>
#include "censorFunctions.h"

using namespace std;

int main() {
	
	// get filenames - for now we will hard code them
	
	// declare/define/open filestreams
  ifstream censorIn("censorwords.txt");
  ifstream textIn("original.txt");
  ofstream textOut("censor.txt");
	
	// make sure all files were opened and give feedback if not
  if (!censorIn.is_open()) {
    cout << "Unable to open censorwords.txt" << endl;
    return 1;
  }

  if (!textIn.is_open()) {
    cout << "Unable to open original.txt" << endl;
    return 1;
  }

  if (!textOut.is_open()) {
    cout << "Unable to open censor.txt" << endl;
    return 1;
  }

  
	// load list of words to censor from file
  string censorWords[10];
  int size = loadWords(censorWords, censorIn, 10);
	
	// print list of censor words to check if we loaded successfully
  printStrings(censorWords, size);
  
  // process files
  processFiles(textIn, censorWords, size, textOut);
}