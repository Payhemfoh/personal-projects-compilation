//dynamic pointer
#include<iostream>

using namespace std;

int main()
{
	int size=0;
	int *list = NULL;
	
	//let user decided size of array
	cout<<"Enter total size in array: ";
	cin>>size;
	
	//allocate memory space for list
	list = new int[size];
	
	//let user enter number
	for(int i=0;i<size;i++)
	{
		cout<<"Enter number "<<i+1<<':';
		cin>>*(list+i);
	}
	
	//print out all value in array
	for(int i=0;i<size;i++)
		cout<<"Number "<<i+1<<": "<<*(list+i)<<endl;
		
	//need to destroy array as this is dynamic array
	delete[] list;//use square bracket to destroy array
	return 0;
}
