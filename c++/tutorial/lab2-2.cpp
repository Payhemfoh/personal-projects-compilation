// This program will output the circumference and area
// of the circle with a given radius.

#include <iostream>
using namespace std;
const double PI = 3.14;
const double RADIUS = 5.4;
int main()
{
   double area // definition of area of circle
   float circumference; // definition of circumference
   
   circumference = 2 * PI * RADIUS; // computes circumference
   area = PI * RADIUS * RADIUS ; // computes area
   
	// Fill in the code for the cout statement that will output (with description)
	// the circumference
	cout<<"The circumference is "<<circumference<<endl;
	
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
	cout<<"The area is "<<area<<endl;
	
	return 0;
}

