#include "Number.h"
class invalidNumber: public exception {
  virtual const char* what() const throw()
  {
    return "You did not input a recognizable number type";
  }
} notNum;
Number::Number(string a) {
    if(isPolynomial(a)) {

    }
    else if(isIrrational(a)) {

    }
    else if(isInteger(a)) {

    }
    else if(isFraction(a)) {
        Fraction* f = new Fraction(a);
    }
    else if(isLog(a)) {

    }
    else {
        throw notNum;
    }
}
bool Number::isPolynomial(string) {
    return false;
}
bool Number::isIrrational(string) {
    return false;
}
bool Number::isInteger(string) {
    return false;
}
bool Number::isFraction(string str) {
    int i = 0;
    while(i <= str.length()-1) {
       if(str[i] == '/') {
           return true;
        }
       i++;
    }
}
bool Number::isLog(string) {
    return false;
}
