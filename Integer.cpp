#include "Integer.h"

using namespace std;

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
    cout << "The integer has a value of: " << value << endl;
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


Number* Integer::add(Number* a) {
	/*if(a->toString) {
		
			}
			//the number is another integer it can be added
	if() {
		
			}//the number is a fraction it can be added*/
			Number * b = new Integer("5");
			return b;
}

Number* Integer::subtract(Number* a) {
	Number * b = new Integer("5");
			return a;
}

Number* Integer::multiply(Number* a) {
	Number * b = new Integer("5");
			return a;
}

Number* Integer::divide(Number* a) {
	Number * b = new Integer("5");
			return a;
}

