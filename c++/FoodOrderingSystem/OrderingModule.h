#pragma once
#include<list>
#include "Customer.h"
#include "Order.h"
#include "Food.h"
#include "Module.h"

/*
	OrderingModule class(extends Module)
	This class is the ordering module of the program.
	This module included 2 function which are:
	make new order
	view order details
*/
class OrderingModule : public Module {
private:
	std::list<Customer>* customerList;
	std::list<Order>* orderList;
	std::list<Food>* foodList;
public:
	/*
	This constructor will point the pointer to the memory address of the list
	required in this module (customerList, orderList, foodList)
	*/
	OrderingModule(std::list<Customer>* customerList, std::list<Order>* orderList, std::list<Food>* foodList);

	/*
	This destructor will display the message to indicate the user is being redirected to the main module.
	*/
	~OrderingModule();

	/*
	This method will print the menu of this module for the user selection
	*/
	void printMenu();

	/*
	This method will called the process method based on the user input
	*/
	void moduleProcess(int input);

	/*
	This method will ask user to enter data and create a new order object
	then append to the orderList
	*/
	void makeOrder();

	/*
	This method will display the order object in table format for the selection of user
	*/
	void displayViewDetailMenu();

	/*
	This method is the function of the view order detail
	The method will first print a list of order id, food id , total price
	then require user to select the order id
	if the order id present, this method will display the detail of the order with Order.printDetails()
	if user enter the number of order id + 1, the user will exit from the function
	else the user will loop in this function
	*/
	void viewOrderDetail();
};

