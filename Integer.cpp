#include "Integer.h"
Integer::Integer(string num) {
    int number;
    istringstream num1(num);
    num1 >> number;
}

/*Integer::Integer(int num)
{
  integer = num;  
}*/

Integer::Integer(int a) {
    value = a;
}
int Integer::getValue(){
    return value;
}
double Integer::getDoubleValue(){
    return (double) value;
}
string Integer::toString(){
    ostringstream os;
    os<< value;
    return os.str();
}
void Integer::simplify(){
    
}

