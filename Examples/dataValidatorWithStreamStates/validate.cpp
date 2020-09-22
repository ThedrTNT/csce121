#include <iostream>
#include <limits>

using namespace std;

int getValidInRange(istream& is, string prompt, int min, int max){
	int num;
	cout << prompt;
	do {
		is.clear(); //resets bits to good state
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		is >> num;
	} while(!is.good() || num < min || num > max);
	return num;
}

int main(){
	int num = getValidInRange(cin, "Enter value from 3 to 8: ", 3, 8);
	cout << "num: " << num << endl;
}