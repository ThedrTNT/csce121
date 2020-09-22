#include <iostream>

using std::cout, std::endl;

int countNum(int nums[], int num, int size) {
	int count = 0;
	for (int i = 0; i <size; ++i) {
		if (num == nums[i]) {
			count++;
		}
	}
	return count;
}
 
int main() {
	int nums[] {1,3,4,3,3,4,5,6,7,7,9};
	int size = 11;

	for (int i = 1; i <= 9; ++i) {
		int count = countNum(nums, i, size);
		cout << i << " appears " << count << " times." << endl;
	}
}