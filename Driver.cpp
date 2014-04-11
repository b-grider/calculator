//#include "Driver.h"
#include<iostream>
#include"Expression.h"
#include "Number.h"
#include "HelperFunctions.h"

using namespace std;

int main() {
    //Integer* isInt = dynamic_cast<Number*>(base);
    //string str = "3+((-3)/4)";
    string str = "250e";
	//string str = "2+5/6*8-(5/2)*78";
	Expression* calc = new Expression(str);
	//calc->testmeth(str);
        string temp = calc->shunting(str);
		cout << temp << endl;
	//cout << calc->evaluate(temp) << endl;
                Irrational* i = new Irrational("260pi");
	//calc->getinput();
	//Fraction* f = new Fraction("256/5634");
    //string s = "25";
    //string t = "log_3:9";
    //HelperFunctions* h = new HelperFunctions(s);
    //HelperFunctions* i = new HelperFunctions(t);
//    Fraction* in = new Fraction("4390/3530");
    //vector<int> factors = in->primeFactorization();

}
/*double Driver::fractionToDecimal(string input) {

}
*/
