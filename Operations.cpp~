#include <iostream>
#include <string>
#include <sstream>
using namespace std;


bool isNegative(string str) {
	if (str[0] == '-') {
		return true;
	}
	return false;
}

bool isIrrational(string str) {
    int i = 0;
    int num;
    while(i < str.length()) {
        if(!(istringstream(str.substr(i, 1)) >> num)) {
            if(str[i] == 'p' && str[i+1] == 'i' || str[i] == 'P' && str[i+1] == 'i' || str[i] == 'p' && str[i+1] == 'I' || str[i] == 'P' && str[i+1] == 'I') {
                return true;
                }
            else if(str[i] == 'e'|| str[i] == 'E') {
                return true;
                }
            else {

                return false;
                }
            }
        else if(istringstream(str.substr(i, 1)) >> num) {
            i++;
        }
    }
}

bool isInteger(string str) {
    string::const_iterator it = str.begin();
	char neg = '-';
    while (it != str.end() && ((std::isdigit(*it))||((*it) == '-'))) ++it;
    return !str.empty() && it == str.end();
}
bool isFraction(string str) {
    int i = 0;
       if((str.find('/') < str.length()) && !((str.find('-') < str.length()) && !isNegative(str)) && !(str.find('+') < str.length()) && !(str.find('*') < str.length())) {
           return true;
        }
		return false;
}
bool isPolynomial(string str) {
    if(!isFraction(str) && (str.find('/')< str.length())) {
		return true;
	}
	if(!isNegative(str) && str.find('-')< str.length()) {
		return true;
	}
	if(str.find('+') < str.length()) {
		return true;
	}
	if(str.find('c') < str.length()) {
		return true;
	}
		return false;
}
bool isLog(string str) {
    if(!isPolynomial(str) && (str.find("log") < str.length())) {
        return true;
    }
	return false;
}
bool isPi(string str) {
    int i = 0;
    while(i < str.length()) {
        if((str[i] == 'p' && str[i+1] == 'i') || (str[i] == 'P' && str[i+1] == 'i') || (str[i] == 'p' && str[i+1] == 'I') || (str[i] == 'P' && str[i+1] == 'I')) {
            return true;
         }
        i++;
    }    
}
bool isE(string str) {
    int i = 0;
    while(i < str.length()) {
        if(str[i] == 'e' || str[i] == 'E') {
            return true;
        }
        i++;
    }   
}
string add(string left, string right) { 
    string leftCoefficient, rightCoefficient, finalC, answer;
    int leftC, rightC, final;
    //checks if the left and right operands are of the same type
    if((isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right))) {
        //Dealing with Irrational Numbers
        if(isIrrational(left)) {
            int i = 0;
            leftCoefficient = "";
            int temp;
            while(i < left.length()) {
                if(istringstream(left.substr(i, 1)) >> temp) {
                    leftCoefficient += left[i];
                 
                }
                i++;
            }
            if(leftCoefficient == ""){
                 leftCoefficient = "1";
            }
            i = 0;
            rightCoefficient = "";
            while(i < right.length()) {
                 if(istringstream(right.substr(i, 1)) >> temp) {
                    rightCoefficient += right[i];
                    
                }
                i++;
             }
             if(rightCoefficient == ""){
                 rightCoefficient = "1";
             }
            istringstream(leftCoefficient) >> leftC;
            istringstream(rightCoefficient) >> rightC;
            final = leftC + rightC;
            ostringstream temporary;
            temporary << final;
            finalC = temporary.str();
            if(isPi(left) && isPi(right)) {
                answer = finalC + "pi";
            }
            else if(isE(left) && isE(right)) {
                answer = finalC + "e";
            }
            else if(isPi(left) && isE(right) || isE(left) && isPi(right)) {
                answer = left + " + " + right;
            }
            } 
        else if(isLog(left)) {
          string leftBase, rightBase, leftNum, rightNum, final;
          int i = 4;
          //Specified base for the log
          if(left[3] == '_' ) {
              while(left[i] != ':') {
                  leftBase += left[i];
                  i++;
              }
              i++;
              while(i <= left.length()-1) {
                  leftNum += left[i];
                  i++;
              }
          }
          //This is log base 10
          else if(left[3] == ':') {
              leftBase = "10";
              while(i <= left.length()-1) {
                  leftNum += left[i];
                  i++;
              }
          }
          i = 4;
          if(right[3] == '_' ) {
              while(right[i] != ':') {
                  rightBase += right[i];
                  i++;
              }
              i++;
              while(i <= right.length()-1) {
                  rightNum += right[i];
                  i++;
              }
          }
          //This is log base 10
          else if(right[3] == ':') {
              rightBase = "10";
              while(i <= right.length()-1) {
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
          if(tempLeft == tempRight) {
              
              answer = "log_" + leftBase + ":" + n.str() ; 
          }
          else {
              answer = left + " + " + right;
          }
          
          
        }
        else if(isFraction(left)) {
            string numerator, denominator;
            int i =0;
            string topLeft, topRight, bottomLeft, bottomRight;
            int leftNum, rightNum, leftDenom, rightDenom, finalNum;
            while(left[i] != '/'){
                topLeft += left[i];
                i++;
            }
            i++;
            while(i < left.length()) {
                bottomLeft += left[i];
                i++;
            }
            i = 0;
            while(right[i] != '/'){
                topRight += right[i];
                i++;
            }
            i++;
            while(i < right.length()) {
                bottomRight += right[i];
                i++;
            }
            istringstream(topLeft) >> leftNum;
            istringstream(topRight) >> rightNum;
            istringstream(bottomLeft) >> leftDenom;
            istringstream(bottomRight) >> rightDenom;
            if(leftDenom == rightDenom) {
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
            answer = numerator + "/" + denominator;
        }
        if(isPolynomial(left)) {
            
        }
        if(isInteger(left)) {
            int leftO, rightO, ans;
            istringstream(left) >> leftO;
            istringstream(right) >> rightO;
            ans = leftO + rightO;
            ostringstream t;
            t << ans;
            answer = t.str();
        }
        
    }
    
    else {
      answer = left + " + " + right;  
    }
    return answer; 
}
string subtract(string left, string right) { 
    string leftCoefficient, rightCoefficient, finalC, answer;
    int leftC, rightC, final;
    //checks if the left and right operands are of the same type
    if((isIrrational(left) && isIrrational(right)) || (isFraction(left) && isFraction(right)) || (isInteger(left) && isInteger(right)) || (isLog(left) && isLog(right)) || (isPolynomial(left) && isPolynomial(right))) {
        //Dealing with Irrational Numbers
        if(isIrrational(left)) {
            int i = 0;
            leftCoefficient = "";
            int temp;
            while(i < left.length()) {
                if(istringstream(left.substr(i, 1)) >> temp) {
                    leftCoefficient += left[i];
                 
                }
                i++;
            }
            if(leftCoefficient == ""){
                 leftCoefficient = "1";
            }
            i = 0;
            rightCoefficient = "";
            while(i < right.length()) {
                 if(istringstream(right.substr(i, 1)) >> temp) {
                    rightCoefficient += right[i];
                    
                }
                i++;
             }
             if(rightCoefficient == ""){
                 rightCoefficient = "1";
             }
            istringstream(leftCoefficient) >> leftC;
            istringstream(rightCoefficient) >> rightC;
            final = leftC - rightC;
            ostringstream temporary;
            temporary << final;
            finalC = temporary.str();
            if(isPi(left) && isPi(right)) {
                answer = finalC + "pi";
            }
            else if(isE(left) && isE(right)) {
                answer = finalC + "e";
            }
            else if(isPi(left) && isE(right) || isE(left) && isPi(right)) {
                answer = left + " - " + right;
            }
            } 
        else if(isLog(left)) {
          string leftBase, rightBase, leftNum, rightNum, final;
          int i = 4;
          //Specified base for the log
          if(left[3] == '_' ) {
              while(left[i] != ':') {
                  leftBase += left[i];
                  i++;
              }
              i++;
              while(i <= left.length()-1) {
                  leftNum += left[i];
                  i++;
              }
          }
          //This is log base 10
          else if(left[3] == ':') {
              leftBase = "10";
              while(i <= left.length()-1) {
                  leftNum += left[i];
                  i++;
              }
          }
          i = 4;
          if(right[3] == '_' ) {
              while(right[i] != ':') {
                  rightBase += right[i];
                  i++;
              }
              i++;
              while(i <= right.length()-1) {
                  rightNum += right[i];
                  i++;
              }
          }
          //This is log base 10
          else if(right[3] == ':') {
              rightBase = "10";
              while(i <= right.length()-1) {
                  rightNum += right[i];
                  i++;
              }
          }
          int num, tempLeft, tempRight, tempLNum, tempRNum;
          istringstream(leftBase) >> tempLeft;
          istringstream(rightBase) >> tempRight;
          istringstream(leftNum) >> tempLNum;
          istringstream(rightNum) >> tempRNum;
          num = tempLNum / tempRNum;
          ostringstream n;
          n << num;
          if(tempLeft == tempRight) {
              
              answer = "log_" + leftBase + ":" + n.str() ; 
          }
          else {
              answer = left + " - " + right;
          }
          
          
        }
        else if(isFraction(left)) {
            string numerator, denominator;
            int i =0;
            string topLeft, topRight, bottomLeft, bottomRight;
            int leftNum, rightNum, leftDenom, rightDenom, finalNum;
            while(left[i] != '/'){
                topLeft += left[i];
                i++;
            }
            i++;
            while(i < left.length()) {
                bottomLeft += left[i];
                i++;
            }
            i = 0;
            while(right[i] != '/'){
                topRight += right[i];
                i++;
            }
            i++;
            while(i < right.length()) {
                bottomRight += right[i];
                i++;
            }
            istringstream(topLeft) >> leftNum;
            istringstream(topRight) >> rightNum;
            istringstream(bottomLeft) >> leftDenom;
            istringstream(bottomRight) >> rightDenom;
            if(leftDenom == rightDenom) {
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
            answer = numerator + "/" + denominator;
        }
        if(isPolynomial(left)) {
            
        }
        if(isInteger(left)) {
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
