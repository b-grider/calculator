#ifndef LOG_H
#define LOG_H
#include "Number.h"
#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using namespace std;
class Log : public Number {
private:
	double base;
	double number;
public:
	Log(string);
	Log(string, string);
	Log(double, double);
	//Will this generalize and be compatible with all number types? Log of a log solved?
	//Log(Number a, Number b) : base(a), pure(b) {}
	string logb(double, double);
	Number* add(Number*);
	Number* subtract(Number*);
	Number* multiply(Number*);
	Number* divide(Number*);

};



#endif
