//pointer with array
#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;

const int SIZE=20;

int main()
{
	int list[SIZE]={0};
	char text[]="INTI is the best!";
	for(int i=0;i<SIZE;i++)
		list[i]=(rand()%100)+1;
	
	//pointer point to array,no & as array name is a pointer
	int *ptr = list;
	
	//using ptr with pointer notation,print out all array items
	/*
	for(int i=0;i<SIZE;i++)
	{
		cout<<*(ptr+i)<<endl;
	}
	*/
	//pointer point to array
	char* pointer=text;
	
	int size=sizeof(text)/sizeof(text[0]);
	
	for(int i=0;i<size;i++){
		*(pointer+i)=tolower(*(pointer+i));
		cout<<*(pointer+i);
	}
	// static_cast<char>(tolower(*(pointer+i)));
	// (char)(tolower(*(pointer+i));
	
	
	for(int i=0;i<size;i++){
		*(pointer+i)=toupper(*(pointer+i));
		cout<<*(pointer+i);
	}
	
	
	//without size
	while(*pointer!='\0') //!*pointer
	{
		cout<< static_cast<char>(toupper(*pointer));
		//move pointer to next position
		pointer++;
	}
	
	//revise pointer back to the first position
	pointer=text;
	return 0;
}
