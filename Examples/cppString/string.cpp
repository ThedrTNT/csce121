#include <iostream>
#include <string>

using namespace std;

int main() {
	string name {"Ryan"};
	cout << name << endl;
	name += " Parker";
	cout << name << endl;
	cout << name.length() << endl;
	cout << name.at(name.length() / 2) << endl;
}