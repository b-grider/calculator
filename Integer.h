#ifndef INTEGER_H_
#define INTEGER_H_
#include <iostream>
#include <string>
#include <exception>
#include "Number.h"
#include <vector>

using namespace std;
class Integer : public Number {
private:

    int i;
public:
    int value;
	Integer(string);
    Integer(int);
    int getValue();
    double getDoubleValue();
    string toString();
    void simplify();
		
	/*Number* add(Number*);
	Number* subtract(Number*);
	Number* multiply(Number*);
	Number* divide(Number*);
*/};
#endif
