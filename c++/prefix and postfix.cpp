#include<iostream>
using namespace std;

int main()
{
	int x =5;
	
	cout<< x++ <<endl;			// cout x first later increment
	cout<< ++x <<endl;			// increase first then cout x
	cout<< x++ <<endl;
	cout<< x <<endl;
	return 0;
}
