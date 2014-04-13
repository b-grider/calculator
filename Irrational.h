#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"

using namespace std;

class Irrational: public Number{
private:
    string PI;
    string e;
    string typeofIrrational;
public:
    Irrational();
    Irrational(string);
    //~Irrational();
    //Number* Add(string);
    /*string addSubtractPi();
    string multiplyPi();			Sorry, But what is this?
    string addSubtractE();
    string multiplyE();*/
	Number* add(Number*);
	Number* subtract(Number*);
	Number* multiply(Number*);
	Number* divide(Number*);
};
#endif
