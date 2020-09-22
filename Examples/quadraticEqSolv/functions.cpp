#include <iostream>
#include <math.h>
#include "functions.h"

using namespace std;


void outputEquation(double a, double b, double c)
{
	if (a != 0)
	{
		cout << a << "x^2 ";
		outputTerm(b);
		cout << "x ";
	}
	else
	{
		cout << b << "x ";
	}
	outputTerm(c);
	cout << " = 0" << endl;	
}

void outputTerm(double num)
{
	if (num >= 0)
	{
		cout << "+ " << num;
	}
	else
	{
		cout << "- " << (-1 * num);
	}
}

void processLinear(double a, double b, double c)
{
	if (b == 0)
	{
		if (c == 0)
		{
			cout << "x is all real numbers" << endl;
		}
		else
		{
			cout << "cannot determine roots" << endl;
		}
	}
	else
	{
		double x = -c/b;
		cout << "x = " << x << endl;
	}
}

void processQuadratic(double a, double b, double c)
{
	double disc = b*b - 4*a*c; //discriminant
	if (disc < 0)
	{
		processImaginary(a, b, c, disc);
	}
	else
	{
		processReal(a, b, c, disc);
	}
}

void processImaginary(double a, double b, double c, double disc)
{
	disc = -1 * disc;
	double realPart = -b / (2 * a);
	double img1 = sqrt(disc) / (2 * a);
	double img2 = -img1;
	double chkReal = a * realPart * realPart - a * img1 * img1 + b * realPart + c;
	double chkImg = -2 * a * realPart * img1 - b * img1;
	if (fabs((chkReal + chkImg)) > 0.000000000000001)
	{
		cout << "didn't work" << endl;
		cout << "chkReal" << chkReal << endl;
		cout << "chkImg" << chkImg << endl;
	}


	cout << "x = " << realPart << " ";
	outputTerm(img1);
	cout << "i" << endl;
	cout << "x = " << realPart << " ";
	outputTerm(img2);
	cout << "i" << endl;
}

void processReal(double a, double b, double c, double disc)
{
	
}