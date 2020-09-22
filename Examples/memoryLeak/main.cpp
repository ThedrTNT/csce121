#include <iostream>

using namespace std;

void doStuff() {
	int* k = new int(12);
}

int main() {
	int* i = new int(7);

	i = new int(11);

	doStuff();
}