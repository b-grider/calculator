#include "Driver.h"
#include <iostream>
#include <string>
#include "Operations.h"
#include<iostream>
#include"Expression.h"
#include <vector>

using namespace std;
vector<string> expressions;
vector<string> answers;

void mainmenu() {
	cout << "Welcome to calculator. Enter the number of the desired option below" << endl;
	cout << "(1) Compute new expression" << endl;
	cout << "(2) Review previous expressions and answers" << endl;
	cout << "(3) Help" << endl;
	cout << "(4) Quit" << endl;
}

void expmenu() {
	cout << "(a) Back " << endl;
	cout << "(b) Quit" << endl;
	cout << "Enter expression:" << endl;
}

int main() {
        
	string option;
	string option2;
	option = "";
	option2 = "";
	//string option;
	string expression;
	char input[100];
	
	while(option!="4") {

	
	mainmenu();
	cin.clear();
	getline(cin, option);
	cout << endl;
	
		if (option == "1") {
			while (expression != "a" && expression != "b") {
				expmenu();
				//cout << expression << endl;
				cin.clear();											//makes getline pause and wait for user input
				getline(cin, expression);								//gets 100 character sequence from cmd and writes to expression
				//cout << endl;
				if (expression == "a") {
					break;
				}
				if (expression == "b") {
					option == "4";
					break;
				}
				else {
					Expression * a = new Expression(expression);
					cout << a->shunting() << endl;
                                        //cout << a-> evaluate() << endl;
                                        //cout << a->shunting() << endl;
                                        cout << "Answer:" << a->evaluate() << endl;
                                        expressions.push_back(expression);
					answers.push_back(a->evaluate());
				}
			}
		}
		if (option == "2") {
                    for (size_t n = 0; n < expressions.size(); n++) {
                        cout << "The expression was: ";
                        cout << expressions[ n ] << " "<< endl;
                        cout << "The answer was: ";
                        cout << answers[n] << " " << endl;
                    }
		}
		if (option == "3") {
			
		}
	}
	
	
}
												  
/*int main()  {
	Expression* e = new Expression("25^5+    56-9^4 *856/  25+log_5:(159)-1896");
	cout << e->shunting() << endl;
	cout << e->evaluate() << endl;
}	*/
