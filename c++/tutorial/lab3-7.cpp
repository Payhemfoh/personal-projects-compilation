#include<iostream>
using namespace std;

int main()
{
	int no1=0, no2=0;
	double result=0.0;
	
	cout<<"Enter number 1: ";
	cin>>no1;
	
	cout<<"Enter numnber 2: ";
	cin>>no2;
	
	result =static_cast<double> (no1)/no2;
	cout<< no1 <<"/"<<no2<<"="<<result<<endl;
	
	return 0;
}
