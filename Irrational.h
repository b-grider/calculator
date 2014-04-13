#ifndef IRRATIONAL_H
#define IRRATIONAL_H
#include "Number.h"

using namespace std;

class Irrational: public Number{
private:
    string coefficient;
    string PI;
    string e;
    string exponent;
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

   // ~Irrational();
   /* Number* Add(string);
    Number* addPi(Number* num);
    Number* subtractPi(Number* num);
    Number* multiplyPi(Number* num);
    Number* addE(Number* num);
    Number* subtractE(Number* num);
    Number* multiplyE(Number* num);*/
};
#endif
