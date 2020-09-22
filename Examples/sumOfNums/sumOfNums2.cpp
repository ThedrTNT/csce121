#include <iostream>

using namespace std;

int main () 
{
	int num = 0;
	int sum = 0;
	for (int i=0; i<5; ++i)
	{
		cin >> num;
		sum += num;
	}
	cout << "Sum is " << sum << endl;
	return 0;
}