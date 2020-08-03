//  This program prints "You Pass" if a student's average is 
//  60 or higher and prints "You Fail" otherwise


#include <iostream>
using namespace std;

int main()
{

	float average;    // holds the grade average

	cout << "Input your average:" << endl;
	cin >> average;

	if (average >= 90 && average <=100)
		cout << "You are in 'A' catagories " << endl;

	else if (average >=80)
		cout << "You are in 'B' catagories" << endl;
		
	else if (average >=60)
		cout << "You are Pass" << endl;
		
	else if (average >=0)
		cout << "You are Fail" << endl;
	
	else
		cout<<"Invalid average mark." << endl;

    return 0;	
}
