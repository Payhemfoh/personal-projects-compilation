#include<iostream>
using namespace std;

int main()
{
	// character can be initialise by null value
	char pattern	='\0';
	int repeat		=0;
	int line 		=0;
	
	//promt user enter pattern, repeat and line
	cout<<"Please enter a character you like : "<<endl;
	cin>>pattern;
	cout<<"Please enter times to repeat : "<<endl;
	cin>>repeat;
	cout<<"Please enter number of lines : "<<endl;
	cin>>line;
	
	cout<<"\n\n"<<endl;
	//nested for loop to repeat the symbol for line and repeat
	for (int i=0;i<line;i++)
	{
		for(int j=0;j<repeat;j++)
		{
			cout<<pattern;
		}
		cout<<endl;
	}
	
	
	return 0;
}
