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
        Integer* integer = new Integer(a);
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
          Log* l = new Log(b, num);
    }
    else {
        throw notNum;
    }
}


bool Number::isPolynomial(string str) {
    int i = 0;
    while(str[i])
    {
        if(str[i] == ('+'||'-'||'*'||'/'))
            return true;
        i++;
    }
    return false;
}
bool Number::isIrrational(string str) {
    if(str.compare("pi") == 0 || str.compare("PI") == 0 || str.compare("Pi") == 0 || str.compare("pI")) 
        return true;
    else if(str.compare("e") == 0 || str.compare("E") == 0)
        return true;
    else

        return false;
}

bool Number::isInteger(string str) {
  double num;
    if(istringstream(str) >> num)
        return true;
    else
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
