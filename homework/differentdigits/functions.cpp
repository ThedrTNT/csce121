#include <iostream>
#include "functions.h"

using namespace std;

bool is_valid_range(int a, int b) {
	return (a > 0 && a <= b && b <= 10000);
}

int count_digit_occurrences(int number, int digit) {
	int testDigit = 0;
	int count = 0;
	do {
		testDigit = number % 10;
		if (testDigit == digit) {
			//cout << "Digit " << digit << " occured in " << number << endl;
			count++;
		}
		number /= 10;
		//cout << "testDigit = " << testDigit << endl;
	} while (number > 0);
	return count;
}

bool has_repeated_digits(int number) {
	int testDigit = 0;
	do {
		testDigit = number % 10;
		if (count_digit_occurrences(number, testDigit) > 1) {
			//cout << testDigit << " is repeated in " << number << endl;
			return true;
		}
		number /= 10;
	} while (number > 0);
	//cout << "No repeated digits in " << number << endl;
	return false;
}

int count_valid_numbers(int a, int b) {
	int count = 0;
	if(is_valid_range(a, b)) {
		for (int i = a; i <= b; ++i) {
			if (!has_repeated_digits(i)) {
				count++;
			}
		}
	}
	return count;
}

