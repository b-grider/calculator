#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H
#include "Number.h"


class Polynomial: public Number{
    private:
        string poly;
    public:
        Polynomial(string);
        //~Polynomial();
        //string Polynomial(Number* num1,Number num2); //What was this for?
		Number* add(Number*);
		Number* subtract(Number*);
		Number* multiply(Number*);
		Number* divide(Number*);
};
#endif	