#include "Help.h"

using namespace std;

void Help::printMenu()
{
    cout<<"**Initial Menu Here**"<<endl;
	char menu = 'y';
	int selection;
	cin>>selection;
	move(selection);
	cout<<"Return to Menu?  y/n"<<endl;
	cin>>menu;
	if(menu == 'y')
		printMenu();
}
void Help::move(int navigate)
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
