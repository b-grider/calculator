
/*
shunting yard test
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include"expression.h"

using namespace std;

int main() {

	stack<char> ops;
	queue<char> out;


string input;
cin >> input;


/*string::iterator it = input.begin();
vector<char> tokens;

for(it=input.begin(); it!=input.end(); it++) {
	tokens.push_back(*it);
}

for(int i = 0; i != tokens.size(); i++) {		//TOKENS IS VECTOR OF CHARACTERS
	cout << "!" << tokens[i] << endl;
}
*/

expression exp(input);

exp.getfields();

cout << endl;

};

