#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	cout << "Enter numbers 0 < a <= b <= 10000: ";
	cin >> a >> b;
	
	if(is_valid_range(a, b)) {
		int validNums = count_valid_numbers(a, b);
		cout << "There are " << validNums << " valid numbers between " 
			<< a << " and " << b << endl;
	} else {
		cout << "Invalid input" << endl;
	}
}