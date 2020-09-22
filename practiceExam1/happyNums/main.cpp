#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

bool isHappy(unsigned int n) {
	int tester = n;
	int sum = 0;
	while(tester != 4 && tester != 1) {
		//cout << "Testing Number: " << tester << endl;
		while(tester > 0) {
			sum += pow(tester % 10, 2);
			tester /= 10;
			//cout << "\t number: " << tester << " \t sum : " << sum << endl;
			//cout << "sum : " << sum << endl;
		}
		tester = sum;
		sum = 0;
	}
	if(tester == 4) {
		return false;
	}
	else {
		return true;
	}

}

int main() {
	int num = 0;
	cout << "Enter number to check isHappy: ";
	cin >> num;
	if(isHappy(num)) {
		cout << num << " is happy!" << endl;
	}
	else {
		cout << num << " is not happy!" << endl;
	}
}