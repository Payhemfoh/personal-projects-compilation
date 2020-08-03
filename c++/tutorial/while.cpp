// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main()
{
	char letter = 'a';

    do
	{
           cout << "Please enter a letter" << endl;
           cout<<"To end the program, please enter x"<<endl;
           cin >> letter;
           
           cout << "The letter you entered is " << letter << endl;
           cout<<endl<<endl;
    }while (letter != 'x');

    return 0;	
}
