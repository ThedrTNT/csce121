#include <cstdlib>
#include <cmath>
#include <iostream>
#include "pi.h"

using std::sqrt;

double approx_pi(unsigned seed, unsigned n) {
    // seed the random number generator
    srand(seed);

    // TODO(student):
    // simulate the dart-throwing process
    double dartHits = 0;
    for (unsigned int i = 0; i < n; ++i) {
    	double x = static_cast<double>(rand()) / RAND_MAX;
    	double y = static_cast<double>(rand()) / RAND_MAX;
    	if ((pow(x,2) + pow(y,2)) <= 1) {
    		dartHits++;
    	}
    }
    // estimate the area of the quadrant
    double quadArea = dartHits / n;
    // estimate the value of pi
    double pi = quadArea * 4;
    std::cout << dartHits << std::endl;
    // return the estimated value of pi
    return pi;
}
