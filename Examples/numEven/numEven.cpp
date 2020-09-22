#include <iostream>

using namespace std;

int main() 
{
	int num = 1;
	int cnt = 0;

	while (num != 0) 
	{
		if (num % 2 == 0)
		{
			cnt++;
		}
		cin >> num;
	}
	cout << "Num even " << cnt << endl;
}