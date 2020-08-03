//print multiplication table
#include<iostream>
using namespace std;

int main()
{
	int num=0;
	
	cout<<"Please enter the number of multiplication table : "<<endl;
	cin>>num;
	
	while(num<=0 || num>=13)
	{
		cout<<"The number should between 0 and 13, Please try again"<<endl;
		cin>>num;
	}
	
	for (int i=1;i<=12;i++)
	{
		cout<<i <<" X "<<num<<" = "<<i*num<<endl;
	}
	return 0;
}
