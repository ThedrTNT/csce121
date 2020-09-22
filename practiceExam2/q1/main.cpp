#include <iostream>

using std::cout, std::cin, std::endl;

void findSum (int n, int* A, int k) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (A[i] + A[j] == k) {
				cout << A[i] << " " << A[j] << endl;
				return;
			}
		}
	}
	cout << "none" << endl;
}

int main() {
	int n = 0;
	cin >> n;

	int k = 0;
	cin >> k;

	int* A = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	findSum(n, A, k);
}