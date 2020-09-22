#include <iostream>
#include "picture_hanging.h"

using std::cin, std::cout, std::endl;

int main () {
	int len = 0;
	cin >> len;
	if (cin.fail()) {
		cout << "invalid input" << endl;;
		return 1;
	}
	int* numArr = new int[len];
	for (int i = 0; i < len; ++i) {
		cin >> numArr[i]; 
		if (cin.fail()) {
			cout << "invalid input" << endl;
			return 1;
		}
	}

	int* testArr = copy(numArr, len);
	size_t newLen = len;
	removeDuplicates(testArr, newLen);
	cout << "sequence uses " << newLen << " nails" << endl;

	cout << "sequence is ";
	if (!isStable(numArr, len)) {
		cout << "not ";
	}
	cout << "stable" << endl;

	cout << "sequence is ";
	if (!isCorrect(numArr, len)) {
		cout << "not ";
	}
	cout << "correct" << endl;


	delete[] testArr;
	delete[] numArr;
}
