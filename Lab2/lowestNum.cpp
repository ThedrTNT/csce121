#include <iostream>

using namespace std;
int main()
{
	int lowestNum = 0;
	int currentNum = 0;

	cin >> lowestNum;
	currentNum = lowestNum;

	while(currentNum != 0)
	{
		if(currentNum < lowestNum)
			lowestNum = currentNum;
		cin >> currentNum;
	}

	if (lowestNum == 0)
	{
		 cout << "empty" << endl;
	}
	else
	{
		cout << lowestNum << endl;
	}
}