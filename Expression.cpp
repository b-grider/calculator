#include "Expression.h"
#include "Driver.h"

using namespace std;
class mystery: public exception {
  virtual const char* what() const throw()
  {
    return "You have somehow found a way to crash the program.";
  }
} mysteriousError;
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
                    //Allows the user to enter "ans" and the program will pull the last stored answer as long as the answer did not throw an
                    /*if(oneChar[0] == 'a') {
                        i++;
                        while(oneChar.length() < 3 && i < userinput.length()) {
                            oneChar += userinput[i];
                            i++;
                        }
                        if(oneChar.find("ans") < oneChar.length()) {
                            oneChar = answers.back();
                            mainStack.push(oneChar);
                        }
                    } */
			// into a double, if true, then it is a numeric value
				if (istringstream(oneChar) >> num || userinput[i] == 's' || userinput[i] == 'S' || userinput[i] == 'l' || userinput[i] == 'L' || userinput[i] == 'p' || userinput[i] == 'P' || userinput[i] == 'e' || userinput[i] == 'E') {
                            if(oneChar == "l") {
                                i++;
                                string mystring = "";
                                while(!isOperator(mystring) && i < userinput.length()) {
                                    oneChar += userinput[i];
                                    mystring = string(1, userinput[i+1]);
                                    i++;
                                }
                                if(isOperator(mystring)) {
                                    i--;
                                }
                            }
                            else {
                                while (i < userinput.length() && userinput.substr(i+1, 1) != " " && !isOperator(userinput.substr(i+1,1)) && userinput.substr(i+1, 1) != "(" && userinput.substr(i+1, 1) != ")") {
											i++;
                                            oneChar += userinput[i];
                                    }
                            }
				// If number, push onto queue, remember, we are passing it back as a string!
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
            if (istringstream(oneChar) >> num|| oneChar.find("rt:") < oneChar.length() || oneChar.find("log") < oneChar.length() || oneChar.find("e") < oneChar.length() || oneChar.find("pi") < oneChar.length()) {
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
						 if (oneChar[i] == '(' || oneChar[i] == ')') {
							 i++;
						 }
						 r += oneChar[i];
                         i++;
                     }
                     if(oneChar[i] == '*') {
                         i++;
                     }
                     i += 3;
                     while(i < oneChar.length()) {
						 if (oneChar[i] == '(' || oneChar[i] == ')') {
							 i++;
						 }
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
						if (oneChar[i] == '(' || oneChar[i] == ')') {
							i++;
						}
                        base += oneChar[i];
                        i++;
                    }
                    i++;
                    while(i < oneChar.length()) {
						if (oneChar[i] == '(' || oneChar[i] == ')') {
							i++;
						}
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
    final = mainStack.top();
    //answers.push_back(final);
    //cout << "The value: "<< answers.back() << " was just added to the answers vector" << endl;
    return final;
}
string Expression::reOrder() {
    vector<string> pile;
	int vectorIndex = 0;
	size_t n = 0;
        bool add = false;
		int i = 0;
		while (i < final.length()) {
		//for (int i = 0; i < final.length(); i++) {
			string temp;
			if (final[i] == '-' && i < final.length()) {
				temp = "-";
				i++;
			}
			if (final[i] == '+' && i < final.length()) {
				temp = "+";
				i++;
			}
			//while you have not come across a plus or minus sign grab everything before the sign				   
			//once you come across a plus sign this will break
			while (final[i] != '+' && final[i] != '-' && i < final.length()) {
				temp += final[i];
				i++;
			}
		if (pile.empty()) {
			pile.push_back(temp);
		}
                        else if (isLog(temp) || isIrrational(temp) || isNthRoot(temp)) {
                    if(isLog(temp)) {
                        for (vector<string>::iterator it = pile.begin(); it != pile.end(); it++) {
                                if (isLog(*it)) {
                                        it++;
                                        pile.insert(it, temp);
                                        add = true;
                                        break;
                                }
                        }
                        //pile.push_back(temp);
                    }
                    else if(isIrrational(temp)) {
                        for (vector<string>::iterator it = pile.begin(); it != pile.end(); it++) {
                                //once you find a log go back an index and insert
                                if (isIrrational(*it)) {
                                        it++;
                                        pile.insert(it, temp);
                                        add = true;
                                        break;
                                }
                        }
                    }
                    else if(isNthRoot(temp)) {
                        for (vector<string>::iterator it = pile.begin(); it != pile.end(); it++) {
                                //once you find a log go back an index and insert
                                if (isNthRoot(*it)) {
                                        it++;
                                        pile.insert(it, temp);
                                        add = true;
                                        break;
                                }
                        }
                        
                    }
                    if(add == false) {
                        pile.push_back(temp);
                    }
		}
		//if the string is an integer or a fraction then traverse the vector to find the last integer 
            else if (isInteger(temp) || isFraction(temp)) {
			//if it begins with an integer or fraction
			if (isInteger(pile[0]) || isFraction(pile[0])) {  
			   //iterate through and see where the first log is 
				for (vector<string>::iterator it = pile.begin(); it != pile.end(); it++) {
					//once you find a log go back an index and insert
                                        if (isLog(*it) || isIrrational(*it) || isNthRoot(*it)) {
						it--;
						pile.insert(it, temp);
						break;
					}
                                        else if ((isInteger(*it) || isFraction(*it)) && it == pile.end()) {
                                                it++;
						pile.insert(it, temp);
						break;
                                        }
					//else if the left has an integer and the right has an irrational insert after left
                                        else if ((isInteger(*it) || isFraction(*it)) && (isLog(*(it + 1)) || isIrrational(*(it + 1)))) {
						it++;
						pile.insert(it, temp);
						break;
					}
				}
				/*while ((isInteger(pile[n]) || isFraction(pile[n])) && n < pile.size()) {
					vectorIndex++;
				}	   */
				//now that we have found the last instance of an integer in the vector insert the string to the next index position.
			}
		}                
	}
	userinput = "";
	for (size_t n = 0; n < pile.size(); n++) {
		userinput += pile[n];
	} 
        /*(string tempInt;
        string tempIrrationals;
        for(vector<string>::iterator finalIt = pile.begin(); !isLog(*finalIt) && !isIrrational(*finalIt) && !isNthRoot(*finalIt); finalIt++) {
            tempInt += *finalIt;
        }	*/
	if (userinput.compare(final) == 0) {
		userinput = final;
	}
	return userinput;
}