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
        string b, num;
        int i = 4;
        //Specified base for the log
        if(a[3] == '_' ) {
            while(a[i] != ':') {
                b += a[i];
                i++;
            }
            i++;
            while(i <= a.length()-1) {
                num += a[i];
                i++;
            }
        }
        //This is log base 10
        else if(a[3] == ':') {
            while(i <= a.length()-1) {
                num += a[i];
                i++;
            }
        }
        Log* l = new Log(b);
    }
    else {
        throw notNum;
    }
}
bool Number::isPolynomial(string str) {
    return false;
}
bool Number::isIrrational(string str) {
    return false;
}
bool Number::isInteger(string str) {
    double num;
    if(istringstream(str) >> num) {

    }
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
bool Number::isLog(string a) {
    if(a[0] == 'l' && a[1] == 'o' && a[2] == 'g') {
        return true;
    }
}
