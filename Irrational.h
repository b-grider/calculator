#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"


class Irrational{
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
    Number* Add(string);
    Number* addPi(Number* num);
    Number* subtractPi(Number* num);
    Number* multiplyPi(Number* num);
    Number* addE(Number* num);
    Number* subtractE(Number* num);
    Number* multiplyE(Number* num);
};
#endif
