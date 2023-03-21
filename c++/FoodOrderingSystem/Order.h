#pragma once
#include "Printable.h"
#include "Food.h"
#include "Customer.h"

/*
	Order class (implement Printable)
	This class store the order information required in this program which are:
	orderID which will be assigned automatically according to the number of order data present
	foodID, quantity, customerID, totalPrice of order
	numOrder which represent the number of customer data present currently in this program
*/
class Order : public Printable {
private:
	int orderID;
	int foodID;
	int quantity;
	int customerID;
	double totalPrice;
	static int numOrder;
public:
	/*
	This constructor is used to create a new profile for the user which require:
	foodID,quantity and customerID and totalPrice of the order
	this constructor will increase the numOrder and assign the orderID automatically
	*/
	Order(int foodID = 0, int quantity = 0, int customerID = 0, double totalPrice = 0.0);

	/*
	This constructor is used to read the order profile from the data file
	This constructor will not increase the numOrder but will assign directly by the input from data file
	*/
	Order(int orderID, int foodID, int quantity, int customerID, double totalPrice);

	int getOrderID();
	int getFoodID();
	int getQuantity();
	int getCustomerID();
	double getTotalPrice();
	static int getNumOrder();

	void setOrderID(int id);
	void setFoodID(int id);
	void setQuantity(int qty);
	void setCustomerID(int id);
	void setTotalPrice(double totalPrice);
	static void setNumOrder(int num);

	/*
	print() method used to display the simplified detail of the order object
	primary used in the table display
	*/
	void print();

	/*
	printDetails() method will print all the detail of the order object line-by-line
	*/
	void printDetails();

	/*
	This printDetails() method is overloaded version which will print:
	detail of the order object
	detail of the customer
	detail of the food
	*/
	void printDetails(Food& food, Customer& customer);

	/*
	This operator is overloaded for the sorting based on the orderID
	*/
	bool operator <(Order& other);
};
