#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"


class Irrational{
private:
    string PI;
    string e;
    string typeofIrrational;
public:
    Irrational();
    Irrational(string);
    ~Irrational();
    Number* Add(string);
    string addSubtractPi();
    string multiplyPi();
    string addSubtractE();
    string multiplyE();
};
#endif
