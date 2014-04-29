#ifndef EXPRESSION_H
#define	EXPRESSION_H
#include "Operations.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

class Expression {
        private:
            string userinput;
            string rpn;
            string final;
            double dec;
            stack<string> mainStack;
            queue<string> mainQueue;
            //vector<string> answers;
        public:
            Expression(string);
            bool isOperator(string);
            int precedence(string);
            string shunting();
            string evaluate();
            string reOrder();
           
            
};


#endif

