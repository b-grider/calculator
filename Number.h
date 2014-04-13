#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Number {
    private:
        string num;
    public:
        Number();
        Number(string);
        //virtual void simplify() = 0;
        //virtual string toString() = 0;
		virtual Number* add(Number*)=0;
		virtual Number* subtract(Number*)=0;
		virtual Number* multiply(Number*)=0;
		virtual Number* divide(Number*)=0;
        //virtual Number* simplify(Number*) = 0;

};
#endif
