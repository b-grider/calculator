#include "HelperFunctions.h"
class invalidNumber: public exception {
  virtual const char* what() const throw()
  {
    return "You did not input a recognizable number type";
  }
} notNum;
HelperFunctions::HelperFunctions(string a) {
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
          Log* l = new Log(b, num);
    }
    else {
        throw notNum;
    }
}

bool HelperFunctions::isPolynomial(string str) {
    //if first number is negative, i=1 should bypass it
    int i = 1;
    while(str[i])
    {
        if(str[i] == ('+'||'-'||'*'||'/'))
            return true;
        i++;
    }
    return false;
}
bool HelperFunctions::isIrrational(string str) {
    if(str.compare("pi") == 0 || str.compare("PI") == 0 || str.compare("Pi") == 0 || str.compare("pI") == 0)
        return true;
    else if(str.compare("e") == 0 || str.compare("E") == 0)
        return true;
    else

        return false;
}

bool HelperFunctions::isInteger(string str) {
  double num;
    if(istringstream(str) >> num)
        return true;
    else
        return false;
}
bool HelperFunctions::isFraction(string str) {
    int i = 0;
    while(i <= str.length()-1) {
       if(str[i] == '/') {
           return true;
        }
       i++;
    }
}
bool HelperFunctions::isLog(string a) {
    if(a[0] == 'l' && a[1] == 'o' && a[2] == 'g') {
        return true;
    }
}

