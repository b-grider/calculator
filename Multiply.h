#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Multiplay
{
private:
	Number* left;
	Number* right;
public:
	Multiply();
	Multiply(Number* left, Number* right);
	Number* answer();
};

#endif



