#include <iostream>
#include <math.h>
#include "functions.h"

using namespace std;

int main ()
{
	double a=0, b=0, c=0;
	cout << "Enter coefficients a, b, and c: ";
	cin >> a >> b >> c;
	outputEquation(a, b, c);
	if (a == 0)
	{
		processLinear(a, b, c);
	}
	else
	{
		processQuadratic(a, b, c);
	}
}
