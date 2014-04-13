#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"


class Irrational: public Number {
private:
    string coefficient;
    string PI;
    string e;
    string exponent;
    string typeofIrrational;
public:
    Irrational();
    Irrational(string);
    ~Irrational();
    string getExponent();
    Number* Add(string);
    Number* add(Number* num);
    Number* subtract(Number* num);
    Number* multiply(Number* num);
};
#endif
