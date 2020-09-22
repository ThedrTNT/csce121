#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

unsigned int find(int, const int[], unsigned int);

bool find(const int[], unsigned int);

unsigned int removeNumber(int, int[], unsigned int);

unsigned int removeNumber(int[], unsigned int);

void insertNumber(int, int*&, unsigned int&, unsigned int&);

void insertNumber(int*&, unsigned int&, unsigned int&);

bool isSorted(const int[], unsigned int);

void printNumbers(const int[], unsigned int);

int* makeArray(unsigned int);

void loadNumbers(int*&, unsigned int&, unsigned int&);

void loadNumbers(std::istream&, int*&, unsigned int&, unsigned int&);

int getInteger(std::string, int, int);

#endif