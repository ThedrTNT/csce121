/*
DADA function definitions
*/
#include <cmath>
#include "dada.h"

int amax(const double x[], const unsigned int len) {
	if (len == 0) {
		return -1;
	}
	double max = fabs(x[0]);
	int index = 0;
	for (unsigned int i = 1; i < len; ++i) {
		double test = fabs(x[i]);
		if (test > max) {
			max = test;
			index = i;
		}
	}
    return index;
}

double asum(const double x[], const unsigned int len) {
	double sum = fabs(x[0]);
	for (unsigned int i = 1; i < len; ++i) {
		sum += fabs(x[i]);
	}
    return sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
	for (unsigned int i = 0; i < len; ++i) {
		y[i] += a * x[i];
	}    
}

void copy(const double src[], double dest[], const unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
		dest[i] = src[i];
	}  
}

double dot(const double x[], const double y[], const unsigned int len) {
	double sum = 0;
	for (unsigned int i = 0; i < len; ++i) {
		sum += x[i] * y[i];
	}
    return sum;
}

double norm2(const double x[], const unsigned int len) {
	double sum = pow(x[0], 2);
	for (unsigned int i = 1; i < len; ++i) {
		sum += pow(x[i], 2);
	}
    return sqrt(sum);
}

void scale(const double a, double x[], const unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
		x[i] *= a;
	}  
}

void swap(double x[], double y[], const unsigned int len) {
    double tempArr[len];
    for (unsigned int i = 0; i < len; ++i) {
    	tempArr[i] = x[i];
    	x[i] = y[i];
    	y[i] = tempArr[i];
    }
}
