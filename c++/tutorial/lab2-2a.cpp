// This program will output the perimeter and area
// of the rectangle with a given length and width.

#include <iostream>
using namespace std;
const int LENGTH = 8;
const int WIDTH = 3;
int main()
{
   int area; // definition of area
   int perimeter; // definition of perimeter
   
   perimeter = (2 * LENGTH) + (2 * WIDTH); // computes perimeter
   area = LENGTH * WIDTH ; // computes area
	
	// Fill in the code for the cout statement that will output (with description)
	// the perimeter
	cout<<"The perimeter is "<<perimeter<<endl;
	
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
	cout<<"The area is "<<area<<endl;

	return 0;
}

