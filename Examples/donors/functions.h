  
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int loadArrays(std::string filename, double donations[], int numDonors[], 
                std::string names[], int maxSize);
void printArrays(double donations[], int numDonors[], std::string names[], 
                int size, double max, double min);
int max(double nums[], int size);
int min(double nums[], int size);
double max(int nums[], int size);
double min(int numbs[], int size);                

#endif