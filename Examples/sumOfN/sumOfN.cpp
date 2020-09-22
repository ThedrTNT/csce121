#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	cin >> num;
	for (int i = num; i >= 1; i--)
	{
		sum += i;
	}

	cout << sum << endl;
}