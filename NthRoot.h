#ifndef NTHROOT_H
#define NTHROOT_H
#include "Number.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class NthRoot{
private:
Number* num;
Number* root;
public:
NthRoot(Number* num, Number* root);
~NthRoot();
Number* nrt(Number* num, Number root);
};
#endif	/* NTHROOT_H */

