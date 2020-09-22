#include <string>
#include "functions.h"

using namespace std;

int main() {
	const int maxCapacity = 10;
	double donations[maxCapacity];
	int numDonors[maxCapacity];
	string names[maxCapacity];
	int size = loadArrays("donors.txt", donations, numDonors, names, maxCapacity);
	printArrays(donations, numDonors, names, size, donations[max(donations, maxCapacity)], donations[min(donations, maxCapacity)]);
}