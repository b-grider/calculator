#include <iostream>
#include <string>
#include <sstream>
#include "Number.h"
#include "Log.h"
#include "Fraction.h"
#include "Integer.h"
#include "Polynomial.h"
#include "Irrational.h"

using namespace std;
#ifndef HELPERFUNCTIONS_H
#define	HELPERFUNCTIONS_H
class HelperFunctions {
private:
    string str;
public:

    HelperFunctions(string);
    bool isPolynomial(string);
    bool isIrrational(string);
    bool isInteger(string);
    bool isFraction(string);
    bool isLog(string);
};
#endif
