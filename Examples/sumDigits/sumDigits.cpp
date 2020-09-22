#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	cout << "Enter number: ";
	cin >> num;

	while (num > 0)
	{
		int digit = 0;
		digit = num % 10;
		sum += digit;
		num /= 10;
		cout << digit;
		if (num > 0)
			cout << " + ";
	}

	cout << " = " << sum << endl;
}