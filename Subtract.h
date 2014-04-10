#ifndef SUBTRACT_H
#define SUBTRACT_H

class Subtract
{
private:
	Number* left;
	Number* right;
public:
	Subtract();
	Subtract(Number* left, Number* right);
	Number* answer();
};

#endif



