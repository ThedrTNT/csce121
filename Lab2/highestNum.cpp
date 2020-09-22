#include <iostream>

using namespace std;
int main()
{
	int highestNum = 0;
	int currentNum = 0;

	cin >> highestNum;
	currentNum = highestNum;

	while(currentNum != 0)
	{
		if(currentNum > highestNum)
		 highestNum = currentNum;
		cin >> currentNum;
	}

	if (highestNum == 0)
	{
		 cout << "empty" << endl;
	}
	else
	{
		cout << highestNum << endl;
	}
}