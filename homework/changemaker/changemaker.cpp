#include <iostream>

using namespace std;

int main()
{
	int numDollars = 0;
	int numCents = 0;
	int numPennies = 0;
	int numNickels = 0;
	int numDimes = 0;
	int numQuarters = 0;

	cout << "Enter dollars: ";
	cin >> numDollars;

	cout << "Enter cents: ";
	cin >> numCents;

	//Calculates the number of quarters then finds the remainder of coins left
	numQuarters = numCents / 25;
	numCents %= 25;
	numDimes = numCents / 10;
	numCents %= 10;
	numNickels = numCents / 5;
	numCents %= 5;
	numPennies = numCents;

	//For every dollar we assume 4 quarters
	numQuarters += 4 * numDollars;
	cout << "Pennies: " << numPennies << endl;
	cout << "Nickels: " << numNickels << endl;
	cout << "Dimes: " << numDimes << endl;
	cout << "Quarters: " << numQuarters << endl << endl;

	int totalCoins = numQuarters + numDimes + numNickels + numPennies;
	cout << "Total coins used: " << totalCoins << endl;
}