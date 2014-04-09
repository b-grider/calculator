#include <string>
#include "Fraction.h"
using namespace std;


class Number {
    Number(string);
    virtual Number& operator+(Number&)=0;
    virtual Number& operator-(Number&)=0;
    virtual Number& operator*(Number&)=0;
    virtual Number& operator/(Number&)=0;

};

/*class Polynomial : Number {

private:
	string expression;
	Polynomial(string a) : expression(a) {}

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
		double pure;

	Integer operator+(Integer&);
	Integer operator-(Integer&);
	Integer operator*(Integer&);
	Integer operator/(Integer&);
};
class Log : Number {

	private:
	double base;
	double pure;

	Log() : base(0), pure(0) {}
	Log(Number a, Number* b) : base(a), pure(b) {}			//Will this generalize and be compatible with all number types? Log of a log solved?

	Log operator+(Log&);
	Log operator-(Log&);
	Log operator*(Log&);
	Log operator/(Log&);
};
=======


class Number {
    Number(string);
    virtual Number& operator+(Number&)=0;
    virtual Number& operator-(Number&)=0;
    virtual Number& operator*(Number&)=0;
    virtual Number& operator/(Number&)=0;

};

/*class Polynomial : Number {

private:
	string expression;
	Polynomial(string a) : expression(a) {}

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
		double pure;

	Integer operator+(Integer&);
	Integer operator-(Integer&);
	Integer operator*(Integer&);
	Integer operator/(Integer&);
};
class Log : Number {

	private:
	double base;
	double pure;

	Log() : base(0), pure(0) {}
	Log(Number a, Number* b) : base(a), pure(b) {}			//Will this generalize and be compatible with all number types? Log of a log solved?

	Log operator+(Log&);
	Log operator-(Log&);
	Log operator*(Log&);
	Log operator/(Log&);
};
>>>>>>> d491b34338c09518a205058378e6c222d1a22a53
*/
