#include<iostream>
using namespace std;

int main()
{
	int num1=0,num2=0;
	int *ptr1,*ptr2;

	//point ptr1 to num1 and ptr2 to num2
	ptr1=&num1;
	ptr2=&num2;
	
	//let user input num1 and num2 by pointer
	cout<<"Enter 2 integer value : "<<endl;
	cin>>*ptr1>>*ptr2;
	
	//display num1+num2 by pointer
	cout<<(*ptr1+*ptr2)<<endl;
	return 0;
}
