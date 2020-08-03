// This program will read in the qunatity of a particular item and its price.
// It will then print out the total price.
// The input will come from a data file and the output will go to
// an output file.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
	//i= read from file
   	ifstream dataIn;		// defines an input stream for a data file
   	//o= write to file
	ofstream dataOut;		// defines an output stream for an output file
	int quantity;			// contains the amount of items purchased
	float itemPrice;		// contains the price of each item
	float  totalBill;		// contains the total bill.  The price of all items

	//read data from the file
	dataIn.open("transaction.dat");  // This opens the file.
	//write the data into this file
	dataOut.open("bill.out");

	// Fill in the appropriate code in the blank below
	dataOut << setprecision(2) << fixed << showpoint;  // formatted output


	// Fill in the input statement that brings in the 
	// quantity and price of the item.
	//0.0 = = >< >.^ @@ o=(030)==b
	dataIn >> quantity >> itemPrice;

	// Fill in the assignment statement that determines the totalbill.
	totalBill= quantity* itemPrice;

	// Fill in the output statement that prints the total bill, with a label,
	// to an output.
	dataOut <<"The total bill is $"<<totalBill <<endl;
	
	cout<< "bill.out file created!"<<endl;


	return 0;
}
