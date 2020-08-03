#include<iostream>
using namespace std;

int displayNum(int i)
{
	if(i==0)
	{
		cout<<i<<endl;
		return 0;	
	}
	cout<<i<<endl;
	displayNum(i-1);
	cout<<i<<endl;
	
	
}

int main()
{
	int result=displayNum(3);
}
