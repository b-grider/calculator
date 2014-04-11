#include "Fraction.h"
Fraction::Fraction(string a) {
    int i =0;
    string top, bottom;
    while(a[i] != '/'){
        top += a[i];
        i++;
    }
    i++;
    while(i < a.length()) {
        bottom += a[i];
        i++;
    }
    numerator = new Integer(top);
    denominator = new Integer(bottom);
    cout << top << endl << "---" << endl << bottom;
}
Fraction::Fraction(double numer, double denom)
{
    //numerator = numer;
    //denominator = denom;
}
vector<int> Fraction::primeFactorization(){
    vector<int>* factors = new vector<int>;
    int i = 2;
    //int value = this->value;
    if(value == 1)
    {
        factors->push_back(1);
        return *factors;
    }
    while((i * i) <= this->value)
    {
        if((value % i) == 0)
        {
            factors->push_back(i);
            value = value / i;
        }
        else
        {
            i++;
        }
    }
    return *factors;
}
int Fraction::greatestCommonFactor(Integer* secondNumber) {
    int a = this->value;
    int b = secondNumber->value;
    return gcd(a, b);


}
int Fraction:: gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
/*

Potential simplification idea???????

 double fraction = numerator/denominator;

 for(int d = 1; denominator > d; d++)
 {
 	 for(int n=0; numerator > n; n++)
 	 {
 	 	 double temp = n/d;
 	 	 if(temp == fraction);
 	 	 denominator = d;
 	 	 numerator = n;
 	 }
 )

 */
