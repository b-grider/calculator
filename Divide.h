#ifndef DIVIDE_H
#define DIVIDE_H
#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Divide
{
private:
	Number* left;
	Number* right;
public:
	Divide();
	Divide(Number* left, Number* right);
	Number* answer();
};

#endif



