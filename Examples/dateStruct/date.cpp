#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isValid(Date d) {
	if (d.year < 1) {
		return false;
	}
	if (d.month < 1 || d.month > 12) {
		return false;
	}
	if (d.day < 1) {
		return false;
	}
	switch (d.month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 11:
			if (d.day > 30) {
				return false;
			}
			break;
		case 2:
			if (d.day > 28) {
				return false;
			}
			break;
		default:
			if (d.day > 31) {
				return false;
			}
			break;
	}
	return true;
}

int main() {
	Date d {2020, 02, 03};
	cout << d.year << "-" << d.month << "-" << d.day << endl;
	if (isValid(d)) {
		cout << "Valid date" << endl;
	}
	else {
		cout << "Invalid date" << endl;
	}
}