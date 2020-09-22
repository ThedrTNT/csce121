#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

int main() {
	int* i = new int(7); //get memory from the heap

	*i = 11; //dereference
	cout << *i << endl; //dereference

	int size;
	cin >> size;
	//int ary[3];
	int* ary = new int[size]; //allocate

	*(ary + 0) = 7; //deref the hard way
	cout << ary[0] << endl; //deref the easy way

	//Date p;
	//Date* d = &p;
	Date* d = new Date; //allocate

	(*d).year = 2020; //dereference the hard way
	cout << d -> year << endl; //dereference the easy way


	Date* days = new Date[2];
	(*(days + 1)).year = 2020;
	cout << days[1].year << endl;

	delete i; //deallocate
	delete[] ary; //deallovate array
	delete d;
	delete[] days;

	i = nullptr;
	ary = nullptr;
	d = nullptr;
	days = nullptr;
}
