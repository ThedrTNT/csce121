#ifndef CENSORFUNCTIONS_H
#define CENSORFUNCTIONS_H

#include <string>

// cannot use "using namespace" in header files
//  so you have to use fully qualified names, e.g. std:: string and std::cout

int loadWords(std::string words[], std::ifstream& censorIn, int maxCapacity);
void printStrings(std::string[], int);
void processFiles(std::ifstream&, std::string[], int, std::ofstream&);
std::string tolower(std::string);
std::string replaceString(std::string);

#endif