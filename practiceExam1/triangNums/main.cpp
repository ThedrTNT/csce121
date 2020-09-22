#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

bool isTriangular(unsigned int n) {
	for (unsigned int i = 3; i < n; ++i) {
		if (((i - 2) * (i - 1) * i) == n) {
			return true;
		}
	}
	return false;
}

int main() {
	int num = 0;
	cout << "Enter number to check isTriangular: ";
	cin >> num;
	if(isTriangular(num)) {
		cout << num << " is triangular!" << endl;
	}
	else {
		cout << num << " is not triangular!" << endl;
	}
}