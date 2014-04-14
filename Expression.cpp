#include "Expression.h"
#include "HelperFunctions.h"
#include "Number.h"

using namespace std;


class parentheses: public exception {
  virtual const char* what() const throw()
  {
    return "Your parentheses do match up. Please try again.";
  }
} par;
class stackSize: public exception {
  virtual const char* what() const throw()
  {
    return "Your operation does not have two valid operands to use.";
  }
} toosmall;
Expression::Expression(string a) {
    userinput = a;
}
bool Expression::isOperator(string c) {
    if(c[0] == '+' || c[0] == '*' || c[0] == '-' || c[0] == '/') {
    	return true;
    }
    else {
        return false;
    }
}
int Expression::precedence(string s) {
    int prec;
        if(s[0] == '/' || s[0] == '*') {
            prec = 2;
        }
        else if(s[0] == '+'|| s[0] == '-') {
            prec = 1;
        }
        else {
            prec = 0;
        }
    return prec;
}
/*Number* Expression::stringToNumber(string a) {
    HelperFunctions* n = new HelperFunctions(a);
    return n->help();
}*/
string Expression::numberToString(Number* n) {
    ostringstream temp;
    temp << n;
    string str = temp.str();
    //n->toString();
    return str;
}
string Expression::shunting(string userinput) {
	// This entire block is performing the Reverse Polish Notation on the input.
	double num;
	// Read all characters one at a time
	for (int i = 0; i < userinput.length(); i++) {
		stringstream ss;
		string oneChar;
		ss << userinput[i];
		ss >> oneChar;
		if (userinput[i] != ' ') {
			// Check if it is a numeric value, converts the character at element 'i'
			// into a double, if true, then it is a numeric value
			if (istringstream(oneChar) >> num || userinput.find("log") < userinput.length() || userinput.find("pi")< userinput.length() || userinput.find('e')< userinput.length()) {
				while (i < userinput.length() && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
					i++;
					oneChar += userinput[i];
				}
				// If number, push onto queue, remember, we are passing it back as a string!
                                //HelperFunctions* n = new HelperFunctions(oneChar);
                                mainQueue.push(oneChar);
			}
                        else if(userinput[i] == '-' && i == 0) {
                            string firstNeg;
                            firstNeg = "-";
                            while (i < (userinput.length()-1) && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
                                i++;
                                firstNeg+= userinput[i];
                            }
                            mainQueue.push(firstNeg);
			}
                        // Check if character is an operator, if so, add to stack
			else if (isOperator(oneChar)) {
                                if(userinput.substr(i+1, 1) == "-") {
                                    string tempNum;
                                    i++;
                                    tempNum = "-";
                                    while (i < (userinput.length()-1) && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
                                        i++;
                                        tempNum += userinput[i];
                                    }
                                    mainQueue.push(tempNum);
				}
				if (mainStack.empty()) {
					mainStack.push(oneChar);
				}
				// The basic 2 highest precedence operator, if same precedence, still have to
				// pop off stack and put in queue
				else if (precedence(oneChar) == 2 && precedence(mainStack.top()) != 2){
					while (precedence(mainStack.top())!= 2) {
						mainStack.push(oneChar);
						break;
					}
				}
				else if ((precedence(oneChar) == 1) && precedence(mainStack.top()) == 0) {
					while (precedence(mainStack.top()) == 0) {
						mainStack.push(oneChar);
						break;
					}
				}
				// Operations are moved from stack to queue.
				// First in last out, so the last operation would be sent to the queue
				else {
                                    while(!mainStack.empty() && mainStack.top() != "(") {
                                        mainQueue.push(mainStack.top());
                                        mainStack.pop();
                                    }
                                    mainStack.push(oneChar);
				}
			}

			// Parentheses Checker, put ( in stack, put everything after the (
			// in the stack also until ) is found. When ) is found, pop ) off,
			// and move all operations below to the queue until ( is found.
			else if (oneChar == "(") {
                if(userinput.substr(i+1, 1) == "-") {
                    string inside;
                    i++;
                    inside = "-";
                    while (i < (userinput.length()-1) && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
                        i++;
                        inside += userinput[i];
                    }
                    mainQueue.push(inside);
                }
				mainStack.push(oneChar);
			}

			else if (oneChar == ")") {
				while (mainStack.top() != "(") {
					if (mainStack.empty()) {
						throw par;
					}
					mainQueue.push(mainStack.top());
					mainStack.pop();
				}
				if (mainStack.top() == "(") {
					mainStack.pop();
				}
			}

		}
                //string stackElement = mainStack.top();
	}
	// Puts all the operations in stack to queue
	for (int j = mainStack.size() - 1; j >= 0; j--) {
		mainQueue.push(mainStack.top());
		mainStack.pop();
	}
	int qSize = mainQueue.size();
	// String builder, puts it into Reverse Polish Notation
	for (int k = 0; k < qSize; k++) {
            //if(mainQueue.front() != "(" || mainQueue.front() != ")") {
                rpn += mainQueue.front() + " ";
		mainQueue.pop();
            //}
	}

	return rpn;
}
/*string Expression::evaluate(string rpn) {
    double num;
    //While there are input tokens left
    for (int i = 0; i < rpn.length(); i++) {
        stringstream ss;
        string oneChar;
        ss << rpn[i];
        ss >> oneChar;
        if(rpn[i] != ' ') {													//Will there ever be spaces in a proper rpn string? unecessary.
            while(rpn.substr(i+1, 1) != " " && i < rpn.length()) {			//Won't first condition always be satisfied??
                i++;
                oneChar += rpn[i];
            }
    //while(!rpn.empty()) {
            //Read the next token from input.
            //If the token is a value
            if (istringstream(oneChar) >> num) {
                    //Push it onto the stack.
                    mainStack.push(oneChar);
            }
            //Otherwise, the token is an operator (operator here includes both operators and functions).
            else if(rpn[i] == ' ') {
            }
            else {
            //It is known a priority that the operator takes 2 arguments.
            //If there are fewer than 2 values on the stack
                if(mainStack.size() < 2) {
                    //(Error) The user has not input sufficient values in the expression.
                    throw toosmall;
                }
                else {
                //Else, Pop the top n values from the stack.
                //Evaluate the operator, with the values as arguments.
                //Push the returned results, if any, back onto the stack.
                    Number* answer;
                    Number* number1;
                    Number* number2;
                    string num1, num2;
                    if(oneChar == "+") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        number1 = stringToNumber(num1);
                        number2 = stringToNumber(num2);
                        //answer = number1 + number2;
                        //numStack.push(numberToString(answer));
                    }
                    else if(oneChar == "-") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        number1 = stringToNumber(num1);
                        number2 = stringToNumber(num2);
                        //answer = number1 - number2;
                        //numStack.push(numberToString(answer));
                    }
                    else if(oneChar == "*") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        number1 = stringToNumber(num1);
                        number2 = stringToNumber(num2);
                        //answer = number1 * number2;
                        //numStack.push(numberToString(answer));
                    }
                    else if(oneChar == "/") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        number1 = stringToNumber(num1);
                        number2 = stringToNumber(num2);
                        //answer = number1 / number2;
                        //numStack.push(numberToString(answer));
                    }
                }
                //If there is only one value in the stack
                //That value is the result of the calculation.
                //Otherwise, there are more values in the stack
                //(Error) The user input has too many values.
            }
        }
    }
    string final = mainStack.top();
    return final;
}

Number* Expression::simplification(Number* numerator, Number* denominator) {

}
string Expression::exponentiate(Number* base, Number* power) {

}
Number* Expression::decimalToFraction(double dec) {

}
*/

