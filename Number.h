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
        virtual void simplify() = 0;
        virtual string toString() = 0;
		virtual Number* add(Number*)=0;
		virtual Number* subtract(Number*)=0;
		virtual Number* multiply(Number*)=0;
		virtual Number* divide(Number*)=0;
        //virtual Number* simplify(Number*) = 0;

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

