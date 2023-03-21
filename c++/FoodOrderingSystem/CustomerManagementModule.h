#pragma once
#include <list>
#include "Module.h"
#include "Customer.h"
#include "Order.h"

/*
	CustomerManagementModule class(extends Module)
	This class is the customer management module of the program.
	This module included 4 function which are:
	create new customer profile
	modify customer profile
	delete customer profile
	display customer profile
*/
class CustomerManagementModule : public Module {
private:
	std::list<Customer>* customerList;
	std::list<Order>* orderList;
public:
	/*
	This constructor will point the pointer to the memory location of the customerList
	*/
	CustomerManagementModule(std::list<Customer>* customerList,std::list<Order>* orderList);

	/*
	This destructor will display message to indicate user is begin redirected to the main module
	*/
	~CustomerManagementModule();

	/*
	This method will display the menu of the module for user selection
	*/
	void printMenu();

	/*
	This method will call the process method in this module based on the user input
	*/
	void moduleProcess(int input);

	/*
	This method will ask user to enter the customer information
	and create a new customer object
	and append the customer object into the customerList
	*/
	void createNewProfile();

	/*
	This method will display the list of customer for user selection
	then display the attribute list for user selection.
	The user can then modify the attributes based on the needs
	*/
	void modifyProfile();

	/*
	This method will display a list of customer for the user selection
	then ask for the confirmation from the user.
	if user confirm to delete the customer data,
	the customer data will be removed from the list.
	*/
	void deleteProfile();

	/*
	This method will display a list of customer for user selection
	and display the full details of the customer data for the selected customer id
	*/
	void displayProfile();

	/*
	This method will print a list of customer data for user selection
	*/
	void printList();

	/*
	This method is used to print the menu which contain the attributes of the customer data
	for user selection in the edit module.
	*/
	void printSelectionMenu();
};