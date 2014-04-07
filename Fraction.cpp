#include "Fraction.h"
Fraction::Fraction()
{

}
Fraction::Fraction(int numer, int denom)
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
