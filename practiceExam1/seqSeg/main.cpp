#include <iostream>

using namespace std;

int main() {
	int segments = 1;
	int num = 0;
	int length = 0;
	cout << "Enter the sequence length: ";
	cin >> length;

	cin >> num;
	for (int i = 1; i < length; ++i)
	{
		int testNum = 0;
		cin >> testNum;
		if (testNum != num)
		{
			segments++;
			num = testNum;
		}
	}
	cout << "Segments: " << segments << endl;
}