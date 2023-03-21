#include <list>
#include <iostream>
#include <algorithm>
#include <functional>
#include "Customer.h"
#include "Order.h"
#include "Food.h"
#include "OrderingModule.h"
#include "InputModule.h"


OrderingModule::OrderingModule(std::list<Customer>* customerList, std::list<Order>* orderList, std::list<Food>* foodList)
	:customerList(customerList), orderList(orderList), foodList(foodList), Module()
{}


OrderingModule::~OrderingModule() {
	std::cout << "Returning to main module..." << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}


void OrderingModule::printMenu() {
	using namespace std;
	cout << "Welcome to Ordering Module" << endl;
	std::cout << std::string(50, '-') << std::endl;
	cout << "1. Make Order" << endl;
	cout << "2. Check Order Detail" << endl;
	cout << "3. Exit" << endl;
}


void OrderingModule::moduleProcess(int input) {
	switch (input) {
	case 1:
		makeOrder();
		break;
	case 2:
		viewOrderDetail();
		break;
	case 3:
		stopLoop();
		break;
	default:
		std::cout << "Invalid Input! Please try again!" << std::endl;
	}
}


void OrderingModule::makeOrder() {
	std::string breakLine(50, '-');
	int customerID = 0;
	int foodID = 0;
	int qty = 0;
	std::list<Food>::iterator fitr;

	//display customer information
	std::cout << breakLine << std::endl;
	printf("%-12s|%-20s\n", "Customer ID", "Name");
	for (Customer& temp : *customerList) {
		temp.print();
	}
	std::cout << breakLine << std::endl;
	//select customer
	customerID = InputModule::getIntegerInput("Enter Customer ID : ");
	while (customerID <= 0 || customerID > Customer::getNumCustomer()){
		std::cout << "The customerID should between 1 and " << Customer::getNumCustomer() << "! Please try again!" << std::endl;
		customerID = InputModule::getIntegerInput("Enter Customer ID : ");
	} 

	//display food information
	std::cout << breakLine << std::endl;
	printf("%-8s|%-20s|%-10s\n", "Food ID", "Food Flavour", "Unit Price");
	for (Food& temp : *foodList) {
		temp.print();
	}
	std::cout << breakLine << std::endl;
	//select food
	foodID = InputModule::getIntegerInput("Enter food ID : ");
	while (foodID <= 0 || foodID > Food::getNumFood()) {
		std::cout << "The foodID should between 1 and " << Food::getNumFood() << "! Please try again!" << std::endl;
		foodID = InputModule::getIntegerInput("Enter food ID : ");
	}

	fitr = std::find_if(foodList->begin(), foodList->end(),
		std::bind([](Food& temp, int id) {return temp.getFoodID() == id; }, std::placeholders::_1, foodID));

	//enter quantity
	while (qty <= 0) {
		qty = InputModule::getIntegerInput("Enter Quantity : ");
		if (qty <= 0) {
			std::cout << "The quantity should more than 0! Please try again!" << std::endl;
		}
	}

	//calculate total price
	double totalPrice = fitr->getUnitPrice() * qty;


	//create new order data
	Order temp(foodID, qty, customerID, totalPrice);
	orderList->push_back(temp);
	
	//sort the list after added new data into the list
	orderList->sort();
}


void OrderingModule::displayViewDetailMenu() {
	std::string breakLine(50, '-');
	printf("%-8s|%-8s|%-10s\n", "OrderID", "FoodID", "Total Price");
	std::cout << breakLine << std::endl;
	for (Order& temp : *orderList) {
		temp.print();
	}
	std::cout << breakLine << std::endl;
}


void OrderingModule::viewOrderDetail() {
	int input = 0;
	bool isContinue = true;
	do {
		displayViewDetailMenu();
		printf("Enter %d to return to module homepage.\n", Order::getNumOrder() + 1);
		input = InputModule::getIntegerInput("Enter order id to view the detail : ");

		std::cout << std::string(50, '-') << std::endl;


		if (input>0 && input < Order::getNumOrder() + 1) {
			//loop through element in list one by one and print the detail of order if id is match
			for (Order& temp : *orderList) {
				//display the detail of the order
				if (temp.getOrderID() == input) {
					//get the id store in the order
					int customerID = temp.getCustomerID();
					int foodID = temp.getFoodID();

					//search the customer with similar ID in the customer list
					std::list<Customer>::iterator citr = std::find_if(customerList->begin(), customerList->end(),
						std::bind([](Customer& temp, int id) {return temp.getCustomerID() == id; }, std::placeholders::_1, customerID));

					//search the food with similar ID in the food list
					std::list<Food>::iterator fitr = std::find_if(foodList->begin(), foodList->end(),
						std::bind([](Food& temp, int id) {return temp.getFoodID() == id; }, std::placeholders::_1, foodID));

					//print the detail
					temp.printDetails(*fitr, *citr);
					break;
				}
			}
		}
		else if (input == Order::getNumOrder() + 1) {
			//exit this function and return to module homepage
			isContinue = false;
			std::cout << "Returning to module homepage" << std::endl << std::endl;
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (isContinue);
}