#include "Expression.h"

using namespace std;
class invalidOperator: public exception {
  virtual const char* what() const throw()
  {
    return "You have entered an invalid operator";
  }
} invalidOperator;

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
        if(s[0] == '^') {
            prec = 3;
        }
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
string Expression::shunting() {
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
			if (istringstream(oneChar) >> num || userinput[i] == 'l' || userinput[i] == 'L' || userinput[i] == 'p' || userinput[i] == 'P' || userinput[i] == 'e' || userinput[i] == 'E') {
                            if(oneChar == "l") {
                                string mystring = "";
                                while(!isOperator(mystring)) {
                                    oneChar += oneChar[i];
                                    mystring = string(1, oneChar[i]);
                                    i++;
                                }
                            }
                            else {
                                while (i < userinput.length() && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
                                            i++;
                                            oneChar += userinput[i];
                                    }
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
string Expression::evaluate() {
    double num;
    //While there are input tokens left
    for (int i = 0; i < rpn.length(); i++) {
        stringstream ss;
        string oneChar;
        ss << rpn[i];
        ss >> oneChar;
        if(rpn[i] != ' ') {								//Will there ever be spaces in a proper rpn string? unecessary.
            while(rpn.substr(i+1, 1) != " " && i < rpn.length()) {			//Won't first condition always be satisfied??
                i++;
                oneChar += rpn[i];
            }
    //while(!rpn.empty()) {
            //Read the next token from input.
            //If the token is a value
            if (istringstream(oneChar) >> num|| oneChar.find("log") < oneChar.length() || oneChar.find("e") < oneChar.length() || oneChar.find("pi") < oneChar.length()) {
                    //Push it onto the stack.
                 if(isLog(oneChar)) {
                      int base, n;
                      string leftNum, leftBase;
                      int i = 4;
                      //Specified base for the log
                      if(oneChar[3] == '_' ) {
                          while(oneChar[i] != ':') {
                              if(oneChar[i] == '(' || oneChar[i] == ')') {
                                  i++;
                              }
                              leftBase += oneChar[i];
                              i++;
                          }
                          i++;
                          while(i <= oneChar.length()-1) {
                              if(oneChar[i] == '(' || oneChar[i] == ')') {
                                  i++;
                              }
                              leftNum += oneChar[i];
                              i++;
                          }
                      }
                      //This is log base 10
                      else if(oneChar[3] == ':') {
                          leftBase = "10";
                          while(i <= oneChar.length()-1) {
                              if(oneChar[i] == '(' || oneChar[i] == ')') {
                                  i++;
                              }
                              leftNum += oneChar[i];
                              i++;
                          }
                      }
                      istringstream(leftBase) >> base;
                      istringstream(leftNum) >> n;
                    oneChar = simplifyLog(base, n);
                }
                 else if(isNthRoot(oneChar)) {
                     int i = 0;
                     string b, r;
                     while(oneChar[i] != 'r' && oneChar[i] != '*') {
                         r += oneChar[i];
                         i++;
                     }
                     if(oneChar[i] == '*') {
                         i++;
                     }
                     i += 3;
                     while(i < oneChar.length()) {
                         b += oneChar[i];
                         i++;
                     }
                     double root, base;
                     istringstream(b) >> base;
                     istringstream(r) >> root;
                     oneChar = simplifyRoot(root, base);
                 }
                 else if(isExponent(oneChar)) {
                    int i = 0;
                    string base, exponent;
                    while(oneChar[i] != '^') {
                        base += oneChar[i];
                        i++;
                    }
                    i++;
                    while(i < oneChar.length()) {
                        exponent += oneChar[i];
                        i++;
                    }
                     oneChar = exponentiate(base, exponent);
                 }
                    mainStack.push(oneChar);
            }
            //Otherwise, the token is an operator (operator here includes both operators and functions).
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
                    string answer, number1, number2, num1, num2;
                    if(oneChar == "+") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        answer = add(num1, num2);
                        mainStack.push(answer);
                    }
                    else if(oneChar == "-") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        answer = subtract(num1, num2);
                        mainStack.push(answer);
                    }
                    else if(oneChar == "*") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        if(num1[num1.length()] == ' ') {
                            num1 = num1.substr(0, num1.length()-1);
                        }
                        if(num2.find(" ") < num2.length()) {
                            num2 = num2.substr(0, num2.length()-1);
                        }
                        answer = multiply(num1,num2);
                        mainStack.push(answer);
                    }
                    else if(oneChar == "/") {
                        num2 = mainStack.top();
                        mainStack.pop();
                        num1 = mainStack.top();
                        mainStack.pop();
                        answer = divide(num1, num2);
                        mainStack.push(answer);
                    }
                    else {
                        throw invalidOperator;
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
/*string Expression::reOrder(string final) {
    vector<string> pile;
    double num;
    int importantCount = 0;
	// Read all characters one at a time
    for(int i = 0; i < final.length(); i++) {
       string temp;
        while(final[i] != '+' && ((final[i] == ':' && final[i+1] == '-') || final[i] != '-')) {
                temp += final[i];
                i++;
        }
        if(isInteger(temp) || isFraction(temp)) {
           pile.insert(importantCount, temp); 
        }
        else if(isLog(temp) || isIrrational(temp)) {
            
            pile.push_back(temp);
        }
        
    }
}
 */       
