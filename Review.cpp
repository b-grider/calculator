#include "Review.h"


string Review::getExpression() {
	return expressions.front();
}
string Review::getExpression(int index) {
	return answers.at(index);
}
string Review::getAnswer() {
	return answers.front();
}
string Review::getAnswer(int index) {
	return answers.at(index);
}
string Review::getAll() {

}


