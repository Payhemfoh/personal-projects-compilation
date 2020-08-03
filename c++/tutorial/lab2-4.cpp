//This program required user to enter radius to calculate volume of sphere
#include<iostream>
#include<cmath>
using namespace std;

const double PI = 22.0/7.0;

int main()
{
	//declare and assign the variables
	double radius=0.0, volume=0.0;
	char menu='0';
	
	do
	{
		cout<<"Welcome to Sphere calculator"<<endl;
		cout<<"******************************"<<endl;
		cout<<"1.Calculate volume with radius"<<endl;
		cout<<"2.Calculate radius with volume"<<endl;
		cout<<"3.Exit the program"<<endl;
		cout<<"******************************"<<endl;
		cout<<"Please choose a functions : ";
		cin>>menu;
		cout<<"\n\n\n"<<endl;
		switch(menu)
		{
		case '1':
			//user input the radius
			cout<<"Please enter the radius of the sphere : ";
			cin>>radius;
			
			//calculate volume
			volume=(4.0/3.0)*PI*(pow(radius,3));
			
			//display the volume
			cout<<"The volume of the sphere is "<<volume<<endl;
			cout<<"\n\n\n"<<endl;
			break;
		
		case '2':
			//user input the volume
			cout<<"Please enter the volume of the sphere : ";
			cin>>volume;
			
			//calculate volume
			radius=cbrt(volume/PI*(3.0/4.0));
			
			//display the volume
			cout<<"The radius of the sphere is "<<radius<<endl;
			cout<<"\n\n\n"<<endl;
			break;
		
		case '3':
			return 0;
			break;
		
		default:
			cout<<"Invalid choice"<<endl;
			cout<<"\n\n\n"<<endl;
			break;
		}
	}while(menu!=3);
}
