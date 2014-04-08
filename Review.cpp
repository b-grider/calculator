#include "Review.h"


string Review::getExpression() {
	return expression.front()
}
string Review::getExpression(int index) {
	return answers.At(index)
}
string Review::getAnswer() {
	return answers.front()
}
string Review::getAnswer(int index) {
	return answers.At(index)
}
string Review::getAll() {
    
}


