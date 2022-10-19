#include <iostream>
#include <string>
#include "OrderingModule.h"
#include "CustomerManagementModule.h"
#include "MenuManagementModule.h"
#include "MainModule.h"


Customer MainModule::getCustomerData(std::ifstream& in) {
	int id = 0;
	std::string address(""), contactNo(""), name("");
	in >> id;
	in.ignore(100, '\n');
	getline(in, name);
	getline(in, address);
	getline(in, contactNo);
	Customer temp(id, name, address, contactNo);
	return temp;
}


Food MainModule::getFoodData(std::ifstream& in) {
	int id = 0;
	std::string flavour("");
	double weight = 0.0, unitPrice = 0.0;
	in >> id;
	in.ignore(100, '\n');
	getline(in, flavour);
	in >> weight;
	in >> unitPrice;
	in.ignore(100, '\n');

	Food temp(id, flavour, weight, unitPrice);
	return temp;
}


Order MainModule::getOrderData(std::ifstream& in) {
	int orderID = 0, foodID = 0, quantity = 0, customerID = 0;
	double totalPrice = 0.0;

	in >> orderID;
	in >> foodID;
	in >> quantity;
	in >> customerID;
	in >> totalPrice;
	in.ignore(100, '\n');
	Order temp(orderID, foodID, quantity, customerID, totalPrice);
	return temp;
}


MainModule::MainModule() : Module() {
	readDataFile();
}


MainModule::~MainModule() {
	writeDataFile();
	std::cout << "Thank you for using the program! Please come again." << std::endl;
}


void MainModule::readDataFile() {
	std::ifstream customerFile("customer.dat"), orderFile("order.dat"), foodFile("food.dat");
	if (customerFile) {
		int numCustomer = 0;
		customerFile >> numCustomer;
		Customer::setNumCustomer(numCustomer);

		for (int i = 0; i < numCustomer; ++i) {
			Customer temp = getCustomerData(customerFile);
			customerList.push_back(temp);
		}
	}

	if (orderFile) {
		int numOrder = 0;
		orderFile >> numOrder;
		Order::setNumOrder(numOrder);

		for (int i = 0; i < numOrder; ++i) {
			Order temp = getOrderData(orderFile);
			orderList.push_back(temp);
		}
	}

	if (foodFile) {
		int numFood = 0;
		foodFile >> numFood;
		Food::setNumFood(numFood);

		for (int i = 0; i < numFood; ++i) {
			Food temp = getFoodData(foodFile);
			foodList.push_back(temp);
		}
	}
}


void MainModule::writeDataFile() {
	std::ofstream customerFile("customer.dat"), orderFile("order.dat"), foodFile("food.dat");
	if (customerFile) {
		customerFile << Customer::getNumCustomer() << std::endl;
		for (Customer& temp : customerList) {
			customerFile << temp.getCustomerID() << std::endl;
			customerFile << temp.getName() << std::endl;
			customerFile << temp.getAddress() << std::endl;
			customerFile << temp.getContactNo() << std::endl;
		}
	}
	customerFile.close();

	if (orderFile) {
		orderFile << Order::getNumOrder() << std::endl;
		for (Order& temp : orderList) {
			orderFile << temp.getOrderID() << std::endl;
			orderFile << temp.getFoodID() << std::endl;
			orderFile << temp.getQuantity() << std::endl;
			orderFile << temp.getCustomerID() << std::endl;
			orderFile << temp.getTotalPrice() << std::endl;
		}
	}
	orderFile.close();

	if (foodFile) {
		foodFile << Food::getNumFood() << std::endl;
		for (Food& temp : foodList) {
			foodFile << temp.getFoodID() << std::endl;
			foodFile << temp.getFlavour() << std::endl;
			foodFile << temp.getWeight() << std::endl;
			foodFile << temp.getUnitPrice() << std::endl;
		}
	}
	foodFile.close();
}


void MainModule::printMenu() {
	using namespace std;
	cout << "Welcome to Food Ordering System" << endl;
	std::cout << std::string(50, '-') << std::endl;
	cout << "1. Ordering Module" << endl;
	cout << "2. Menu Management Module" << endl;
	cout << "3. Customer Management Module" << endl;
	cout << "4. Exit" << endl;
}


void MainModule::moduleProcess(int input) {
	switch (input) {
	case 1:
	{
		if (foodList.empty()) {
			std::cout << "You are not allowed to enter this module with empty food list!" << std::endl;
		}
		else if (customerList.empty()) {
			std::cout << "You are not allowed to enter this module with empty customer list!" << std::endl;
		}
		else {
			OrderingModule om(&customerList, &orderList, &foodList);
			do {
				om.printMenu();
				int input = 0;
				std::cout << std::string(50, '-') << std::endl;
				std::cout << "Enter your option:";
				std::cin >> input;
				std::cout << std::string(50, '-') << std::endl;
				om.moduleProcess(input);
			} while (om.isContinue());
		}
	}
	break;
	case 2:
	{
		MenuManagementModule mm(&foodList, &orderList);
		do {
			mm.printMenu();
			int input = 0;
			std::cout << std::string(50, '-') << std::endl;
			std::cout << "Enter your option:";
			std::cin >> input;
			std::cout << std::string(50, '-') << std::endl;
			mm.moduleProcess(input);
		} while (mm.isContinue());
	}
	break;
	case 3:
	{
		CustomerManagementModule cm(&customerList,&orderList);
		do {
			cm.printMenu();
			int input = 0;
			std::cout << std::string(50, '-') << std::endl;
			std::cout << "Enter your option:";
			std::cin >> input;
			std::cout << std::string(50, '-') << std::endl;
			cm.moduleProcess(input);
		} while (cm.isContinue());
	}
	break;
	case 4:
		stopLoop();
		break;
	default:
		std::cout << "Invalid input! Please try again!" << std::endl;
	}
}