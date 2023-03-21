#include <iostream>
#include <string>
#include "Customer.h"


Customer::Customer(std::string name, std::string address, std::string contactNo)
	:name(name), address(address), contactNo(contactNo)
{
	++numCustomer;
	this->customerID = numCustomer;
}


Customer::Customer(int customerID, std::string name, std::string address, std::string contactNo)
	:customerID(customerID), name(name), address(address), contactNo(contactNo) {}

int Customer::getCustomerID() { return this->customerID; }
std::string Customer::getName() { return this->name; }
std::string Customer::getAddress() { return this->address; }
std::string Customer::getContactNo() { return this->contactNo; }
int Customer::getNumCustomer() { return numCustomer; }

void Customer::setCustomerID(int id) { this->customerID = id; }
void Customer::setName(std::string name) { this->name = name; }
void Customer::setAddress(std::string address) { this->address = address; }
void Customer::setContactNo(std::string contactNo) { this->contactNo = contactNo; }
void Customer::setNumCustomer(int num) { numCustomer = num; }


void Customer::print() {
	printf("%-12d|%-20s\n", this->customerID, this->name.c_str());
}


void Customer::printDetails() {
	using namespace std;
	cout << "Customer ID : " << this->customerID << endl;
	cout << "Customer Name : " << this->name << endl;
	cout << "Customer Address : " << this->address << endl;
	cout << "Customer Contact No : " << this->contactNo << endl;
}


bool Customer::operator <(Customer& other) {
	return this->customerID < other.customerID;
}

int Customer::numCustomer = 0;