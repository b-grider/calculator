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
    cout << top << endl << "---" << endl << bottom;
}
Fraction::Fraction(double numer, double denom)
{
    numerator = numer;
    denominator = denom;
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
