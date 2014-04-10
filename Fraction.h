#ifndef FRACTION_H_
#define FRACTION_H_
#include "Number.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Fraction {
private:
	double numerator;
	double denominator;
public:
	Fraction(string);
	Fraction(double, double);
	//Fraction operator+(Fraction&);
	//Fraction operator-(Fraction&);
	//Fraction operator*(Fraction&);
	//Fraction operator/(Fraction&);
};
#endif
