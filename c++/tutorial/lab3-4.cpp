// This program will input the value of two sides of a right triangle and then 
// determine the size of the hypotenuse.

// PLACE YOUR NAME HERE

#include <iostream>
#include <cmath>         // needed for math functions like sqrt()
#include <iomanip>
using namespace std;



int main()

{

	double a,b;		   // the smaller two sides of the triangle
	double hyp;		   // the hypotenuse calculated by the program
   
   	cout<< setprecision(2) << fixed << showpoint;
	cout << "Please input the value of the two sides" << endl;
	cin >> a >> b;


	// Fill in the assignment statement that determines the hypotenuse.
	hyp=sqrt(pow(a,2)+pow(b,2));
	
	cout << "The sides of the right triangle are " << a << " and " << b << endl;

	cout << "The hypotenuse is " << hyp << endl;

	return 0;
}
