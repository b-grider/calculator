#include "help.h"

using namespace std;

help::printMenu()
{
    cout<<"**Initial Menu Here**"<<endl;
	char menu = 'y';
	do
	{
		int selection;
		cin>>selection;
		move(selection);
		cout<<"Return to Menu?  y/n"<<endl;
	}while(menu == 'y');
}
help::move(int navigate)
{
	if(navigate == 1)
		cout<<"**Selection One**"<<endl;
	if(navigate == 2)
		cout<<"**Selection Two**"<<endl;
	if(navigate == 3)
		cout<<"**Selection Three**"<<endl;
	/*
	 * Add more if needed
	 */
}
