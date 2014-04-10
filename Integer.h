#ifndef INTEGER_H_
#define INTEGER_H_
#include <iostream>
#include <string>
#include <exception>
#include "Number.h"

using namespace std;
class Integer : public Number {
private:
	int i;
public:
	Integer(string num);
};
#endif
