//#include "Driver.h"
#include<iostream>
#include"Expression.h"
#include<cmath>

using namespace std;

int main() {
    string str = "(23+ (-5*6) - 8)+(4 /      (2 * 5))";
	//string str = "2+5/6*8-(5/2)*78";
	Expression* calc = new Expression(str);
	//calc->testmeth(str);
        string temp = calc->shunting(str);
		cout << temp << endl;
	cout << calc->evaluate(temp) << endl;
	//calc->getinput();
	
	
	//cout << pow(4,2);
	
	
	return 0;
}
/*double Driver::fractionToDecimal(string input) {

}
*/
