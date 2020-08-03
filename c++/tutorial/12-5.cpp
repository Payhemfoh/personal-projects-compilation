#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char text1[]="Saturday is the exam date";
	char text2[50];
	char text3[10];
	
	//try to copy all the text from text1 to text2
	//text2 = text1; //illegal way
	strcpy(text2,text1);
	
	cout<<text2<<endl;
	
	//copy saturday to text3 from text1
	strncpy(text3,text1,8);
	text3[8]='\0';
	
	cout<<text3<<endl;
	
	if(strcmp(text3,"Saturday")==0)
		cout<<"Today is saturday"<<endl;
	return 0;
}
