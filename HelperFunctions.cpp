#include "HelperFunctions.h"
class invalidNumber: public exception {
  virtual const char* what() const throw()
  {
    return "You did not input a recognizable number type";
  }
} notNum;
HelperFunctions::HelperFunctions(string a) {
    input = a;
}
Number* HelperFunctions::help() {
    Number* n;
    if(isPolynomial(input)) {
        //Polynomial* i = new Polynomial();
    }
    else if(isIrrational(input)) {
        Irrational* n = new Irrational(input);
    }
    else if(isInteger(input)) {
        Integer* n = new Integer(input);
    }
    else if(isFraction(input)) {
        Fraction* n = new Fraction(input);
    }
    else if(isLog(input)) {
        string b, num;
          int i = 4;
          //Specified base for the log
          if(input[3] == '_' ) {
              while(input[i] != ':') {
                  b += input[i];
                  i++;
              }
              i++;
              while(i <= input.length()-1) {
                  num += input[i];
                  i++;
              }
              Log* n = new Log(b, num);
          }
          //This is log base 10
          else if(input[3] == ':') {
              while(i <= input.length()-1) {
                  num += input[i];
                  i++;
              }
              Log* n = new Log(num);
          }
        return n;
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

