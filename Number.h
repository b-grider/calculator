#ifndef NUMBER_H
#define NUMBER_H
#include "Log.h"
#include "Fraction.h"
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
        /*virtual Number& operator+(Number&)=0;
        virtual Number& operator-(Number&)=0;
        virtual Number& operator*(Number&)=0;
        virtual Number& operator/(Number&)=0;
        virtual Number* simplify(Number*, Number*) = 0;*/

};
#endif
/*class Polynomial : Number {

private:
	string expression;

	Polynomial(string a) : Expression(a) {}

	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator*(Polynomial&);
	Polynomial operator/(Polynomial&);
};

class Irrational : Number {

	Irrational operator+(Irrational&);
	Irrational operator-(Irrational&);
	Irrational operator*(Irrational&);
	Irrational operator/(Irrational&);
};

class Integer : Number {

	private:
		int pure;

	Integer operator+(Integer&);
	Integer operator-(Integer&);
	Integer operator*(Integer&);
	Integer operator/(Integer&);
};*/

/*class Log : Number {

	private:
	double base;
	double pure;

	Log() : base(0), pure(0) {}
	Log(Number a, Number b) : base(a), pure(b) {}			//Will this generalize and be compatible with all number types? Log of a log solved?

	Log operator+(Log&);
	Log operator-(Log&);
	Log operator*(Log&);
	Log operator/(Log&);
};*/

