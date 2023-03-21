#include <iostream>
#include <string>
#include "Order.h"


Order::Order(int foodID, int quantity, int customerID, double totalPrice)
	:foodID(foodID), quantity(quantity), customerID(customerID), totalPrice(totalPrice)
{
	numOrder++;
	this->orderID = numOrder;
}

Order::Order(int orderID, int foodID, int quantity, int customerID, double totalPrice)
	:orderID(orderID), foodID(foodID), quantity(quantity), customerID(customerID), totalPrice(totalPrice) {}

int Order::getOrderID() { return this->orderID; }
int Order::getFoodID() { return this->foodID; }
int Order::getQuantity() { return this->quantity; }
int Order::getCustomerID() { return this->customerID; }
double Order::getTotalPrice() { return this->totalPrice; }
int Order::getNumOrder() { return numOrder; }

void Order::setOrderID(int id) { this->orderID = id; }
void Order::setFoodID(int id) { this->foodID = id; }
void Order::setQuantity(int qty) { this->quantity = qty; }
void Order::setCustomerID(int id) { this->customerID = id; }
void Order::setTotalPrice(double totalPrice) { this->totalPrice = totalPrice; }
void Order::setNumOrder(int num) { numOrder = num; }


void Order::print() {
	printf("%-8d|%-8d|RM %-7.2f\n", this->getOrderID(), this->getFoodID(), this->getTotalPrice());
}


void Order::printDetails() {
	std::cout << "Order ID : " << this->orderID << std::endl;
	std::cout << "Food ID : " << this->foodID << std::endl;
	std::cout << "Customer ID : " << this->customerID << std::endl;
	std::cout << "Quantity : " << quantity << std::endl;
	std::cout << "Total Price : RM " << this->totalPrice << std::endl;
}


void Order::printDetails(Food& food, Customer& customer) {
	std::string breakLine(50, '-');
	std::string starLine(50, '*');

	std::cout << starLine << std::endl;
	std::cout << "Order ID : " << this->orderID << std::endl;
	std::cout << breakLine << std::endl;
	std::cout << "Food ID : " << this->foodID << std::endl;
	std::cout << "Food Flavour : " << food.getFlavour() << std::endl;
	std::cout << "Food Weight : " << food.getWeight() << "kg" << std::endl;
	std::cout << "Food Unit Price : RM" << food.getUnitPrice() << std::endl;
	std::cout << breakLine << std::endl;
	std::cout << "Customer ID : " << this->customerID << std::endl;
	std::cout << "Customer Name : " << customer.getName() << std::endl;
	std::cout << "Customer Address : " << customer.getAddress() << std::endl;
	std::cout << "Customer Contact No. : " << customer.getContactNo() << std::endl;
	std::cout << breakLine << std::endl;
	std::cout << "Quantity : " << quantity << std::endl;
	std::cout << "Total Price : RM" << this->totalPrice << std::endl;
	std::cout << starLine << std::endl;
}


bool Order::operator <(Order& other) {
	return this->orderID < other.orderID;
}

int Order::numOrder = 0;