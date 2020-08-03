// this program prompt user enter last 4 quartile of water bill and calculate the average

#include<iostream>
using namespace std;

int main()
{
	//declare the variable;
	double q1=0.0,q2=0.0,q3=0.0,q4=0.0;
	double average = 0.0;
	
	//quarter 1
	cout<<"Please enter your water bill for quarter 1 : "<<endl;
	cin>>q1;
	
	//quarter 2
	cout<<"Please enter your water bill for quarter 2 : "<<endl;
	cin>>q2;
	
	//quarter 3
	cout<<"Please enter your water bill for quarter 3 : "<<endl;
	cin>>q3;
	
	//quarter 4
	cout<<"Please enter your water bill for quarter 4 : "<<endl;
	cin>>q4;
	
	//calculate average
	average= (q1+q2+q3+q4)/4;
	
	//display message.
	if(average>75)
		cout<<"Your average monthly bill is $"<<average<<". You are using excessive amounts of water."<<endl;
	else if(average>=25)
		cout<<"Your average monthly bill is $"<<average<<". You are using a typical amount of water."<<endl;
	else if(average>=0)
		cout<<"Your average monthly bill is $"<<average<<". You are using a less amount of water."<<endl;
	else
		cout<<"Invalid average number."
		
	return 0;
}
