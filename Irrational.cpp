#include "Irrational.h"
Irrational::Irrational() {

   }
Irrational::Irrational(string str) {
    int i = 0;
    coefficient = "";
    int temp;
    while(i < str.length()) {
         if(istringstream(str.substr(i, 1)) >> temp) {
            coefficient += str[i];
            i++;
        }
         else if(!(istringstream(str.substr(i, 1)) >> temp)) {
            if((str[i] == 'p' && str[i+1] == 'i') || (str[i] == 'P' && str[i+1] == 'i') || (str[i] == 'p' && str[i+1] == 'I') || (str[i] == 'P' && str[i+1] == 'I')) {
                PI = coefficient + "pi";
                }
            else if((str[i] == 'e' || str[i] == 'E')) {
                e = coefficient + "e";
                }
            i = str.length();
         }
         
         if(coefficient == ""){
             coefficient = "1";
         }
    }
    
}
Number* Irrational::addPi(Number* num) {
    Number* res = new Number();
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    while(i < Num.length()){
        if(istringstream(Num.substr(i, 1)) >> temp) {
            tempString += Num[i];
            i++;
        }
        else if(!(istringstream(Num.substr(i, 1)) >> temp)){
                istringstream(tempString) >> temp;
                if((Num[i] == 'p' && Num[i+1] == 'i') || (Num[i] == 'P' && Num[i+1] == 'i') || (Num[i] == 'p' && Num[i+1] == 'I') || (Num[i] == 'P' && Num[i+1] == 'I')){
                    istringstream(coefficient) >> tempcoeff;
                    temp += tempcoeff;
                    ostringstream(tempString) << temp;
                    result = tempString + "pi";
                    i = Num.length();
                    break;
                }
                else{
                    result = Num + "+pi";
                    i = Num.length();
                    break;
                }   
        }
        result = Num + "+pi";
    }
    res->setNumber(result);
    return res;
}
Number* Irrational::subtractPi(Number* num) {
    Number* res = new Number();
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString;
    string result = "";
    while(i < Num.length()){
        if(istringstream(Num.substr(i, 1)) >> temp) {
            tempString += Num[i];
            i++;
        }
        else if(!(istringstream(Num.substr(i, 1)) >> temp)){
                istringstream(tempString) >> temp;
                if((Num[i] == 'p' && Num[i+1] == 'i') || (Num[i] == 'P' && Num[i+1] == 'i') || (Num[i] == 'p' && Num[i+1] == 'I') || (Num[i] == 'P' && Num[i+1] == 'I')){
                    istringstream(coefficient) >> tempcoeff;
                    temp -= tempcoeff;
                    ostringstream(tempString) << temp;
                    result = tempString + "pi";
                    i = Num.length();
                    break;
                }
                else{
                    result = Num + "-pi";
                    i = Num.length();
                    break;
                }   
        }
        result = Num + "-pi";
    }
    res->setNumber(result);
    return res;
}
Number* Irrational::multiplyPi(Number* num) {
    Number* res = new Number();
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    while(i < Num.length()){
        if(istringstream(Num.substr(i, 1)) >> temp) {
            tempString += Num[i];
            i++;
        }
        else if(!(istringstream(Num.substr(i, 1)) >> temp)){
                istringstream(tempString) >> temp;
                if((Num[i] == 'p' && Num[i+1] == 'i') || (Num[i] == 'P' && Num[i+1] == 'i') || (Num[i] == 'p' && Num[i+1] == 'I') || (Num[i] == 'P' && Num[i+1] == 'I')){
                    istringstream(coefficient) >> tempcoeff;
                    temp *= tempcoeff;
                    ostringstream(tempString) << temp;
                    result = tempString + "pi^2";
                    i = Num.length();
                    break;
                }
                else{
                    result = Num + "pi";
                    i = Num.length();
                    break;
                }   
        }
        result = Num + "pi";
    }
    res->setNumber(result);
    return res;
}
Number* Irrational::addE(Number* num) {
    Number* res = new Number();
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    while(i < Num.length()){
        if(istringstream(Num.substr(i, 1)) >> temp) {
            tempString += Num[i];
            i++;
        }
        else if(!(istringstream(Num.substr(i, 1)) >> temp)){
                istringstream(tempString) >> temp;
                if((Num[i] == 'e' || Num[i] == 'E')){
                    istringstream(coefficient) >> tempcoeff;
                    temp += tempcoeff;
                    ostringstream(tempString) << temp;
                    result = tempString + "e";
                    i = Num.length();
                    break;
                }
                else{
                    result = Num + "+e";
                    i = Num.length();
                    break;
                }   
        }
        result = Num + "+e";
    }
    res->setNumber(result);
    return res;
}
Number* Irrational::subtractE(Number* num) {
    Number* res = new Number();
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString;
    string result = "";
    while(i < Num.length()){
        if(istringstream(Num.substr(i, 1)) >> temp) {
            tempString += Num[i];
            i++;
        }
        else if(!(istringstream(Num.substr(i, 1)) >> temp)){
                istringstream(tempString) >> temp;
                if((Num[i] == 'e' || Num[i] == 'E')){
                    istringstream(coefficient) >> tempcoeff;
                    temp -= tempcoeff;
                    ostringstream(tempString) << temp;
                    result = tempString + "e";
                    i = Num.length();
                    break;
                }
                else{
                    result = Num + "-e";
                    i = Num.length();
                    break;
                }   
        }
        result = Num + "+e";
    }
    res->setNumber(result);
    return res;
}
Number* Irrational::multiplyE(Number* num) {

}

