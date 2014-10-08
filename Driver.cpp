#include "Driver.h"
#include <iostream>
#include <string>
#include "Operations.h"
#include<iostream>
#include"Expression.h"
#include <vector>
#include<iostream>
#include<string>

using namespace std;

vector<string> expressions;
vector<string> answers;

void mainMenu() {
    cout <<" "<<endl;
    cout << "Welcome to calculator. Enter the number of the desired option below" << endl;
    cout << "(1) Compute new expression" << endl;
    cout << "(2) Review previous expressions and answers" << endl;
    cout << "(3) Help" << endl;
    cout << "(4) Quit" << endl;
    cout <<" "<<endl;
}

void expMenu() {
    cout << "(a) Back " << endl;
    cout << "(b) Quit" << endl;
    cout << "Enter expression:" << endl;
    cout <<" "<<endl;
}

int main() {

    char option ='0';

    char option2 = '0';

    string expression = "0";
    char input[100];

//bool test = isdigit(option);
//
//cout << test << endl;


/*if(isdigit(option) != true){

string ErrorMessage = "Sorry That is not an option please try again";

cout<< Error */

    while(option!=4 && isdigit(option)) { 

    mainMenu();
    cin >> option;
    cout << endl;
    expression = "0";
    int testTwo = ((int) option) - 48;


    if(testTwo!=4 && isdigit(option) ){

    switch(testTwo) {
            case 1:
                    while (expression != "a" && expression != "b") {	
                            expMenu();
                            //cout << expression << endl;
                            cin >> expression;
                            //cin.clear(); //makes getline pause and wait for user input
                            //getline(cin, expression); //gets 100 character sequence from cmd and writes to 				expression
                            //cout << endl;
                            if (expression == "a") {
                                    break;
                            }
                            else if (expression == "b") {
                                    option == 4;
                                    break;
                            }
                            else {
                                    Expression* e = new Expression(expression);
                                    e->shunting();
                                    //cout << e->evaluate() << endl;
                                    string eval, reEval, shunt;
                                    eval = e->evaluate();
                                    reEval = e->reOrder();
                                    delete e;
                                    while (eval.compare(reEval) != 0) {	
                                        Expression* j = new Expression(reEval);
                                        shunt = j->shunting();
                                        eval = j->evaluate();
                                        reEval = j->reOrder();
                                        delete j;
                                    }
                                    expressions.push_back(expression);
                                    answers.push_back(reEval);
                                    cout << "\nAnswer: " << reEval << endl;
                            }
                    }

                    break;
            case 2:

                    for (size_t n = 0; n < expressions.size(); n++) {
                            cout << "The expression was: ";
                            cout << expressions[ n ] << " "<< endl;
                            cout << "The answer was: ";
                            cout << answers[n] << " " << endl;
                        }
                    break;
            case 3:
                cout << "This is the calculator's help menu \n" <<
                        "Here you can reference how your expression must be input into the program. \n" <<
                        "If you would like to input a log you must enter a colon preceding the base you would like for the log to have and a colon before the reset of the log \n" <<
                        " \t Ex. log_2:8 \n" <<
                        "If you would like to input a Nth root or a square root you must enter the number then \" rt:\" followed by the number you would like to take the root of. \n " <<
                        " \t Ex. 2rt:4 - would be the square root of 4 \n" << 
                        " \t Ex. 4rt:16 - would be the fourth root of 16 \n" << 
                        "If you want to enter e or pi simply enter \"e\" or \"pi\" depending on which irrational number you would like."<< endl;
                    break;

            default:
            //Errors:
            //log_4:(1+2)    expressions within logs  (Crashes program)
            //5^(1+2)   Don't know if this should be a large issue, but it should be "5^3" but it
            //outputs"1 +2" (Does not cause a crash, but is a miscalculation)
            //Dividing by 0 causes a crash
            cout<< "hello";
                    break;
            }

      }

     else if(testTwo == 5){
            break;
     }

     else{
            cout<<"Error: Not an option, Please try again"<< endl;
            cout<<" "<< endl;
            main();
       }
    }
}
