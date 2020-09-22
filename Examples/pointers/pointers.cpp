#include <iostream>

using namespace std;

void printReverse(int ary[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		cout << ary[i] << endl;
	}
}

int main() {
	int i = 7;
	int* j = &i; //int *j = &i

	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	cout << "*j: " << *j << endl;

	*j = 11;

	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	cout << "*j: " << *j << endl;

	int ary[3] {1, 2, 3};

	for(int i = 0; i < 3; ++i){
		cout << "ary[" << i << "]: " << ary[i] << endl;
		cout << "*(ary+" << i << "): " << *(ary+i) << endl;
	}

	printReverse(ary, 3);
}