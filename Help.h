#ifndef HELP_H
#define HELP_H
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Help {
       private:
           int navigate;
       public:
           void printMenu();
           void move(int navigate);
};
#endif	/* HELP_H */
