// Function demostration
#include<iostream>
#include<iomanip>
using namespace std;

//function prototype
void spacing(int);
void make_decision();
char display_menu();
void cel_to_fah();
void fah_to_cel();
void conti_dicision();

//declare global variable
char option='\0';
int repeat=1;

int main()
{
	//formating output
	cout<<setprecision(2)<<fixed;
	
	//repeat until exit the program
	while(repeat!=0)
	{
		display_menu();
		make_decision();
	}
	return 0;
 } 
 
 void spacing(int x)
 {
 	for (int i=0; i<x;i++)
 	{
 		cout<<endl;
	 }
 }
 
 void make_decision()
 {
 	switch(option)
	{
		case'1':
			cel_to_fah();
			repeat=1;
			break;
			
		case'2':
			fah_to_cel();
			repeat=1;
			break;
				
		case'3':
			//end program. display bye-bye
			cout<<"The program will be closed. See you again. Bye-bye."<<endl;
			repeat=0;
			break;
				
		default:
			cout<<"Invalid option, please try again!!"<<endl;
			repeat=1;
		}
	spacing(2);
 }
 
 char display_menu()
 {
 	cout<<"Temperature Convertor"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"1. Celcius to Fahrenheit"<<endl;
		cout<<"2. Fahrenheit to Celcius"<<endl;
		cout<<"3. Exit program"<<endl;
		cout<<"\nEnter Option: "<<endl;
		cin>>option;
 }
 
void cel_to_fah()
 {
 	double fahrenheit=0.0, celcius=0.0;
 	
 	//convert celcius to fahrenheit
	//user input
	cout<<"Please enter the celcius : ";
	cin>>celcius;
	spacing(1);
				
	//calculation
	fahrenheit=(celcius*9/5)+32;
				
	//output
	cout<<"The fahrenheit for the "<<celcius<<" celcius is "<<fahrenheit<<" fahrenheit."<<endl;
	conti_dicision();
				
 }
 
 void fah_to_cel()
 {
 	double fahrenheit=0.0, celcius=0.0;
 	
 	//convert fahrenheit to celcius
 	//user input
 	cout<<"Please enter the fahrenheit : ";
	cin>>fahrenheit;
	spacing(1);
				
	//calculation
	celcius=(fahrenheit-32)*5/9;
				
	//output
	cout<<"The celcius for the "<<fahrenheit<<" fahrenheit is "<<celcius<<" celcius."<<endl;
	conti_dicision();
 }
 
 void conti_dicision()
 {
 	int re_conti=1;
 	char conti='\0';
 	
 	cout<<"Do you want to continue? [Y/N]:"<<endl;
	cin>>conti;
				
	conti=toupper(conti);
	
 	while (re_conti!=0)
	{
		if (conti=='Y')
		{
			cout<<"Please continue."<<endl;
			repeat=1;
			re_conti=0;
		}
		else if (conti=='N')
		{
			cout<<"The program will be closed. Please come again. Bye-Bye."<<endl;
			repeat=0;
			re_conti=0;
		}
		else
		{
			cout<<"Invalid choice. Please try again."<<endl;
			repeat=1;
			re_conti=1;
		}
	}
 }
