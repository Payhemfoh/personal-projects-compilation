//Function demostration
#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

int main()
{
	//declare variables
	double fahrenheit=0.0, celcius=0.0;
	char option='\0';
	int repeat=1, re_conti=1;
	char conti='\0;';
	
	//formating output
	cout<<setprecision(2)<<fixed;
	
	//repeat until exit the program
	while(repeat!=0)
	{
		fahrenheit=0.0;
		celcius=0.0;
		
		//menu
		cout<<"Temperature Convertor"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"1. Celcius to Fahrenheit"<<endl;
		cout<<"2. Fahrenheit to Celcius"<<endl;
		cout<<"3. Exit program"<<endl;
		cout<<"\nEnter Option: "<<endl;
		cin>>option;
		
		switch(option)
		{
			case'1':
				//convert celcius to fahrenheit
				//user input
				cout<<"Please enter the celcius : ";
				cin>>celcius;
				cout<<endl;
				
				//calculation
				fahrenheit=(celcius*9/5)+32;
				
				//output
				cout<<"The fahrenheit for the "<<celcius<<" celcius is "<<fahrenheit<<" fahrenheit."<<endl;
				
				while (re_conti!=0)
				{
				cout<<"Do you want to continue? [Y/N]:"<<endl;
				cin>>conti;
				
				conti=toupper(conti);
				
				
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
				break;
			case'2':
				//convert fahrenheit to celcius
				cout<<"Please enter the fahrenheit : ";
				cin>>fahrenheit;
				cout<<endl;
				
				//calculation
				celcius=(fahrenheit-32)*5/9;
				
				//output
				cout<<"The celcius for the "<<fahrenheit<<" fahrenheit is "<<celcius<<" celcius."<<endl;
				
				while (re_conti!=0)
				{
				cout<<"Do you want to continue? [Y/N]:"<<endl;
				cin>>conti;
				
				conti=toupper(conti);
				
				
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
		cout<<endl;
		cout<<endl;
	}
	return 0;
 } 
