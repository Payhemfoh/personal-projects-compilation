//Function demostration
#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

int continue_decision();
double get_doublevalue(string);
char get_char(string);
void show_menu();
void invalid_message();
void close_program();
void cel_to_fah(double,double&);
void fah_to_cel(double,double&);

int repeat=1;

int main()
{
	//declare variables
	double fahrenheit=0.0, celcius=0.0;
	char option='\0';
	
	//formating output
	cout<<setprecision(2)<<fixed;
	
	//repeat until exit the program
	while(repeat!=0)
	{	
		//menu
		show_menu();
		option=get_char("\nEnter Option: ");
		
		switch(option)
		{
			case'1':
				//convert celcius to fahrenheit
				//user input
				celcius=get_doublevalue("Please enter the celcius : ");
				
				//calculation
				cel_to_fah(celcius,fahrenheit);
				
				//output
				cout<<"The fahrenheit for the "<<celcius<<" celcius is "<<fahrenheit<<" fahrenheit."<<endl;
				
				continue_decision();
				break;
			case'2':
				//convert fahrenheit to celcius
				fahrenheit=get_doublevalue("Please enter the fahrenheit : ");
				
				//calculation
				//celcius=far_to_cel(celcius,fahrenheit);
				fah_to_cel(fahrenheit,celcius);
				//output
				cout<<"The celcius for the "<<fahrenheit<<" fahrenheit is "<<celcius<<" celcius."<<endl;
				
				continue_decision();
				
				break;
				
			case'3':
				//end program. display bye-bye
				close_program();
				break;
				
			default:
				invalid_message();
		}
		cout<<endl;
		cout<<endl;
	}
	return 0;
}

void fah_to_cel(double fahrenheit,double &celcius)
{
	celcius=(fahrenheit-32)*5/9;
}

void cel_to_fah(double celcius,double &fahrenheit)
{
	fahrenheit=(celcius*9/5)+32;
}

void close_program()
{
	cout<<"The program will be closed. See you again. Bye-bye."<<endl;
	repeat=0;
}

void invalid_message()
{
	cout<<"Invalid option, please try again!!"<<endl;
	repeat=1;
}

void show_menu()
{
	cout<<"Temperature Convertor"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"1. Celcius to Fahrenheit"<<endl;
	cout<<"2. Fahrenheit to Celcius"<<endl;
	cout<<"3. Exit program"<<endl;
}

char get_char(string promptText)
{
	char value='\0';
	
	cout<<promptText<<endl;
	cin>>value;
	cout<<endl;
	
	return value;
}

double get_doublevalue(string promptText)
{
	double value='\0';
	
	cout<<promptText<<endl;
	cin>>value;
	cout<<endl;
	
	return value;
}

int continue_decision()
{
	char conti='\0';
	int  re_conti=1;
	
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
			repeat=0;
			re_conti=0;
		}
		else
		{
			invalid_message();
			re_conti=1;
		}	
	}
}
 
 // exit(0); terminate program
