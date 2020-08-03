#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	ifstream dataIn;
	ofstream dataOut;
	dataIn.open("data.txt");
	dataOut.open("data.txt");
	
	int array[100]={0};
	
	array[0]=1;
	
	for (int i=0; i<100;i++)
	{
		array[i]=array[i-1]+1;
	}
	
	//bubble sort
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<(SIZE-i);j++)
		{
			if (arr[j]>arr[j+1])
			{
				arr[j]=arr[j]+arr[j+1];
				arr[j+1]=arr[j]-arr[j+1];
				arr[j]=arr[j]-arr[j+1];
			}
		}
	}
	
	for()
	
	//binary search
	int s,e,m;
	s=0;
	e=100;
	bool result;
	int repeat=1;
	int search;
	
	cin>>search;
	do
	{
		m=(s+e)/2;
		if (search == array[m])
		{
			cout<<"The number is found in array["<<m<<"]"<<endl;
			result=true;
			repeat=0;
		}
		else if(search< array[m])
		{
			e=m;
			if (s>=e)
			{
				cout<<"The number is not found in the array"<<endl;
				result=false;
				repeat=0;
			}
		}
		else if(search>array[m])
			s=m;
			if (s>=e)
			{
				cout<<"The number is not found in the array"<<endl;
				result=false;
				repeat=0;
			}
	}while(repeat==1);
	
	
	
	
	
	
	return 0;
}
