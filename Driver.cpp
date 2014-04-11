//#include "Driver.h"
#include<iostream>
#include"Expression.h"
#include "Number.h"
#include "HelperFunctions.h"

using namespace std;

int main() {
    //Integer* isInt = dynamic_cast<Number*>(base);
    //string str = "3+((-3)/4)";
    //string str = "(23+ (5) - 8) /      (2 * 5)";
	//string str = "2+5/6*8-(5/2)*78";
	//Expression* calc = new Expression(str);
	//calc->testmeth(str);
       // string temp = calc->shunting(str);
		//cout << temp << endl;
	//cout << calc->evaluate(temp) << endl;
	//calc->getinput();
	//Fraction* f = new Fraction("256/5634");
    //string s = "25";
    //string t = "log_3:9";
    //HelperFunctions* h = new HelperFunctions(s);
    //HelperFunctions* i = new HelperFunctions(t);
    Fraction* in = new Fraction("4390/3530");
    vector<int> factors = in->primeFactorization();
    for(int i = 0; i < factors.size(); i++)
    {
        cout<<factors[i]<<endl;
    }
    cout<<"\n\n\n"<<endl;
    Integer* in2 = new Integer(1);
    int a = in->greatestCommonFactor(in2);
    cout<<a<<endl;

}
/*double Driver::fractionToDecimal(string input) {

}
*/
