#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include "functions.h"

using namespace std;

int loadArrays(string filename, double donations[], int numDonors[], 
                string names[], int maxSize) {
	ifstream ifs(filename);
	if (!ifs.is_open()) {
		throw runtime_error("Unable to open file");
	}
	int index = 0;
	while (!ifs.eof() && index < maxSize) {
		string line;
		getline(ifs, line);
		istringstream iss(line);
		double num = 0;
		double sum = 0;
		int count = 0;
		do {
			iss >> num;
			if (iss.good()) {
				sum += num;
				count++;
			}
		} while (iss.good());
		iss.clear();
		string name;
		iss >> name;
		donations[index] = sum / count;
		numDonors[index] = count;
		names[index] = name;
		index++;
	}
	return index;
}

void printArrays(double donations[], int numDonors[], string names[], 
                int size, double max, double min) {
	for (int i = 0; i < size; i++) {
		cout << names[i] << ": " << donations[i] << " (" << numDonors[i] << ") ";
		if (fabs(donations[i]-max) < 0.000000000000001) {
			cout << " - max";
		}
		cout << endl;
	}
}

int max(double nums[], int size) {
	double maxVal = nums[0];
	int maxIndex = 0;
	for (int i = 1; i < size; i++) {
		if (maxVal < nums[i])
		{
			maxVal = nums[i];
			maxIndex = i;
		}
	}
  return maxIndex;
}

int min(double nums[], int size) {
	double minVal = nums[0];
	int minIndex = 0;
	for (int i = 1; i < size; i++) {
		if (minVal > nums[i])
		{
			minVal = nums[i];
			minIndex = i;
		}
	}
  return minIndex;
}

double max(int nums[], int size) {
  return 0;
}

double min(int numbs[], int size) {
  return 0;
}  