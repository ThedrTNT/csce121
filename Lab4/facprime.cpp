#include <iostream>

using namespace std;

int main() {
	long factorial = 0;
	long factor = 1;
	cout << "Enter n >= 0: ";
	cin >> factorial;
	long tempFact = 1;

	int largestPrimeFact = 2;
	if (factorial == 0 || factorial == 1) {
		cout << "The number is 0! and 1! No prime factors" << endl;
	}
	else {

		while (tempFact < factorial) {
			factor++;
			tempFact *= factor;
		}
		if (tempFact == factorial) {
			cout << "The number is " << factor << "!";
			for (int i = factor; i > 0; i--) {
				for (int j = 2; j < i; j++) {
					if (i % j != 0) {
						largestPrimeFact = i;
						break;
					}
					else {
						break;
					}
				}
				if (i == largestPrimeFact) {
					break;
				}
			}
			cout << " The largest prime factor is " << largestPrimeFact << endl;
		}
		else {
			cout << "Not a factorial" << endl;
		}
	}
}