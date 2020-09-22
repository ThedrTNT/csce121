#include <iostream>
#include <cmath>

using std::pow;
using std::cout, std::endl;

int fromOctalToDecimal (int* octal, int n) {
	int sum = 0;
	int power = n - 1;
	for (int i = 0; i < n; ++i) {
		sum += octal[i] * pow(8, power);
		power--;
	}
	return sum;
}

int main() {
	int n = 4;
	int octal[] = {1, 0, 0, 1};

	cout << fromOctalToDecimal(octal, n) << endl;
}