#include "Irrational.h"
Irrational::Irrational() {

   }
Irrational::Irrational(string str) {
    int i = 0;
    PI = "";
    e = "";
    coefficient = "";
    exponent= "";
    typeofIrrational = "";
    int temp;
    while(i < str.length()) {
         if(istringstream(str.substr(i, 1)) >> temp) {
            coefficient += str[i];
            i++;
        }
         else if(!(istringstream(str.substr(i, 1)) >> temp)) {
            if((str[i] == 'p' && str[i+1] == 'i') || (str[i] == 'P' && str[i+1] == 'i') || (str[i] == 'p' && str[i+1] == 'I') || (str[i] == 'P' && str[i+1] == 'I')) {
                if(str.substr(i+2,1) == "^") {
                    for(int j = i; j < str.length(); j++) {
                        exponent += str[j+2];
                    }
                    typeofIrrational = coefficient + "pi" + "^"+ exponent;
                    PI = "pi";
                    break;
                }
                typeofIrrational = coefficient + "pi";
                PI = "pi";
            }
            else if((str[i] == 'e' || str[i] == 'E')) {
                if(str.substr(i+1,1) == "^") {
                    for(int j = i; j < str.length(); j++) {
                        exponent += str[j+2];
                    }
                    typeofIrrational = coefficient + "e" + "^"+ exponent;
                    e = "e";
                    break;
                }
                typeofIrrational = coefficient + "e";
                e = "e";
            }
            i = str.length();
         }
         
         if(coefficient == ""){
             coefficient = "1";
         }
    }
    
    
}
string Irrational::getExponent() {
    return exponent;
}
string Irrational::getCoefficient() {
    return coefficient;
}
string Irrational::toString() {
    return typeofIrrational;
}


Number* Irrational::add(Number* num) {
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    if(PI != "") {
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
    }
    else if(e != "") {
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
    }
    num->setNumber(result);
    return num;  
}
Number* Irrational::subtract(Number* num) {
    int i, temp, tempcoeff;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    if(PI != "") {
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
    }
    else if(e != "") {
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
            result = Num + "-e";
        }
    }
    num->setNumber(result);
    return num;
}
Number* Irrational::multiply(Number* num) {
    int i, temp, tempcoeff,tempExp;
    string Num = num->getNumber();
    string tempString = "";
    string result = "";
    if(PI != "") {
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
    }
    num->setNumber(result);
    return num;
}
