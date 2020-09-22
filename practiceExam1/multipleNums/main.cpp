#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

void printMultiples(unsigned int n, unsigned int a, unsigned int b) {
	unsigned int numsPrinted = 0;
	unsigned int count = 1;
	int aMult = 0;
	int bMult = 0;
	while (numsPrinted < n) {
		aMult = a * count;
		bMult = b * count;
		if(aMult == bMult) {
			cout << aMult << " ";
			numsPrinted++;
		}
		else {
			if (numsPrinted < n) {
				cout << aMult << " ";
				numsPrinted++;
			}
			if (numsPrinted < n) {
				cout << bMult << " ";
				numsPrinted++;
			}
		}
		count++;
	}
}

int main() {
	int num = 0;
	cout << "Enter number of multiples to print: ";
	cin >> num;
	int a = 0;
	cout << "Enter number for a: ";
	cin >> a;
	int b = 0;
	cout << "Enter number for b: ";
	cin >> b;
	printMultiples(num, a, b);
}