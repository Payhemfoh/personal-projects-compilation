// This program tests whether or not an initialized value
// is equal to a value input by the user 

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main( )
{
 	int num1,				// num1 is not initialized
		num2;           // num2 has been initialized to 5

    cout << "Please enter two integer" << endl;
	cin >> num1 >> num2; 


	cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

    if (num1 == num2)
		cout << "The value are same\nHey, that's  a coincidence!" << endl; 
			
    else
		cout << "The values are not the same" << endl;
			
    return 0;	
}
