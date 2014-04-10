#ifndef EXPRESSION_H
#define	EXPRESSION_H
//#include "Number.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

class Expression {
        private:
            string userinput;
            string rpn;
            //Number* numerator;
            //Number* denominator;
            //Number* base;
            //Number* power;
            double dec;
            stack<string> mainStack;
            queue<string> mainQueue;
        public:
            Expression(string);
            bool isOperator(string);
            int precedence(string);
            string shunting(string);
            string evaluate(string);
            double stringToDouble(string);
            string doubleToString(double);
            //Number* simplification(Number* numerator, Number* denominator);
            //string exponentiate(Number* base, Number* power);
            //Number* decimalToFraction(double dec);

};


#endif

