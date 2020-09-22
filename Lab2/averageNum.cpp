#include <iostream>

using namespace std;

int main()
{
	double sum = 0;
	double numVals = 0;
	double userIn = 0;

	cin >> userIn;

	while (userIn != 0)
	{
		sum += userIn;
		numVals++;
		cin >> userIn;
	}

	if (numVals == 0)
	{
		cout << "empty" << endl;
	}
	else
	{
		double avg = sum / numVals;
		cout << avg << endl;
	}
}