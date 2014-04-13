#ifndef ADD_H
#define  ADD_H
#include <iostream>
#include <string>
#include <exception>
#include"Number.h"

using namespace std;

class Add {

private:
	Number* left;
	Number* right;
	Number* answer;
public:
	Add();
	Add(Number* left, Number* right);
	Number* getanswer();

};
#endif
