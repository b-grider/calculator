#include "Number.h"

Number::Number(string str) {

<<<<<<< HEAD
=======
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
    //if first number is negative, i=1 should bypass it
    int i = 1;
    while(str[i])
    {
        if(str[i] == ('+'||'-'||'*'||'/'))
            return true;
        i++;
    }
    return false;
>>>>>>> 98582179da35d6aa97c163bde6e27ee30eb5ffb1
}
Number::Number() {

}
