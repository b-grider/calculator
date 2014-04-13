#include "Log.h"
Log::Log(string a) {
    double temp;
    base = 10;
    if(istringstream(a) >> temp) {
        number = temp;
    }
    cout << "The log has a base of: " << base << " and the number is: " << number << endl;
    cout << "This gives us: " << a << endl;
}
Log::Log(string b, string num) {
    istringstream(b) >> base;
    istringstream(num) >> number;
    cout << "The log has a base of: " << base << " and the number is: " << number << endl;
}

Log::Log(double a, double b) {
	base = a;
	number = b;
}
/*Log::Log(Number* base, Number* number) {

}
Log::logb(Number* base, Number* number) {

}*/
string Log::logb(double base, double number) {
	return "Hey there";							// FLAG Whoever started this method should probably finish it lol
}

Number* Log::add(Number* a) {
	Number* b = new Log(2,8);
	return b;
}

Number* Log::subtract(Number* a) {
	Number* b = new Log(2,8);
	return b;
}

Number* Log::multiply(Number* a) {
	Number* b = new Log(2,8);
	return b;
}

Number* Log::divide(Number* a) {
	Number* b = new Log(2,8);
	return b;
}
