#pragma once
#include <fstream>
#include <list>
#include "Customer.h"
#include "Food.h"
#include "Order.h"
#include "Module.h"

class MainModule : public Module {
private:
	std::list<Customer> customerList;
	std::list<Order> orderList;
	std::list<Food> foodList;

	/*
	This method is used to read the customer data from the data file
	which saved the information of customers
	*/
	Customer getCustomerData(std::ifstream& in);

	/*
	This method is used to read the food data from the data file
	which saved the information of foods
	*/
	Food getFoodData(std::ifstream& in);

	/*
	This method is used to read the order data from the data file
	which saved the information of orders
	*/
	Order getOrderData(std::ifstream& in);
public:
	/*
	This constructor will call the readDataFile method to read all the data saved in the datafile
	*/
	MainModule();

	/*
	This destructor will call the writeDataFile method to save all the data into the datafile
	and print the message after the saving process
	*/
	~MainModule();

	/*
	This method will be called in the beginning of the program by the constructor to read the data
	from the data file
	*/
	void readDataFile();

	/*
	This method will be called at the end of the program by the destructor to save the data
	into the data file
	*/
	void writeDataFile();

	/*
	This method will print the main menu of the program
	*/
	void printMenu();

	/*
	This method will direct the user to each module based on the user input.
	The user cannot enter the order module with empty orderList or customerList
	*/
	void moduleProcess(int input);
};

