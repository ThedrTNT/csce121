#include <cmath>
#include <iostream>
#include "Stack.h"

using std::cout, std::endl;

// add element to the top of Stack s
// if Stack s is full, resize the underlying array
void push(Stack& s, double element){
	if(s.length + 1 > s.capacity) {
		double* newArr = new double[s.length * 2];
		for (int i = 0; i < s.length; ++i) {
			newArr[i] = s.A[i];
			//cout << "new: " << newArr[i] << "\t initial: " << s.A[i] << endl;
		}
		s.A = newArr;
		s.capacity = s.length * 2;

	}
	s.length++;
	//cout << "pre add: " << s.A[s.length - 1] << endl;
	s.A[s.length - 1] = element;
	//cout << "post add: " << s.A[s.length - 1] << endl;
}

// remove and return the element on top of Stack s
// if Stack s is empty, return NAN
double pop(Stack& s){
	if(s.length == 0) {
		return NAN;
	}
	s.length--;
	double element = s.A[s.length];
	s.A[s.length] = 0;
	return element;
}

// OPTIONAL
// return but do not remove the element on top of Stack s
double peek(const Stack s){
	double element = s.A[s.length - 1];
	return element;
}

void printArray(Stack& s) {
	for (int i = 0; i < s.length; ++i)
	{
		cout << "Index: " << i << " = " << s.A[i] << endl;
	}
}