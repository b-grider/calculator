#ifndef ADD_H
#define  ADD_H
#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Add {

private:
	Number* left;
	Number* right;
public:
	Add();
	Add(Number* left, Number* right);
	Number* answer();

}
#endif
