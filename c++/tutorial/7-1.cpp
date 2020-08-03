//This program allow user to enter 12 month rainfall volume
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//constant value for the size of array
const int SIZE = 12;

//function prototype
string changeMonth(int);
void enter_rainfall(double*);
void display_rainfall(double*);
void program();
int get_highest_rainfall(double*);
void display_highest_rainfall(double*);
double get_mean_rainfall(double*);

int main()
{
	program();
	return 0;
 } 
 
 //convert integer type month to string type month
 string changeMonth(int month)
 {
 	string month_name="\0";
 	
 	//use switch case to convert
 	switch (month)
 	{
 		case 0:
 			month_name="January";
 			break;
 		case 1:
 			month_name="February";
 			break;
 		case 2:
 			month_name="March";
 			break;
 		case 3:
 			month_name="April";
 			break;
 		case 4:
 			month_name="May";
 			break;
 		case 5:
 			month_name="June";
 			break;
 		case 6:
 			month_name="July";
 			break;
 		case 7:
 			month_name="August";
 			break;
 		case 8:
 			month_name="September";
 			break;
 		case 9:
 			month_name="October";
 			break;
 		case 10:
 			month_name="November";
 			break;
 		case 11:
 			month_name="December";
 			break;
 		//for wrong value captured
 		default:
 			month_name="January";
	 }
	 return month_name;
}
	
void enter_rainfall(double rain[])
{
	//loop to enter the data and calculate the total
	for(int i=0 ; i<SIZE ; i++)
	{
		cout<<"Please enter the rainfall volume for month "
			<<left<<setw(10)<<changeMonth(i)<<" : ";
		cin>>rain[i];
	}
}

void display_rainfall(double rain[])
{
	//display all the rainfall for each month
	cout<<"Rainfall Details : "<<endl;
	cout<<"-----------------------"<<endl;
	for(int i=0; i<SIZE ; i++)
	{
		cout<<"month "<<left<<setw(15)<<changeMonth(i)<<" : "<<rain[i]<<endl;
	}
	
	cout<<endl;
}

void program()
{
	//declare variable
	double rainfall[SIZE]={0.0};
	
	//formating output
	cout<<setprecision(2)<<showpoint<<fixed;
	
	enter_rainfall(rainfall);
	cout<<endl;
	display_rainfall(rainfall);
	cout<<endl;
	display_highest_rainfall(rainfall);
	double mean=get_mean_rainfall(rainfall);
	
	cout<<"The mean rainfall is "<<mean<<endl;
}


int get_highest_rainfall(double rain[])
{
	//set the position to -1
	int pos=0;
	//assume first element is highest
	double highest=rain[0];
	//compare the highest value by loop
	for( int i=1; i<SIZE ; i++)
	{
		if (rain[i]>highest)
		//change highest value
		{
			highest=rain[i];
			pos=i;
		}
	}
	//return highest position
	return pos;
}


void display_highest_rainfall(double rain[])
{
	int pos = get_highest_rainfall(rain);
	
	cout<<"The highest rainfall is fall in "
		<<changeMonth(pos)<<" with "<<rain[pos]<<endl;
}

double get_mean_rainfall(double rain[])
{
	double total=0.0;
	
	for( int i=0; i<SIZE ; i++)
	{
		total+=rain[i];
	}
	
	return (total/SIZE);
}
