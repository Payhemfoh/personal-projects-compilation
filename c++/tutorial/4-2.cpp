//This program will prompt user enter number of T-shirt and compute total price.

#include<iostream>
#include<iomanip>
using namespace std;



int main()
{
	//declare variables
	int num_shirt=0; 
	double price=12.0;
	double total_price=0.0;
	
	cout<<
	
	//validation of number of shirt
	while (num_shirt<0)
	{
	//input number of t-shirt
	cout<<"How many shirts would you like :";
	cin>>num_shirt;
	
	if(num_shirt<0)
		cout<<"Invalid Input: Please enter a nonnegative integer"<<endl;
	}
	
	//decide the discount
	if (num_shirt>=31)
		price =price *0.75;
	
	else if(num_shirt>=21)
		price=price*0.8;
	
	else if(num_shirt>=11)
		price=price*0.85;
	
	else if(num_shirt>=5)
		price=price*0.9;
	
	//calculate total price
	total_price=num_shirt*price;
	
	//display the prices
	cout<<"The cost per shirt is $"<<price<<" and the total cost is $"<<total_price;
	
	
	return 0;
}
