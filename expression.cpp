#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include"expression.h"

using namespace std;

bool isoperator(char a) {
	if((a == '+')||(a== '-')||(a== '*')||(a== '/')) {
		return true;
	}
	return false;
}


string expression::shunting() {
	
	stack<char> ops;
	queue<char> out;

	/*for(int i=0; i < tokens.size(); i++) {
		if (isoperator(tokens[i])) {
			
		}


	}
	*/
	string str = exp;
	return str;
}

string expression::evaluate() {
	string str = exp;
	return str;
}

void expression::setfields(string input) {
	exp = input;
	string::iterator it = input.begin();
	
		for (it = input.begin(); it!=input.end(); it++) {
			tokens.push_back(*it);
		}

}

void expression::getfields() {
	cout << exp << endl << endl;
	for(int i=0; i != tokens.size(); i++) {
		cout << tokens[i] << endl;
	}
}

