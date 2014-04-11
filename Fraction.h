//#ifndef FRACTION_H_
//#define FRACTION_H_
#include "Number.h"
#include <iostream>
#include <string>
#include <exception>
#include "Integer.h"

using namespace std;
class Fraction : public Number {
private:
        Integer* numerator;
        Integer* denominator;
        int value;
public:
	Fraction(string);
	Fraction(double, double);
	vector<int> primeFactorization();
        int greatestCommonFactor(Integer*);
        int gcd(int, int);
        Number* getNumerator();
        Number* getDenominator();
	//Fraction operator+(Fraction&);
	//Fraction operator-(Fraction&);
	//Fraction operator*(Fraction&);
	//Fraction operator/(Fraction&);
};
//#endif
