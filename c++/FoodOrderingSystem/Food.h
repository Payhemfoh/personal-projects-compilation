#pragma once
#include <string>
#include "Printable.h"

/*
	Food class (implement Printable)
	This class store the food information required in this program which are:
	foodID which will be assigned automatically according to the number of food data present
	flavour, weight and unit price of food
	numFood which represent the number of customer data present currently in this program
*/
class Food : public Printable {
private:
	int foodID;
	std::string flavour;
	double weight;
	double unitPrice;
	static int numFood;

public:
	/*
	This constructor is used to create a new profile for the food which require:
	flavour, weight, unit price of the food
	this constructor will increase the numFood and assign the foodID automatically
	*/
	Food(std::string flavour = "", double weight = 0.0, double unitPrice = 0.0);

	/*
	This constructor is used to read the food profile from the data file
	This constructor will not increase the numFood but will assign directly by the input from data file
	*/
	Food(int foodID, std::string flavour, double weight, double unitPrice);

	void setFoodID(int foodID);
	void setFlavour(std::string flavour);
	void setWeight(double weight);
	void setUnitPrice(double unitPrice);
	static void setNumFood(int num);

	int getFoodID();
	double getWeight();
	double getUnitPrice();
	std::string getFlavour();
	static int getNumFood();

	/*
	print() method used to display the simplified detail of the food object
	primary used in the table display
	*/
	void print();

	/*
	printDetails() method will print all the detail of the food object line-by-line
	*/
	void printDetails();

	/*
	This operator is overloaded for the sorting based on the foodID
	*/
	bool operator <(Food& other);
};
