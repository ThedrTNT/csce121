#include <iostream>

using namespace std;

void loadAry(int** ary, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ary[i][j] = (i+1)*(j+1);
		}
	}
}

void printAry(int** ary, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << ary[i][j] << endl;
		}
	}
}

int main() {
	int nums[2][3];

	int nums2[2*3];

	int** nums3 = new int*[2];

	for (int i =0; i < 2; ++i) {
		nums3[i] = new int[3];

	}

	for (int i =0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			nums2[i * 3 + j] = (i+1)*(j+1);
		}
	}

	//loadAry(nums, 2, 3);
	//printAry(nums, 2, 3);

	loadAry(nums3, 2, 3);
	printAry(nums3, 2, 3);

}