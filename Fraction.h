//#ifndef FRACTION_H_
//#define FRACTION_H_
#include "Number.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Fraction : public Number {
private:
	Number* numerator;
	Number* denominator;
public:
	Fraction(string);
	Fraction(double, double);
        Number* getNumerator();
        Number* getDenominator();
	//Fraction operator+(Fraction&);
	//Fraction operator-(Fraction&);
	//Fraction operator*(Fraction&);
	//Fraction operator/(Fraction&);
};
//#endif
