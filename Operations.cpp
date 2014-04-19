#include <iostream>
#include <string>
#include <sstream>
#include "Operations.h"
#include <exception>
#include <vector>
#include <math.h>
#include "Operations.h"

using namespace std;
class divideByZero : public exception {
	virtual const char* what() const throw()
	{
		return "You cannot divide by zero";
	}
} divideByZero;
class negativeEvenRoot : public exception {
	virtual const char* what() const throw()
	{
		return "can't take even root of a negative number";
	}
} negativeRoot;
class invalidIrrational : public exception {
	virtual const char* what() const throw()
	{
		return "You have entered an invalid irrational number";
	}
} invalidIrr;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
string simplifyLog(int base, int num) {
        int originalNum = num;
	//if the left log can be simplified to an int
	//if the fractions can be simplified
	vector<int> primeFactors;
	int j = -1;
	int counter = 0;
	int d, ans;
	//int gcf = 1;
	d = gcd(base, num);
	if (num == 1) {
		return "0";
	}
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			primeFactors.push_back(i);
			j++;
			if (primeFactors.at(j) == base) {
				counter++;
				primeFactors.pop_back();
				j--;
			}
		}
	}
	int temp = 1;
	while (!primeFactors.empty()) {
		temp = primeFactors.back();
		temp *= temp;
		primeFactors.pop_back();
	}
	ostringstream remaining, b, c;
	remaining << temp;
	b << base;
	c << counter;
	if (temp == 1) {
		return c.str();
	}
	if (counter != 0) {
		return c.str() + " + log_" + b.str() + ":" + remaining.str();
	}
	//if counter == 0
	else {
		ostringstream b;
		ostringstream n;
		b << base;
		n << originalNum;
		return "log_" + b.str() + ":" + n.str();
	}
}
string simplifyRoot(double root, double base) {
	double ans;
	string answer;
	ans = pow(base, (1 / root));
	ostringstream a;
	a << ans;
	if (ans == (int) ans) {
		answer = a.str();
	}
	else {
		int outside = 1;
		int inside = (int)base;
		int d = (int)root;
		while (d * d <= inside) {
			if (inside % (d * d) == 0) { // inside_root evenly divisible by d * d
				inside = inside / (d * d);
				outside = outside * d;
			}
			else {
				d = d + 1;
			}
		}
		ostringstream o, i, n;
		o << outside;
		i << inside;
		n << root;
		answer = o.str() + "*"+ n.str() + "rt:" + i.str();
	}
	return answer;
}
bool isNegative(string str) {
	if (str[0] == '-') {
		return true;
	}
	return false;
}
bool isIrrational(string str) {
	int i = 0;
	int num;
	while (i < str.length()) {
		if (!(istringstream(str.substr(i, 1)) >> num)) {
			if (str.find("pi") < str.length() || str.find("pI") < str.length() || str.find("Pi") < str.length() || str.find("PI") < str.length()) {
				return true;
			}
			else if (str.find("e") < str.length() || str.find("E") < str.length()) {
				return true;
			}
			else {

				return false;
			}
		}
		else if (istringstream(str.substr(i, 1)) >> num) {
			i++;
		}
                    return false;
	}
}
bool isInteger(string str) {
    if(isInteger1(str) || isInteger2(str)) {
        return true;
    }
    else {
        return false;
    }
}
bool isInteger1(string str) {
    int num;
    if(istringstream(str) >> num && !isPolynomial(str) && !isFraction(str) && !isNthRoot(str) && !isLog(str)) {
        return true;
    }
    else {
        return false;
    }
}
bool isInteger2(string str) {
	string::const_iterator it = str.begin();
	char neg = '-';
	while (it != str.end() && ((isdigit(*it)) || ((*it) == '-') || (*it) == ' ')) ++it;
	return !str.empty() && it == str.end();

}
bool isFraction(string str) {
	int i = 0;
	if ((str.find('/') < str.length()) && !((str.find('-') < str.length()) && !isNegative(str)) && !(str.find('+') < str.length()) && !(str.find('*') < str.length())){
		return true;
	}
	return false;
}
bool isPolynomial(string str) {
	if (!isFraction(str) && (str.find('/')< str.length())) {
		return true;
	}
	if (!isNegative(str) && str.find('-')< str.length()) {
		return true;
	}
	if (str.find('+') < str.length()) {
		return true;
	}
	if (str.find('c') < str.length()) {
		return true;
	}
	return false;
}
bool isLog(string str) {
	if (!isPolynomial(str) && (str.find("log") < str.length())) {
		return true;
	}
        else {
            return false;
        }
}
bool isNthRoot(string str) {
	if (str.find("rt:") < str.length() || str.find("Rt:") < str.length() || str.find("rT:") < str.length() || str.find("RT:") < str.length()) {
		return true;
	}
	return false;
}
bool isSqrt(string str){
	if (str.find("sqrt:") < str.length()){
		return true;
	}
	return false;
}
bool isPi(string str) {
	int i = 0;
	while (i < str.length()) {
		if ((str[i] == 'p' && str[i + 1] == 'i') || (str[i] == 'P' && str[i + 1] == 'i') || (str[i] == 'p' && str[i + 1] == 'I') || (str[i] == 'P' && str[i + 1] == 'I')) {
			return true;
		}
		i++;
	}
}
bool isE(string str) {
	int i = 0;
	while (i < str.length()) {
		if (str[i] == 'e' || str[i] == 'E') {
			return true;
		}
		i++;
	}
}
bool isExponent(string str) {
    if(str.find("^") < str.length()) {
        return true;
    }
    else {
        return false;
    }
}
string add(string left, string right) {
	string rightRoot, leftRoot, leftB, rightB, leftCoefficient, rightCoefficient, leftExponent, rightExponent, finalC, answer, simplifiedLeft, simplifiedRight;
	int leftC, rightC, final, leftIndex, rightIndex, originalLength, leftO, rightO, tempLEx, tempREx;
	//checks if the left and right operands are of the same type
	if ((isNthRoot(left) && isNthRoot(right)) || (isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right)) || (isInteger(left) && isFraction(right)) ||(isFraction(left) && isInteger(right))) {
		//dealing with roots
		if (isNthRoot(left)){
			if (isSqrt(left)){
				leftRoot = "2";
				int i = 5;
				while (i < left.length()){
					if (left[i] == '-') throw negativeRoot;
					else {
						leftB += left[i];
					}
					i++;

				}

			}
			if (isSqrt(right)){
				rightRoot = "2";
				int i = 5;
				while (i < right.length()){
					if (right[i] == '-') throw negativeRoot;
					else {
						rightB += right[i];
					}
					i++;

				}

			}
			if (!isSqrt(right)){
				int temp;
				int i = 0;
				while (right[i] != 'r'){
					rightRoot += right[i];
					i++;
				}
				i += 3;
				istringstream(rightRoot) >> temp;
				if ((temp % 2 == 0) && right[i] == '-') throw negativeRoot;
				else {
					while (i < right.length()){
						rightB += right[i];
					}
				}

			}
			if (!isSqrt(left)){
				int temp;
				int i = 0;
				while (left[i] != 'r'){
					leftRoot += left[i];
					i++;
				}
				i += 3;
				istringstream(rightRoot) >> temp;
				if ((temp % 2 == 0) && right[i] == '-') throw negativeRoot;
				else {
					while (i < left.length()){
						leftB += left[i];
					}
				}
			}
			double tempLB, tempRB;
			double tempLR, tempRR;
			int tempCL, tempCR;


			istringstream(leftB) >> tempLB;
			istringstream(leftRoot) >> tempLR;
			istringstream(rightB) >> tempRB;
			istringstream(rightRoot) >> tempRR;
			//tries to simplify the root if possible   
			simplifiedLeft = simplifyRoot(tempLR, tempLB);
			simplifiedRight = simplifyRoot(tempRR, tempRB);



			if (isInteger(simplifiedLeft)) {
				left = simplifiedLeft;
				istringstream(left) >> leftO;
			}
			if (isInteger(simplifiedRight)) {
				right = simplifiedRight;
				istringstream(left) >> rightO;
			}
			if (isInteger(simplifiedLeft) && isInteger(simplifiedRight)) {
				answer = leftO + rightO;
			}
			else if (!isInteger(simplifiedLeft) && !isInteger(simplifiedRight)) {
				int i = 0;
				while (simplifiedLeft[i] != '*'){
					leftCoefficient += simplifiedLeft[i];
					i++;
				}
				i = 0;
				while (simplifiedRight[i] != '*'){
					rightCoefficient += simplifiedRight[i];
					i++;
				}
				istringstream(leftCoefficient) >> tempCL;
				istringstream(rightCoefficient) >> tempCR;

				final = tempCL + tempCR;
				ostringstream temp;
				temp << final;
				finalC = temp.str();

				if (tempLR == tempRR && tempRB == tempLB) {
					string a = finalC + "*" + leftRoot + "rt:" + leftB;
					answer = a;
				}
				else {
					answer = left + " + " + right;
				}
			}
			else {
				answer = simplifiedLeft + " + " + simplifiedRight;
			}
		}
		//Dealing with Irrational Numbers
		else if (isIrrational(left)) {
			int i = 0;
			leftCoefficient = "";
			leftExponent = "";
			int temp;
			originalLength = left.length();
			while (i < left.length()) {
				if (istringstream(left.substr(i, 1)) >> temp) {
					leftCoefficient += left[i];

				}
				else {
					break;
				}
				i++;
			}
			if (leftCoefficient == ""){
				leftCoefficient = "1";
			}
			i = 0;
			rightCoefficient = "";
			rightExponent = "";
			while (i < right.length()) {
				if (istringstream(right.substr(i, 1)) >> temp) {
					rightCoefficient += right[i];

				}
				else {
					break;
				}
				i++;
			}
			if (rightCoefficient == ""){
				rightCoefficient = "1";
			}
			istringstream(leftCoefficient) >> leftC;
			istringstream(rightCoefficient) >> rightC;
			//adds the coefficients
			final = leftC + rightC;
			//converts coefficient to string
			ostringstream temporary;
			temporary << final;
			finalC = temporary.str();
			//if both operands contain pi
			if (isPi(left) && isPi(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent = "1";
				}
				if (rightExponent == "") {
					rightExponent = "1";
				}
				istringstream(leftExponent) >> tempLEx;
				istringstream(rightExponent) >> tempREx;
				if ((tempLEx == tempREx) && !(leftExponent == "" && rightExponent == "")) {
					answer = finalC + "pi" + "^" + leftExponent;
				}
				else if ((tempLEx == tempREx) && (leftExponent == "" && rightExponent == "")){
					answer = finalC + "pi";
				}
				else
					answer = left + " + " + right;
			}
			//if both operands contain e
			else if (isE(left) && isE(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent = "1";
				}
				if (rightExponent == "") {
					rightExponent = "1";
				}
				istringstream(leftExponent) >> tempLEx;
				istringstream(rightExponent) >> tempREx;

				if ((tempLEx == tempREx) && (leftExponent != "" && rightExponent != "")) {
					answer = finalC + "e" + "^" + leftExponent;
				}
				else if ((tempLEx == tempREx) && (leftExponent == "" && rightExponent == "")){
					answer = finalC + "e";
				}
				else
					answer = left + " + " + right;
			}
			//if the operands cannot be added and simplified, concatenate them
			else if (isPi(left) && isE(right) || isE(left) && isPi(right)) {
				answer = left + " + " + right;
			}
			else {
				throw invalidIrr;
			}
		}
		//Dealing with logs
		else if (isLog(left)) {
			string leftBase, rightBase, leftNum, rightNum, final;
			int i = 4;
			//Specified base for the log
			if (left[3] == '_') {
				while (left[i] != ':') {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftBase += left[i];
					i++;
				}
				i++;
				while (i <= left.length() - 1) {
					leftNum += left[i];
					i++;
				}
			}
			//This is log base 10
			else if (left[3] == ':') {
				leftBase = "10";
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftNum += left[i];
					i++;
				}
			}
			i = 4;
			if (right[3] == '_') {
				while (right[i] != ':') {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightBase += right[i];
					i++;
				}
				i++;
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			//This is log base 10
			else if (right[3] == ':') {
				rightBase = "10";
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			int num, tempLeft, tempRight, tempLNum, tempRNum;
			istringstream(leftBase) >> tempLeft;
			istringstream(rightBase) >> tempRight;
			istringstream(leftNum) >> tempLNum;
			istringstream(rightNum) >> tempRNum;
			//simplifies the logs to numbers if possible.
			//if the log cannot be simplified it will return the log as it was.
			simplifiedLeft = simplifyLog(tempLeft, tempLNum);
			simplifiedRight = simplifyLog(tempRight, tempRNum);
			if (isInteger(simplifiedLeft)) {
				left = simplifiedLeft;
				istringstream(left) >> leftO;
			}
			if (isInteger(simplifiedRight)) {
				right = simplifiedRight;
				istringstream(left) >> rightO;
			}
			num = tempLNum * tempRNum;
			if (isInteger(simplifiedLeft) && isInteger(simplifiedRight)) {
				answer = leftO - rightO;
			}
			else if (!isInteger(simplifiedLeft) && !isInteger(simplifiedRight)) {
				if (tempLeft == tempRight) {
					string a = simplifyLog(tempLeft, num);
					answer = a;
				}
				else {
					answer = left + " + " + right;
				}
			}
			else {
				answer = simplifiedLeft + " + " + simplifiedRight;
			}
		}
		else if (isFraction(left) && isFraction(right)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (left[i] != '/'){
				topLeft += left[i];
				i++;
			}
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}
			i = 0;
			while (right[i] != '/'){
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}
                        
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			if(leftDenom == 0 || rightDenom == 0) {
                            throw divideByZero;
                        }
                        //if the fractions can be simplified
			int d, e;
			d = gcd(leftNum, leftDenom);
			leftNum /= d;
			leftDenom /= d;
			e = gcd(rightNum, rightDenom);
			rightNum /= e;
			rightDenom /= e;
			if (leftDenom == rightDenom) {
				finalNum = leftNum + rightNum;
				ostringstream temp;
				temp << finalNum;
				numerator = temp.str();
				denominator = bottomLeft;
			}
			else {
				leftNum *= rightDenom;
				rightNum *= leftDenom;
				leftDenom *= rightDenom;
				finalNum = leftNum + rightNum;
				ostringstream numer;
				numer << finalNum;
				numerator = numer.str();
				ostringstream denom;
				denom << leftDenom;
				denominator = denom.str();

			}
			if (leftDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
                else if (isInteger(left) && isInteger(right)) {
					int leftO, rightO, ans;
					istringstream(left) >> leftO;
					istringstream(right) >> rightO;
					ans = leftO + rightO;
					ostringstream t;
					t << ans;
					answer = t.str();
				}
                else if (isInteger(left) && isFraction(right)) {
                        string numerator, denominator;
                        int i = 0;
                        string topLeft, topRight, bottomLeft, bottomRight;
                        int leftNum, rightNum, leftDenom, rightDenom, finalNum;
                        while (right[i] != '/'){
                                topRight += right[i];
                                i++;
                        }
                        i++;
                        while (i < right.length()) {
                                bottomRight += right[i];
                                i++;
                        }
                        topLeft = left;
                        bottomLeft = "1";
                        istringstream(topLeft) >> leftNum;
                        istringstream(topRight) >> rightNum;
                        istringstream(bottomLeft) >> leftDenom;
                        istringstream(bottomRight) >> rightDenom;
						if (rightDenom < 0) {
							rightDenom *= -1;
							rightNum *= -1;
						}
						if (leftDenom < 0) {
							leftDenom *= -1;
							leftNum *= -1;
						}
                        if(rightDenom == 0) {
                            throw divideByZero;
                        }
                        //if the fractions can be simplified
                        int d, e;
                        e = gcd(rightNum, rightDenom);
                        rightNum /= e;
                        rightDenom /= e;
                        leftNum *= rightDenom;
                        leftDenom *= rightDenom;
                        finalNum = leftNum + rightNum;
                        e = gcd(finalNum, rightDenom);
                        finalNum /= e;
                        rightDenom /= e;
						if (rightDenom < 0) {
							rightDenom *= -1;
							finalNum *= -1;
						}
                        ostringstream numer;
                        numer << finalNum;
                        numerator = numer.str();
                        ostringstream denom;
                        denom << rightDenom;
                        denominator = denom.str();
						if (rightDenom == 1) {
							answer = numerator;
						}
						else {
							answer = numerator + "/" + denominator;
						}
				}
                else if (isInteger(right) && isFraction(left)) {
                        string numerator, denominator;
                        int i = 0;
                        string topLeft, topRight, bottomLeft, bottomRight;
                        int leftNum, rightNum, leftDenom, rightDenom, finalNum;
                        while (left[i] != '/'){
                                topLeft += left[i];
                                i++;
                        }
                        i++;
                        while (i < left.length()) {
                                bottomLeft += left[i];
                                i++;
                        }

                        topRight = right;
                        bottomRight = "1";
                        istringstream(topLeft) >> leftNum;
                        istringstream(topRight) >> rightNum;
                        istringstream(bottomLeft) >> leftDenom;
                        istringstream(bottomRight) >> rightDenom;
						if (rightDenom < 0) {
							rightDenom *= -1;
							rightNum *= -1;
						}
						if (leftDenom < 0) {
							leftDenom *= -1;
							leftNum *= -1;
						}
                        if(leftDenom == 0) {
                            throw divideByZero;
                        }
                        //if the fractions can be simplified
                        int d, e;
                        e = gcd(leftNum, leftDenom);
                        leftNum /= e;
                        leftDenom /= e;
                        rightNum *= leftDenom;
                        rightDenom *= leftDenom;
                        finalNum = leftNum + rightNum;
                        e = gcd(finalNum, leftDenom);
                        finalNum /= e;
                        leftDenom /= e;
						if (leftDenom < 0) {
							leftDenom *= -1;
							finalNum *= -1;
						}
                        ostringstream numer;
                        numer << finalNum;
                        numerator = numer.str();
                        ostringstream denom;
                        denom << leftDenom;
                        denominator = denom.str();
						if (leftDenom == 1) {
							answer = numerator;
						}
						else {
							answer = numerator + "/" + denominator;
						}
                }
        }
	else {
		answer = left + " + " + right;
	}
    return answer;
}
string subtract(string left, string right) {
	string rightRoot, leftRoot, a, leftB, rightB, leftCoefficient, rightCoefficient, leftExponent, rightExponent, finalC, answer, simplifiedLeft, simplifiedRight;
	int leftC, rightC, final, leftIndex, rightIndex, originalLength, leftO, rightO, tempLEx, tempREx;
	//checks if the left and right operands are of the same type
	if (((isNthRoot(left) && isNthRoot(right)) || isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right)) || (isInteger(left) && isFraction(right)) || (isFraction(left) && isInteger(right))) {
		//dealing with roots
		if (isNthRoot(left)){
			if (isSqrt(left)){
				leftRoot = "2";
				int i = 5;
				while (i < left.length()){
					if (left[i] == '-') throw negativeRoot;
					else {
						leftB += left[i];
					}
					i++;

				}

			}
			if (isSqrt(right)){
				rightRoot = "2";
				int i = 5;
				while (i < right.length()){
					if (right[i] == '-') throw negativeRoot;
					else {
						rightB += right[i];
					}
					i++;

				}

			}
			if (!isSqrt(right)){
				int i = 0;
				while (right[i] != 'r'){
					rightRoot += right[i];
					i++;
				}
				i += 3;
				while (i < right.length()){
					rightB += right[i];
				}
			}
			if (!isSqrt(left)){
				int i = 0;
				while (left[i] != 'r'){
					leftRoot += left[i];
					i++;
				}
				i += 3;
				while (i < left.length()){
					leftB += left[i];
				}
			}
			double tempLB, tempRB;
			double tempLR, tempRR;
			int tempCL, tempCR;


			istringstream(leftB) >> tempLB;
			istringstream(leftRoot) >> tempLR;
			istringstream(rightB) >> tempRB;
			istringstream(rightRoot) >> tempRR;
			//tries to simplify the root if possible   
			simplifiedLeft = simplifyRoot(tempLR, tempLB);
			simplifiedRight = simplifyRoot(tempRR, tempRB);



			if (isInteger(simplifiedLeft)) {
				left = simplifiedLeft;
				istringstream(left) >> leftO;
			}
			if (isInteger(simplifiedRight)) {
				right = simplifiedRight;
				istringstream(left) >> rightO;
			}
			if (isInteger(simplifiedLeft) && isInteger(simplifiedRight)) {
				answer = leftO + rightO;
			}
			else if (!isInteger(simplifiedLeft) && !isInteger(simplifiedRight)) {
				int i = 0;
				while (simplifiedLeft[i] != '*'){
					leftCoefficient += simplifiedLeft[i];
					i++;
				}
				i = 0;
				while (simplifiedRight[i] != '*'){
					rightCoefficient += simplifiedRight[i];
					i++;
				}
				istringstream(leftCoefficient) >> tempCL;
				istringstream(rightCoefficient) >> tempCR;

				final = tempCL - tempCR;
				ostringstream temp;
				temp << final;
				finalC = temp.str();

				if (tempLR == tempRR && tempLB == tempRB) {
					string a = finalC + "*" + leftRoot + "rt:" + leftB;
					answer = a;
				}
				else {
					answer = left + " - " + right;
				}
			}
			else {
				answer = simplifiedLeft + " - " + simplifiedRight;
			}
		}
		//Dealing with Irrational Numbers
		if (isIrrational(left)) {
			int i = 0;
			leftCoefficient = "";
			leftExponent = "";
			int temp;
			while (i < left.length()) {
				if (istringstream(left.substr(i, 1)) >> temp) {
					leftCoefficient += left[i];

				}
				else {
					break;
				}
				i++;
			}
			if (leftCoefficient == ""){
				leftCoefficient = "1";
			}
			i = 0;
			rightCoefficient = "";
			rightExponent = "";
			while (i < right.length()) {
				if (istringstream(right.substr(i, 1)) >> temp) {
					rightCoefficient += right[i];
				}
				else {
					break;
				}
				i++;
			}
			if (rightCoefficient == ""){
				rightCoefficient = "1";
			}
			istringstream(leftCoefficient) >> leftC;
			istringstream(rightCoefficient) >> rightC;
			final = leftC - rightC;
			ostringstream temporary;
			temporary << final;
			finalC = temporary.str();
			if (isPi(left) && isPi(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent = "1";
				}
				if (rightExponent == "") {
					rightExponent = "1";
				}
				istringstream(leftExponent) >> tempLEx;
				istringstream(rightExponent) >> tempREx;
				if ((tempLEx == tempREx) && !(leftExponent == "" && rightExponent == "")) {
					answer = finalC + "pi" + "^" + leftExponent;
				}
				else if ((tempLEx == tempREx) && (leftExponent == "" && rightExponent == "")){
					answer = finalC + "pi";
				}
				else
					answer = left + " - " + right;
			}
			else if (isE(left) && isE(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent = "1";
				}
				if (rightExponent == "") {
					rightExponent = "1";
				}
				istringstream(leftExponent) >> tempLEx;
				istringstream(rightExponent) >> tempREx;
				if ((tempLEx == tempREx) && !(leftExponent == "" && rightExponent == "")) {
					answer = finalC + "e" + "^" + leftExponent;
				}
				else if ((tempLEx == tempREx) && (leftExponent == "" && rightExponent == "")){
					answer = finalC + "e";
				}
				else
					answer = left + " - " + right;
			}
			else if (isPi(left) && isE(right) || isE(left) && isPi(right)) {
				answer = left + " - " + right;
			}
			else {
				throw invalidIrr;
			}
		}
		else if (isLog(left)) {
			string leftBase, rightBase, leftNum, rightNum, final;
			int i = 4;
			//Specified base for the log
			if (left[3] == '_') {
				while (left[i] != ':') {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftBase += left[i];
					i++;
				}
				i++;
				while (i <= left.length() - 1) {
					leftNum += left[i];
					i++;
				}
			}
			//This is log base 10
			else if (left[3] == ':') {
				leftBase = "10";
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftNum += left[i];
					i++;
				}
			}
			i = 4;
			if (right[3] == '_') {
				while (right[i] != ':') {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightBase += right[i];
					i++;
				}
				i++;
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			//This is log base 10
			else if (right[3] == ':') {
				rightBase = "10";
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			int num, tempLeft, tempRight, tempLNum, tempRNum;
			istringstream(leftBase) >> tempLeft;
			istringstream(rightBase) >> tempRight;
			istringstream(leftNum) >> tempLNum;
			istringstream(rightNum) >> tempRNum;
			simplifiedLeft = simplifyLog(tempLeft, tempLNum);
			simplifiedRight = simplifyLog(tempRight, tempRNum);
			if (isInteger(simplifiedLeft)) {
				left = simplifiedLeft;
				istringstream(left) >> leftO;
			}
			if (isInteger(simplifiedRight)) {
				right = simplifiedRight;
				istringstream(left) >> rightO;
			}
			if (tempLNum % tempRNum == 0) {
				num = tempLNum / tempRNum;
			}
			else {
				int p = gcd(tempLNum, tempRNum);
				tempLNum /= p;
				tempRNum /= p;
				ostringstream c, d;
				c << tempLNum;
				d << tempRNum;
				a = "(" + c.str() + "/" + d.str() + ")";
			}
			if (isInteger(simplifiedLeft) && isInteger(simplifiedRight)) {
				answer = leftO - rightO;
			}
			else if (!isInteger(simplifiedLeft) && !isInteger(simplifiedRight)) {
				if (tempLeft == tempRight) {
					answer = "log_" + leftBase + ":" + a;
				}
				else {
					answer = simplifiedLeft + " - " + simplifiedRight;
				}
			}
			else {
				answer = simplifiedLeft + " - " + simplifiedRight;
			}
		}
		else if (isFraction(left) && isFraction(right)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (left[i] != '/'){
				topLeft += left[i];
				i++;
			}
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}
			i = 0;
			while (right[i] != '/'){
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
            if(leftDenom == 0 || rightDenom == 0) {
                throw divideByZero;
            }
                        //if the fractions can be simplified
			int d, e;
			d = gcd(leftNum, leftDenom);
			leftNum /= d;
			leftDenom /= d;
			e = gcd(rightNum, rightDenom);
			rightNum /= e;
			rightDenom /= e;
			if (leftDenom == rightDenom) {
				finalNum = leftNum - rightNum;
				ostringstream temp;
				temp << finalNum;
				numerator = temp.str();
				denominator = bottomLeft;
			}
			else {
				leftNum *= rightDenom;
				rightNum *= leftDenom;
				leftDenom *= rightDenom;
				finalNum = leftNum - rightNum;
				ostringstream numer;
				numer << finalNum;
				numerator = numer.str();
				ostringstream denom;
				denom << leftDenom;
				denominator = denom.str();

			}
			if (leftDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
		else if (isInteger(left) && isFraction(right)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (right[i] != '/'){
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}
			topLeft = left;
			bottomLeft = "1";
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			if (rightDenom == 0) {
				throw divideByZero;
			}
			//if the fractions can be simplified
			int d, e;
			e = gcd(rightNum, rightDenom);
			rightNum /= e;
			rightDenom /= e;
			leftNum *= rightDenom;
			leftDenom *= rightDenom;
			finalNum = leftNum - rightNum;
			e = gcd(finalNum, rightDenom);
			finalNum /= e;
			rightDenom /= e;
			if (rightDenom < 0) {
				rightDenom *= -1;
				finalNum *= -1;
			}
			ostringstream numer;
			numer << finalNum;
			numerator = numer.str();
			ostringstream denom;
			denom << rightDenom;
			denominator = denom.str();
			if (rightDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
		else if (isInteger(right) && isFraction(left)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (left[i] != '/'){
				topLeft += left[i];
				i++;
			}
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}

			topRight = right;
			bottomRight = "1";
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			if (leftDenom == 0) {
				throw divideByZero;
			}
			//if the fractions can be simplified
			int d, e;
			e = gcd(leftNum, leftDenom);
			leftNum /= e;
			leftDenom /= e;
			rightNum *= leftDenom;
			rightDenom *= leftDenom;
			finalNum = leftNum - rightNum;
			e = gcd(finalNum, leftDenom);
			finalNum /= e;
			leftDenom /= e;
			if (leftDenom < 0) {
				leftDenom *= -1;
				finalNum *= -1;
			}
			ostringstream numer;
			numer << finalNum;
			numerator = numer.str();
			ostringstream denom;
			denom << leftDenom;
			denominator = denom.str();
			if (leftDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
        else if (isInteger(left) && isInteger(right)) {
			int leftO, rightO, ans;
			istringstream(left) >> leftO;
			istringstream(right) >> rightO;
			ans = leftO - rightO;
			ostringstream t;
			t << ans;
			answer = t.str();
		}
	}
	else {
		answer = left + " - " + right;
	}
	return answer;
}
string multiply(string left, string right) {
	string leftCoefficient, leftRoot, rightRoot, leftB, rightB, rightCoefficient, finalC, answer, leftExponent, rightExponent;
	int leftC, rightC, final;
	double leftex, rightex, leftco, rightco, finalco, finalex;
	//checks if the left and right operands are of the same type
	if (((isNthRoot(left) && isNthRoot(right)) || isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right)) || (isInteger(left) && isFraction(right)) || (isFraction(left) && isInteger(right))) {
		//dealing with roots
		if (isNthRoot(left)){
			if (isSqrt(left)){
				leftRoot = "2";
				int i = 5;
				while (i < left.length()){
					if (left[i] == '-') {
						throw negativeRoot;
					}
					else {
						leftB += left[i];
					}
					i++;

				}

			}
			if (isSqrt(right)){
				rightRoot = "2";
				int i = 5;
				while (i < right.length()){
					if (right[i] == '-') throw negativeRoot;
					else {
						rightB += right[i];
					}
					i++;

				}

			}
			if (!isSqrt(right)){
				int i = 0;
				while (right[i] != 'r'){
					rightRoot += right[i];
					i++;
				}
				i += 3;
				while (i < right.length()){
					rightB += right[i];
				}
			}
			if (!isSqrt(left)){
				int i = 0;
				while (left[i] != 'r'){
					leftRoot += left[i];
					i++;
				}
				i += 3;
				while (i < left.length()){
					leftB += left[i];
				}
			}
		}

		//PARSE EXPONENTS
		leftExponent = "";
		rightExponent = "";

		//PARSE EXPONENTS
        //dealing with irrationals
		if (isPi(left) && isPi(right)) {
			int i = 0;
			while (i < left.length()) {
				if (left.substr(i, 1) == "^") {
					leftExponent += left[i + 1];
				}
				i++;
			}
			i = 0;
			while (i < right.length()) {
				if (right.substr(i, 1) == "^") {
					rightExponent += right[i + 1];
				}
				i++;
			}
			if (leftExponent == "") {
				leftExponent = "1";
			}
			if (rightExponent == "") {
				rightExponent = "1";
			}
			//PARSE COEFFICIENTS


			//PARSE COEFFICIENTS

			i = 0;
			leftCoefficient = "";
			int temp;
			//string tempchar;
			if (isNegative(left)) {	//If left is negative
				leftCoefficient = "-";	//make the leftcoeff start with a "-"
				i++;	//increment i
			}
			while (i < left.length()) {
				if (istringstream(left.substr(i, 1)) >> temp && !((left[i] == 'p') || (left[i] == 'P'))) {	//if this character of left is an int
					leftCoefficient += left[i];	//concatenate to leftcoefficient string (handles multi digit ints)
					i++;
				}
				else {
					break;
				}
			}
			if (leftCoefficient == ""){	//if left coeff is 1 (i.e. "pi")
				leftCoefficient = "1";	//leftcoefficient is 1;
			}
			//cout << leftCoefficient << endl;
			i = 0;
			rightCoefficient = "";
			if (isNegative(right)) {	//If left is negative
				rightCoefficient = "-";	//make the leftcoeff start with a "-"
				i++;	//increment i
			}
			while (i < right.length()) {
				if (istringstream(right.substr(i, 1)) >> temp && !((right[i] == 'p') || (right[i] == 'P'))) {	//if this character of right is an int
					rightCoefficient += right[i];	//concatenate to rightcoefficient string (handles multidigit numbers)
					i++;
				}
				else {
					break;
				}
			}
			if (rightCoefficient == ""){	//if right coeff is 1 (i.e. "pi") //rightCoefficient is 1;
				rightCoefficient = "1";	//make rightCoefficient 1
			}
			istringstream(leftExponent) >> leftex;
			istringstream(rightExponent) >> rightex;
			istringstream(leftCoefficient) >> leftco;
			istringstream(rightCoefficient) >> rightco;
			finalco = leftco*rightco;
			finalex = leftex + rightex;

			stringstream s;
			stringstream t;

			s << finalco;
			t << finalex;

			//cout << s.str() << endl;
			//cout << t.str() << endl;

			answer = s.str() + "pi^" + t.str();
		}
		//Dealing with Irrational Numbers
		//PARSE COFFICIENTS OF IRRATIONALS NOW
		if (isIrrational(left) && !(isPi(left) && isPi(right))) {
			int i = 0;
			leftCoefficient = "";
			int temp;
			if (isNegative(left)) {	//If left is negative
				leftCoefficient = "-";	//make the leftcoeff start with a "-"
				i++;	//increment i
			}
			while (i < left.length()) {
				if (istringstream(left.substr(i, 1)) >> temp) {	//if this character of left is an int
					leftCoefficient += left[i];	//concatenate to leftcoefficient string (handles multi digit ints)
				}
				i++;
			}
			if (leftCoefficient == ""){	//if left coeff is 1 (i.e. "pi")
				leftCoefficient = "1";	//leftcoefficient is 1;
			}
			i = 0;
			rightCoefficient = "";
			if (isNegative(right)) {	//If left is negative
				rightCoefficient = "-";	//make the leftcoeff start with a "-"
				i++;	//increment i
			}
			while (i < right.length()) {
				if (istringstream(right.substr(i, 1)) >> temp) {	//if this character of right is an int
					rightCoefficient += right[i];	//concatenate to rightcoefficient string (handles multidigit numbers)

				}
				i++;
			}
			if (rightCoefficient == ""){	//if right coeff is 1 (i.e. "pi") //rightCoefficient is 1;
				rightCoefficient = "1";	//make rightCoefficient 1
			}
			istringstream(leftCoefficient) >> leftC;
			istringstream(rightCoefficient) >> rightC;	//write the coefficients to ints; we can handle them and multiply now
			final = leftC * rightC;	//final gets the product of leftC and rightC
			ostringstream temporary;
			temporary << final;	//writes product of coefficients to a stringstream
			finalC = temporary.str();	//finalC gets the string of temporary stringstream
			if (isPi(left) && isPi(right)) {
				answer = finalC + "pi";
			}
			else if (isE(left) && isE(right)) {
				answer = finalC + "e";
			}
			else if (isPi(left) && isE(right) || isE(left) && isPi(right)) {
				answer = left + " + " + right;
			}
		}
		else if (isLog(left)) {	//BOTH OPERANDS ARE LOGS
			string leftBase, rightBase, leftNum, rightNum, final;
			char signL, signR;
			if (isNegative(left)) {
				signL = '-';
			}
			else {
				signL = '+';
			}
			int i = 4;
			//Specified base for the log
			if (left[3] == '_') {	//about to parse the base
				while (left[i] != ':') {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }//while there are still digits to parse
					leftBase += left[i];	//concatenate base string
					i++;	//increment i
				}
				i++;	//SKIP OVER char ':'
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }//Parse the remaining digits
					leftNum += left[i];
					i++;
				}
			}
			//This is log base 10
			else if (left[3] == ':') {
				leftBase = "10";	//If no base specified, its base 10
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftNum += left[i];	//parse num
					i++;
				}
			}
			i = 4;
			if (right[3] == '_') {
				while (right[i] != ':') {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightBase += right[i];
					i++;
				}
				i++;
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			//This is log base 10
			else if (right[3] == ':') {
				rightBase = "10";
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			int num, tempLeft, tempRight, tempLNum, tempRNum;
			istringstream(leftBase) >> tempLeft;
			istringstream(rightBase) >> tempRight;
			istringstream(leftNum) >> tempLNum;
			istringstream(rightNum) >> tempRNum;
			num = tempLNum * tempRNum;
			ostringstream n;
			n << num;
			if (tempLeft == tempRight) {	//IF SAME BASE

				answer = left + "*" + right;
			}
			else {
				answer = left + "*" + right;
			}
		}
		else if (isFraction(left) && isFraction(right)) {
			//cout << "Inside fraction" << endl;
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum, finalDenom;
			while (left[i] != '/'){
				topLeft += left[i];
				i++;
			}
			//cout << topLeft << endl;
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}
			//cout << bottomLeft << endl;

			i = 0;
			while (right[i] != '/'){
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}

			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}

			finalNum = leftNum*rightNum;
			finalDenom = leftDenom*rightDenom;

			ostringstream n;
			ostringstream d;
			n << finalNum;
			string num, den;
			num = n.str();
			d << finalDenom;
			den = d.str();

			answer = num + "/" + den;
			if (num == den) {
				answer = "1";
			}
		}


		if (isPolynomial(left)) {
			answer = "(" + left + ")" + "*" + "(" + right + ")";
		}
		if (isInteger(left) && isInteger(right)) {
			int leftO, rightO, ans;
			istringstream(left) >> leftO;
			istringstream(right) >> rightO;
			ans = leftO * rightO;
			ostringstream t;
			t << ans;
			answer = t.str();
		}
		else if (isInteger(left) && isFraction(right)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (right[i] != '/'){
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}
			topLeft = left;
			bottomLeft = "1";
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			if (rightDenom == 0) {
				throw divideByZero;
			}
			//if the fractions can be simplified
			int d, e;
			e = gcd(rightNum, rightDenom);
			rightNum /= e;
			rightDenom /= e;
			finalNum = leftNum * rightNum;
			e = gcd(finalNum, rightDenom);
			finalNum /= e;
			rightDenom /= e;
			if (rightDenom < 0) {
				rightDenom *= -1;
				finalNum *= -1;
			}
			ostringstream numer;
			numer << finalNum;
			numerator = numer.str();
			ostringstream denom;
			denom << rightDenom;
			denominator = denom.str();
			if (rightDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
		else if (isInteger(right) && isFraction(left)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum;
			while (left[i] != '/'){
				topLeft += left[i];
				i++;
			}
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}

			topRight = right;
			bottomRight = "1";
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightNum;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightDenom;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			if (leftDenom == 0) {
				throw divideByZero;
			}
			//if the fractions can be simplified
			int d, e;
			e = gcd(leftNum, leftDenom);
			leftNum /= e;
			leftDenom /= e;
			finalNum = leftNum * rightNum;
			e = gcd(finalNum, leftDenom);
			finalNum /= e;
			leftDenom /= e;
			if (leftDenom < 0) {
				leftDenom *= -1;
				finalNum *= -1;
			}
			ostringstream numer;
			numer << finalNum;
			numerator = numer.str();
			ostringstream denom;
			denom << leftDenom;
			denominator = denom.str();
			if (leftDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}

	}

	else {
		answer = "(" + left + ")" + " * " + "(" + right + ")";
	}
	return answer;
}
string divide(string left, string right) {
	string rightRoot, leftRoot, leftB, rightB, finalE, leftCoefficient, rightCoefficient, leftExponent, rightExponent, finalC, answer, simplifiedLeft, simplifiedRight;
	int leftC, rightC, final, leftE, rightE, leftIndex, rightIndex, originalLength, leftO, rightO, tempLEx, tempREx;
	//checks if the left and right operands are of the same type
	if (((isNthRoot(left) && isNthRoot(right)) || isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right)) || (isInteger(left) && isFraction(right)) || (isFraction(left) && isInteger(right))) {
		//dealing with roots
		if (isNthRoot(left)){
			if (isSqrt(left)){
				leftRoot = "2";
				int i = 5;
				while (i < left.length()){
					if (left[i] == '-') throw negativeRoot;
					else {
						leftB += left[i];
					}
					i++;

				}

			}
			if (isSqrt(right)){
				rightRoot = "2";
				int i = 5;
				while (i < right.length()){
					if (right[i] == '-') throw negativeRoot;
					else {
						rightB += right[i];
					}
					i++;

				}

			}
			if (!isSqrt(right)){
				int i = 0;
				while (right[i] != 'r'){
					rightRoot += right[i];
					i++;
				}
				i += 3;
				while (i < right.length()){
					rightB += right[i];
				}
			}
			if (!isSqrt(left)){
				int i = 0;
				while (left[i] != 'r'){
					leftRoot += left[i];
					i++;
				}
				i += 3;
				while (i < left.length()){
					leftB += left[i];
				}
			}
		}
		//Dealing with Irrational Numbers
		if (isIrrational(left)) {
			int i = 0;
			leftCoefficient = "";
			leftExponent = "";
			int temp;

			while (i < left.length()) {
				if (istringstream(left.substr(i, 1)) >> temp) {
					leftCoefficient += left[i];

				}
				else
					break;
				i++;
			}
			if (leftCoefficient == "") {
				leftCoefficient = "1";
			}
			i = 0;
			rightCoefficient = "";
			rightExponent = "";
			while (i < right.length()) {
				if (istringstream(right.substr(i, 1)) >> temp) {
					rightCoefficient += right[i];

				}
				else
					break;
				i++;
			}
			if (rightCoefficient == "") {
				rightCoefficient = "1";
			}
			istringstream(leftCoefficient) >> leftC;
			istringstream(rightCoefficient) >> rightC;
			//if the coefficients can be divided into a whole number
			if ((leftC % rightC) == 0) {
				final = leftC / rightC;
				ostringstream temporary;
				temporary << final;
				finalC = temporary.str();
			}
			else {
				int d = gcd(leftC, rightC);
				leftC /= d;
				rightC /= d;
				ostringstream tempNumerator;
				ostringstream tempDenominator;
				tempNumerator << leftC;
				tempDenominator << rightC;
				finalC = tempNumerator.str() + "/" + tempDenominator.str();
			}
			i = 0;
			if (isPi(left) && isPi(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent == "1";
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (rightExponent == "") {
					rightExponent == "1";
				}
				istringstream(leftExponent) >> leftE;
				istringstream(rightExponent) >> rightE;
				final = leftE - rightE;
				ostringstream temporary;
				temporary << final;
				finalE = temporary.str();
				if (final == 0) {
					answer = finalC;
				}
				else {
					answer = finalC + "pi" + "^" + finalE;
				}
			}
			else if (isE(left) && isE(right)) {
				while (i < left.length()) {
					if (left.substr(i, 1) == "^") {
						while (i < left.length()) {
							leftExponent += left[i + 1];
							i++;
						}
					}
					i++;
				}
				if (leftExponent == "") {
					leftExponent == "1";
				}
				i = 0;
				while (i < right.length()) {
					if (right.substr(i, 1) == "^") {
						while (i < right.length()) {
							rightExponent += right[i + 1];
							i++;
						}
					}
					i++;
				}
				if (rightExponent == "") {
					rightExponent == "1";
				}
				istringstream(leftExponent) >> leftE;
				istringstream(rightExponent) >> rightE;
				final = leftE - rightE;
				ostringstream temporary;
				temporary << final;
				finalE = temporary.str();
				if (final == 0) {
					answer = finalC;
				}
				else {
					answer = finalC + "e" + "^" + finalE;
				}
			}
			else if (isPi(left) && isE(right)) {
				if (leftE == 0 && rightE == 0){
					answer = finalC + "pi" + "/" + "e";
				}
				else
					answer = finalC + "pi" + "^" + leftExponent + "/" + "e" + "^" + rightExponent;
			}
			else if (isE(left) && isPi(right)) {
				if (leftE == 0 && rightE == 0)
					answer = finalC + "e" + "/" + "i";
				else
					answer = finalC + "e" + "^" + leftExponent + "/" + "pi" + "^" + rightExponent;
			}
			else {
				throw invalidIrr;
			}
		}
		else if (isLog(left)) {
			string leftBase, rightBase, leftNum, rightNum, final;
			int i = 4;
			//Specified base for the log
			if (left[3] == '_') {
				while (left[i] != ':') {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftBase += left[i];
					i++;
				}
				i++;
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftNum += left[i];
					i++;
				}
			}//This is log base 10
			else if (left[3] == ':') {
				leftBase = "10";
				while (i <= left.length() - 1) {
                                    if(left[i] == '(' || left[i] == ')') {
                                      i++;
                                     }
					leftNum += left[i];
					i++;
				}
			}
			i = 4;
			if (right[3] == '_') {
				while (right[i] != ':') {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightBase += right[i];
					i++;
				}
				i++;
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}//This is log base 10
			else if (right[3] == ':') {
				rightBase = "10";
				while (i <= right.length() - 1) {
                                    if(right[i] == '(' || right[i] == ')') {
                                      i++;
                                     }
					rightNum += right[i];
					i++;
				}
			}
			int num, tempLeft, tempRight, tempLNum, tempRNum;
			istringstream(leftBase) >> tempLeft;
			istringstream(rightBase) >> tempRight;
			istringstream(leftNum) >> tempLNum;
			istringstream(rightNum) >> tempRNum;
			simplifiedLeft = simplifyLog(tempLeft, tempLNum);
			simplifiedRight = simplifyLog(tempRight, tempRNum);
			if (isInteger(simplifiedLeft)) {
				left = simplifiedLeft;
				istringstream(left) >> leftO;
			}
			if (isInteger(simplifiedRight)) {
				right = simplifiedRight;
				istringstream(left) >> rightO;
			}
			//if the two logs simmplify to integers and the integers are evenly divisible
			if (isInteger(simplifiedLeft) && isInteger(simplifiedRight) && (leftO % rightO == 0)) {
				answer = leftO / rightO;
			}
			//if the two logs simplify to integers but the integers are not evenly divisible
			else if (isInteger(simplifiedLeft) && isInteger(simplifiedRight) && !(leftO % rightO == 0)) {
				int a = gcd(leftO, rightO);
				ostringstream n;
				ostringstream d;
				leftO /= a;
				rightO /= a;
				n << leftO;
				d << rightO;
				answer = n.str() + "/" + d.str();
			}
			else if (!isInteger(simplifiedLeft) && !isInteger(simplifiedRight)) {
				//if the bases are equal
				if (tempLeft == tempRight) {
					answer = "log_" + rightNum + ":" + leftNum;
				}
				else {
					answer = simplifiedLeft + " / " + simplifiedRight;
				}
			}
			else {
				answer = simplifiedLeft + " / " + simplifiedRight;
			}
		}
		else if (isFraction(left) && isFraction(right)) {
			string numerator, denominator;
			int i = 0;
			string topLeft, topRight, bottomLeft, bottomRight;
			int leftNum, rightNum, leftDenom, rightDenom, finalNum, finalDenom;
			while (left[i] != '/') {
				topLeft += left[i];
				i++;
			}
			i++;
			while (i < left.length()) {
				bottomLeft += left[i];
				i++;
			}
			i = 0;
			while (right[i] != '/') {
				topRight += right[i];
				i++;
			}
			i++;
			while (i < right.length()) {
				bottomRight += right[i];
				i++;
			}
			istringstream(topLeft) >> leftNum;
			istringstream(topRight) >> rightDenom;
			istringstream(bottomLeft) >> leftDenom;
			istringstream(bottomRight) >> rightNum;
			if (rightDenom < 0) {
				rightDenom *= -1;
				rightNum *= -1;
			}
			if (leftDenom < 0) {
				leftDenom *= -1;
				leftNum *= -1;
			}
			//if the fractions can be simplified
			int d, e;
			d = gcd(leftNum, leftDenom);
			leftNum /= d;
			leftDenom /= d;
			e = gcd(rightNum, rightDenom);
			rightNum /= e;
			rightDenom /= e;
			finalNum = leftNum * rightNum;
			finalDenom = leftDenom * rightDenom;
			int g = gcd(finalNum, finalDenom);
			finalNum /= g;
			finalDenom /= g;
			if (finalDenom < 0) {
				finalDenom *= -1;
				finalNum *= -1;
			}
			ostringstream numer;
			numer << finalNum;
			numerator = numer.str();
			ostringstream denom;
			denom << finalDenom;
			denominator = denom.str();
			if (finalDenom == 1) {
				answer = numerator;
			}
			else {
				answer = numerator + "/" + denominator;
			}
		}
		if (isInteger(left) && isInteger(right)) {
			int leftO = 0;
			int rightO = 0;
			int ans;
			istringstream(left) >> leftO;
			istringstream(right) >> rightO;
			if (leftO % rightO == 0) {
				ans = leftO / rightO;
				ostringstream t;
				t << ans;
				answer = t.str();
			}
			else {
				int d = gcd(leftO, rightO);
				leftO /= d;
				rightO /= d;
				ostringstream numera;
				ostringstream denomi;
				numera << leftO;
				denomi << rightO;
				answer = numera.str() + "/" + denomi.str();
			}
		}
                else if (isInteger(left) && isFraction(right)) {
                        string numerator, denominator;
                        int i = 0;
                        string topLeft, topRight, bottomLeft, bottomRight;
                        int leftNum, rightNum, leftDenom, rightDenom, finalNum;
                        while (right[i] != '/'){
                                bottomRight += right[i];
                                i++;
                        }
                        i++;
                        while (i < right.length()) {
                                topRight += right[i];
                                i++;
                        }
                        topLeft = left;
                        bottomLeft = "1";
                        istringstream(topLeft) >> leftNum;
                        istringstream(topRight) >> rightNum;
                        istringstream(bottomLeft) >> leftDenom;
                        istringstream(bottomRight) >> rightDenom;
						if (rightDenom < 0) {
							rightDenom *= -1;
							rightNum *= -1;
						}
						if (leftDenom < 0) {
							leftDenom *= -1;
							leftNum *= -1;
						}
                        if(rightDenom == 0) {
                            throw divideByZero;
                        }
                        //if the fractions can be simplified
                        int d, e;
                        d = gcd(rightNum, rightDenom);
                        rightNum /= d;
                        rightDenom /= d;
                        leftDenom *= rightDenom;
                        finalNum = leftNum * rightNum;
                        e = gcd(finalNum, leftDenom);
                        finalNum /= e;
                        leftDenom /= e;
						if (leftDenom < 0) {
							leftDenom *= -1;
							finalNum *= -1;
						}
                        ostringstream numer;
                        numer << finalNum;
                        numerator = numer.str();
                        ostringstream denom;
                        denom << leftDenom;
                        denominator = denom.str();
						if (leftDenom == 1) {
							answer = numerator;
						}
						else {
							answer = numerator + "/" + denominator;
						}
                }
                else if (isInteger(right) && isFraction(left)) {
                        string numerator, denominator;
                        int i = 0;
                        string topLeft, topRight, bottomLeft, bottomRight;
                        int leftNum, rightNum, leftDenom, rightDenom, finalNum;
                        while (left[i] != '/'){
                                topLeft += left[i];
                                i++;
                        }
                        i++;
                        while (i < left.length()) {
                                bottomLeft += left[i];
                                i++;
                        }

                        bottomRight = right;
                        topRight = "1";
                        istringstream(topLeft) >> leftNum;
                        istringstream(topRight) >> rightNum;
                        istringstream(bottomLeft) >> leftDenom;
                        istringstream(bottomRight) >> rightDenom;
						if (rightDenom < 0) {
							rightDenom *= -1;
							rightNum *= -1;
						}
						if (leftDenom < 0) {
							leftDenom *= -1;
							leftNum *= -1;
						}
                        if(leftDenom == 0) {
                            throw divideByZero;
                        }
                        //if the fractions can be simplified
                        int d, e;
                        d = gcd(leftNum, leftDenom);
                        leftNum /= d;
                        leftDenom /= d;
                        rightDenom *= leftDenom;
                        finalNum = leftNum * rightNum;
                        e = gcd(finalNum, rightDenom);
                        finalNum /= e;
                        rightDenom /= e;
						if (rightDenom < 0) {
							rightDenom *= -1;
							finalNum *= -1;
						}
                        ostringstream numer;
                        numer << finalNum;
                        numerator = numer.str();
                        ostringstream denom;
                        denom << rightDenom;
                        denominator = denom.str();
						if (rightDenom == 1) {
							answer = numerator;
						}
						else {
							answer = numerator + "/" + denominator;
						}
                }
	}
	else {
		answer = left + " / " + right;
	}
	return answer;
}
string exponentiate(string left, string right) {
    double b, e;
    istringstream(left) >> b;
    istringstream(right) >> e;
    double answer = pow(b, e);
    ostringstream ans;
    ans << answer;
    return ans.str();
}