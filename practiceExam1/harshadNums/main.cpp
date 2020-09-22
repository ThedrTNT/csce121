#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

bool isHarshad(unsigned int n, unsigned int b) {
	int numCheck = n;
	int sum = 0;
	while(numCheck > 0) {
		sum += numCheck % b;
		numCheck /= b;
	}
	if(n % sum == 0) {
		return true;
	}
	return false;
}

int main() {
	int num = 0;
	int base = 10;
	cout << "Enter number to check isHarshad: ";
	cin >> num;
	cout << "Enter base of number: ";
	cin >> base;
	if(isHarshad(num, base)) {
		cout << num << " is harshad!" << endl;
	}
	else {
		cout << num << " is not harshad!" << endl;
	}
}