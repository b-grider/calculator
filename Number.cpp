#include "Number.h"
Number:: Number(string str) {
    num = str;
}
Number::Number() {
    num = "";
}
string Number::getNumber(){
    return num;  
}
void Number::setNumber(string str){
    num = str;
}