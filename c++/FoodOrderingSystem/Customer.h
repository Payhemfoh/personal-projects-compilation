#pragma once
#include "Printable.h"
#include <string>

/*
	Customer class (implement Printable)
	This class store the customer information required in this program which are:
	customerID which will be assigned automatically according to the number of customer data present
	name, address and contactNo of customer
	numCustomer which represent the number of customer data present currently in this program
*/
class Customer : public Printable {
private:
	int customerID;
	std::string name;
	std::string address;
	std::string contactNo;
	static int numCustomer;
public:
	/*
	This constructor is used to create a new profile for the user which require:
	name,address and contactNo of user
	this constructor will increase the numCustomer and assign the customerID automatically
	*/
	Customer(std::string name = "", std::string address = "", std::string contactNo = "");

	/*
	This constructor is used to read the customer profile from the data file
	This constructor will not increase the numCustomer but will assign directly by the input from data file
	*/
	Customer(int customerID, std::string name, std::string address, std::string contactNo);

	int getCustomerID();
	std::string getName();
	std::string getAddress();
	std::string getContactNo();
	static int getNumCustomer();

	void setCustomerID(int id);
	void setName(std::string name);
	void setAddress(std::string address);
	void setContactNo(std::string contactNo);
	static void setNumCustomer(int num);

	/*
	print() method used to display the simplified detail of the customer object
	primary used in the table display
	*/
	void print();

	/*
	printDetails() method will print all the detail of the customer object line-by-line
	*/
	void printDetails();

	/*
	This operator is overloaded for the sorting based on the customerID
	*/
	bool operator <(Customer& other);
};