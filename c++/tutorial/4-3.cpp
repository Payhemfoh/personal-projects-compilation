#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	int no1=0,no2=0,no3=0;
	int largest=0,smallest=0,middle=0;
	
	cout<<"Enter 3 numbers :";
	cin>>no1>>no2>>no3;
	
	//find largest number
/*	if(no1>no2)
	{
		if(no1>no3)
			largest=no1;
		else if(no3>no1)
			largest=no3;
	}
	
	else if(no2>no1)
	{
		if(no3>no2)
			largest=no3;
		else if(no2>no3)
			largest=no2;
	}
*/	

/*
	largest=no1;
	
	if(largest<no2)
		largest= no2;
	
	if(largest<no3)
		largest= no3;
*/

	//from cmath
	largest=max(no1,no2);
	largest=max(largest,no3);
		
	cout<<"The largest number is "<<largest <<endl;
	return 0;
}
