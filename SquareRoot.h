#ifndef SQUAREROOT_H
#define SQUAREROOT_H
#include "Number.h"


class SquareRoot{
private:
Number* num;
public:
SquareRoot(Number* num);
~SquareRoot();
Number* sqrt(Number* num);
};
#endif	/* SQUAREROOT_H */

