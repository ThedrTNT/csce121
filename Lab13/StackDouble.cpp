#include <iostream>
#include <cmath>
#include "StackDouble.h"

StackDouble::StackDouble() {
	A = new double[1];
	capacity = 1;
	length = 0;
}

StackDouble::~StackDouble() {
	delete[] A;
}

void StackDouble::push(double element) {
	if(length + 1 > capacity) {
		double* newArr = new double[length * 2];
		for (int i = 0; i < length; ++i) {
			newArr[i] = A[i];
		}
		A = newArr;
		capacity = length * 2;

	}
	length++;
	A[length - 1] = element;
}

double StackDouble::pop() {
	if(length == 0) {
		return NAN;
	}
	length--;
	double element = A[length];
	A[length] = 0;
	return element;
}