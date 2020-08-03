#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;

double disc(int, int, int, int);
void dici(float);
void dicistatic();
void statics();
int c=0;
int x1=0,x2=0,x3=0;

int main()
{
	srand(time(0));
	cout<<setprecision(2)<<fixed;
	
	int x1=0,x2=0,y1=0,y2=0;
	float distance=1.0;
	
	char menu='0';
	
	while(menu!=3)
	{
		cout<<"Welcome to simple treasure box game!"<<endl;
		cout<<"------------------------------------------"<<endl;
		
		cout<<"1. Play game"<<endl;
		cout<<"2. Scoreboard"<<endl;
		cout<<"3. Exit game"<<endl;
		cout<<"Please select : ";
		cin>>menu;
		
		switch(menu)
		{
			case '1':
				
				x1=rand()%801;
				y1=rand()%601;
				c=0;
				
				while (distance!=0)
				{
					cout<<"Please enter your location : "<<endl;
					cin>>x2>>y2;
					
					distance=disc(x1,y1,x2,y2);
					
					dici(distance);
					
				}
				break;
				
			case '2':
				statics();
				break;
				
			case '3':
				cout<<"Good bye, Please come again.\nHave a nice day!!"<<endl;
				return 0;
				break;
				
			default:
				cout<<"Invalid choice, please try again!!";
				break;
		}
	}
 } 
 
 
 double disc(int x1,int y1,int x2,int y2)
 {
 	int dif=0;
 	double sqdif=0.0;
 	
 	dif=(pow((x2-x1),2))+(pow((y2-y1),2));
 	sqdif=sqrt(static_cast<double>(dif));
 	
 	return sqdif;
 }
 
 void dici(float x)
 {
 	if(x!=0)
		{
			cout<<"Ops, you didn't found the treasure box, the distance distance between you and the treasure box is "<<x<<endl;
			c+=1;
		}
		
		else
		{
			cout<<"You found the treasure box, congratulation!!"<<endl;
			cout<<"You had tried "<<c<<"times"<<endl;
			dicistatic();
		}
 }
 
 void dicistatic()
 {
 	if (c<x1)
 	{
 		x2=x3;
 		x1=x2;
 		c=x1;
	 }
	
	else if (c<x2)
	{
		x2=x3;
		c=x2;
	}
	
	else if (c<x3)
	{
		c=x3;
	}
 }
 
 void statics()
 {
 	char chars='*';
 	
 	cout<<"Scoreboard!!"<<endl;
 	cout<<"-----------------------"<<endl;
 	
 	cout<<"1. "<<left<<setw(8)<<x1;
 	for(int r=0;r<=x1;r++)
 	{
 		cout<<chars<<endl;
	 }
 	cout<<"2. "<<left<<setw(8)<<x2;
 	for(int r=0;r<=x2;r++)
 	{
 		cout<<chars<<endl;
	 }
 	cout<<"3. "<<left<<setw(8)<<x3;
 	for(int r=0;r<=x3;r++)
 	{
 		cout<<chars<<endl;
	 }
 }
