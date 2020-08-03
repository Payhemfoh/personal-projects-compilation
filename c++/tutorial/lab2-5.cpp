//This program will display a random number which is random according to the time
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
	//random value according to time
	srand(time(0));
	
	//declare and asign the variable
	int x1=0,y1=0,x2=0,y2=0;
	int tried=0;
	double distance=1;
	
	cout<<"Treasure Hunt Game"<<endl;
	cout<<"---------------------------"<<endl;
	
	//computer generate the location of treasure box randomly
	x1=rand()%801;		//get value in range 0-800
	y1=rand()%601;	//get value in range 0-600
	
	//loop until success
	while(distance!=0)
	{
		cout<<"Enter your location to find the treasure box : ";
		cin>> x2 >> y2;
		
		//calculate distance between you and treasure box
		distance = (abs(sqrt(pow((y2-y1),2)+(pow((x2-x1),2)))));
		
		//if distance=0,player found the treasure
		if(distance!=0)
		{
			cout<<"The distance between you and treasure box is "<<distance <<endl;
			tried=tried+1;
		}
	}
	
	cout<<"Congratulation!You found the treasure"<<endl;
	cout<<"You had tried "<<tried <<"times";
	return 0;
}
