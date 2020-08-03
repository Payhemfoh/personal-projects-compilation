#include<iostream>
using namespace std;

int main()
{
	int test[5];
	
	test[0]=95;
	test[1]=60;
	test[2]=test[1]+10;
	test[3]=test[2]-6;
	test[4]=test[0]-20;
	test[5]=0;			// only until test[4]
	
	cout<<test[5]<<endl;
	
	return 0;
 } 
