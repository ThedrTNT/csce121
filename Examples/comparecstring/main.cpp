#include <iostream>

using std::cout, std::endl;

int compare(char wd1[], char wd2[]) {
	int idx = 0;
	while (wd1[idx] != '\0' && wd2[idx] != '\0') {
		if (wd1[idx] < wd2[idx]) {
			return -1;
		}
		else if (wd2[idx] < wd1[idx]) {
			return 1;
		}
		idx++;
	}
	if (wd1[idx] == wd2[idx]) {
		return 0;
	}
	if (wd1[idx] == '\0') {
		return -1;
	}
	return 1; 
}

int main() {
	char wd1[] = "Hello";
	char wd2[] = "Hel";

	int result = compare(wd1, wd2);
	if (result == 0) {
		cout << "equal" << endl;
	}
	else if (result < 0) {
		cout << wd1 << " is less" << endl;
	}
	else {
		cout << wd2 << " is less" << endl;
	}
}