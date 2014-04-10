#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"


class Irrational{
private:
string PI;
string e;
string typeofIrrational;
public:
Irrational(string typeofIrrational);
~Irrational();
Number* Add(string typeofIrrational);
};
#endif	/* IRRATIONAL_H */

