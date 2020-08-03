// This program displays a hot beverage menu and prompts the user to
// make a selection. A switch statement determines which item the user
// has chosen. A do-while loop repeats until the user selects item E
// from the menu.

#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	// Fill in the code to define an integer variable called number, 
	int num=0;
	
	// a floating point variable called cost,
	float cost=0.0f;
	
	// and a character variable called beverage
	char bever='x';
	
	bool validBeverage;

	cout << fixed << showpoint << setprecision(2);
	

	do
	{
		cout << endl << endl;
		cout << "Hot Beverage Menu" << endl << endl;
		cout << "A: Coffee         $1.00" << endl;
		cout << "B: Tea            $0.75" << endl;
		cout << "C: Hot Chocolate  $1.25" << endl;
		cout << "D: Cappuccino     $2.50" << endl <<endl << endl;
		
		cout << "Enter the beverage A,B,C, or D you desire" << endl;
		cout << "Enter E to exit the program" << endl << endl;
		cin>>bever;
		// Fill in the code to read in beverage
		
		switch(bever)
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'd':
			case 'D':  validBeverage = true;
					   break;
			default:   validBeverage = false;
		}

		if (validBeverage == true)
		{
			cout << "How many cups would you like?" << endl;
			// Fill in the code to read in number
			cin>>num;
		}
		// Fill in the code to begin a switch statement 
		// that is controlled by beverage
		switch(bever)
		{
			case 'a':
			case 'A': cost += (num * 1.00);
				    cout << "The total cost is $ " << cost << endl;
					break;
			
			// Fill in the code to give the case for tea ( $0.75 a cup)
			// Fill in the code to give the case for hot chocolate ($1.25 a cup)
			// Fill in the code to give the case for cappuccino ($2.50 a cup)
			case 'b':
			case 'B':
					cost += (num * 0.75);
					cout << "The total cost is $ " << cost << endl;
					break;
			case 'c':
			case 'C':
					cost += (num * 1.25);
					cout << "The total cost is $ " << cost << endl;
					break;
			case 'd':
			case 'D':
					cost += (num * 2.50);
					cout << "The total cost is $ " << cost << endl;
					break;
			
			case 'e':		
			case 'E': cout << " Please come again" << endl;
				    break;
			default:cout << // Fill in the code to write a message 
						    // indicating an invalid selection.
					cout << " Try again please" << endl;
		}
		
	// Fill in the code to finish the do-while statement with the 
	// condition that beverage does not equal E or e.
	}while(bever!='E'&&bever!='e'); 

	// Fill in the appropriate return statement
	return 0;
}



