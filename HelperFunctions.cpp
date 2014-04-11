#include "HelperFunctions.h"
class invalidNumber: public exception {
  virtual const char* what() const throw()
  {
    return "You did not input a recognizable number type";
  }
} notNum;
HelperFunctions::HelperFunctions(string a) {
    if(isPolynomial(a)) {
        //Polynomial* p = new Polynomial();
    }
    else if(isIrrational(a)) {
        Irrational* i = new Irrational(a);
    }
    else if(isInteger(a)) {
        Integer* i = new Integer(a);
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
              Log* l = new Log(b, num);
          }
          //This is log base 10
          else if(a[3] == ':') {
              while(i <= a.length()-1) {
                  num += a[i];
                  i++;
              }
              Log* m = new Log(num);
          }

    }
    else {
        throw notNum;
    }
}

bool HelperFunctions::isPolynomial(string str) {
    //if first number is negative, i=1 should bypass it
    int i = 0;
    if(str[0] == '-') {
        i++;
    }
    while(i < str.length()) {
        if(str[i] == ('+'||'-'||'*'||'/'))
            return true;
            i++;
        }
        return false;
}
bool HelperFunctions::isIrrational(string str) {
    int i = 0;
    int num;
    while(i < str.length()) {
        if(!(istringstream(str.substr(i, 1)) >> num)) {
            if(str[i] == 'p' && str[i+1] == 'i' || str[i] == 'P' && str[i+1] == 'i' || str[i] == 'p' && str[i+1] == 'I' || str[i] == 'P' && str[i+1] == 'I') {
                return true;
                }
            else if(str[i] == 'e'|| str[i] == 'E') {
                return true;
                }
            else {

                return false;
                }
            }
        else if(istringstream(str.substr(i, 1)) >> num) {
            i++;
        }
    }
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

