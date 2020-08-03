#include<iostream>
using namespace std;

int main()
{
	int val =5;
	val=val-1;					 // val -=1
	cout<<val++ + ++val;		// 4 + 6
	return 0;
}
