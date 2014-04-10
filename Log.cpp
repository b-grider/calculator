#include "Log.h"
Log::Log(string a) {
    double temp;
    base = 10;
    if(istringstream(a) >> temp) {
        number = temp;
    }
}
Log::Log(string b, string num) {
    istringstream(b) >> base;
    istringstream(num) >> number;

}
/*Log::Log(Number* base, Number* number) {

}
Log::logb(Number* base, Number* number) {

}*/
string Log::logb(double base, double number) {

}
