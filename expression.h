#include<iostream>
#include<string>


using namespace std;

class expression {

	string exp;
	vector<char> tokens;

	//expression(string in, vector<char>& vec) : exp(in), tokens(vec) {}
	
	public : expression() {
		exp = "String literal";
	}

	expression(string in) {
	
		exp = in;
		string::iterator it = in.begin();
	
		for (it = in.begin(); it!=in.end(); it++) {
			tokens.push_back(*it);
		}
	}
	
	void setfields(string);
	void getfields();
	string shunting();
	string evaluate();
	
};


