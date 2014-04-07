#ifndef REVIEW_H
#define REVIEW_H
#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class Review {
    private:
       vector<string> expressions;
       vector<string> answers;
       int index;
    public:
        string getExpression();
        string getExpression(int index);
        string getAnswer();
        string getAnswer(int index);
        string getAll();
    
};

#endif	/* REVIEW_H */



