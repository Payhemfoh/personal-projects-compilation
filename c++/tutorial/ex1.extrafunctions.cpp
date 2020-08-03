// Function demostration
#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

//function prototype
void spacing(int);
void make_decision();
void display_menu();
void cel_to_fah();
void fah_to_cel();
void conti_dicision();
void close_program();
char get_char(string);
double get_value(string);
void display_convert(string,string,double,double);
void invalid();

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
			close_program();
			break;
				
		default:
			invalid();
		}
	spacing(2);
 }
 
 void display_menu()
 {
 	cout<<"Temperature Convertor"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"1. Celcius to Fahrenheit"<<endl;
		cout<<"2. Fahrenheit to Celcius"<<endl;
		cout<<"3. Exit program"<<endl;
		option=get_char("\nEnter Option: ");
 }
 
 void cel_to_fah()
 {
 	double fahrenheit=0.0, celcius=0.0;
 	
 	//convert celcius to fahrenheit
	//user input
	celcius=get_value("Please enter the celcius : ");
	spacing(1);
				
	//calculation
	fahrenheit=(celcius*9/5)+32;
				
	//output
	cout<<"The fahrenheit for the "<<celcius<<" celcius is "<<fahrenheit<<" fahrenheit."<<endl;
	display_convert("fahrenheit","celcius",fahrenheit,celcius);
				
 }
 
 void fah_to_cel()
 {
 	double fahrenheit=0.0, celcius=0.0;
 	
 	//convert fahrenheit to celcius
 	//user input
 	fahrenheit=get_value("Please enter the fahrenheit : ");
	spacing(1);
				
	//calculation
	celcius=(fahrenheit-32)*5/9;
				
	//output
	
 }
 
 void conti_dicision()
 {
 	int re_conti=1;
 	char conti='\0';
 	
 	while (re_conti!=0)
	{
 	conti=get_char("Do you want to continue? [Y/N]:");
				
	conti=toupper(conti);
	
 	
		if (conti=='Y')
		{
			cout<<"Please continue."<<endl;
			repeat=1;
			re_conti=0;
		}
		else if (conti=='N')
		{
			close_program();
			re_conti=0;
		}
		else
		{
			invalid();
			re_conti=1;
		}
	}
 }
 
 void close_program()
 {
 	cout<<"The program will be closed. Please come again. Bye-Bye."<<endl;
	repeat=0;
 }
 
 char get_char(string promptText)
 {
 	//get the options from the user
 	char options='\0';
 	
 	cout<<promptText<<endl;
 	cin>>options;
 	
 	return options;
 }
 
 double get_value(string promptText)
 {
 	//get the options from the user
 	double value=0.0;
 	
 	cout<<promptText<<endl;
 	cin>>value;
 	
 	return value;
 }
 
 void display_convert(string word1,string word2,double value1,double value2)
 {
 	cout<<"The "<<word1<<" for the "<<value2<<word2<<" is "<<value1<<word1<<endl;
	conti_dicision();
 }
 
 void invalid()
 {
 	cout<<"Invalid choice. Please try again."<<endl;
	repeat=1;
 }
