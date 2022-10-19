#include<iostream>
#include<string>
#include "Food.h"


Food::Food(std::string flavour, double weight, double unitPrice)
	:flavour(flavour), weight(weight), unitPrice(unitPrice)
{
	++numFood;
	this->foodID = numFood;
}

Food::Food(int foodID, std::string flavour, double weight, double unitPrice)
	:foodID(foodID), flavour(flavour), weight(weight), unitPrice(unitPrice) {}

void Food::setFoodID(int foodID) { this->foodID = foodID; }
void Food::setFlavour(std::string flavour) { this->flavour = flavour; }
void Food::setWeight(double weight) { this->weight = weight; }
void Food::setUnitPrice(double unitPrice) { this->unitPrice = unitPrice; }
void Food::setNumFood(int num) { numFood = num; }

int Food::getFoodID() { return this->foodID; }
double Food::getWeight() { return this->weight; }
double Food::getUnitPrice() { return this->unitPrice; }
std::string Food::getFlavour() { return this->flavour; }
int Food::getNumFood() { return numFood; }


void Food::print() {
	printf("%-8d|%-20s| RM %-6.2f\n", foodID, flavour.c_str(), unitPrice);
}


void Food::printDetails() {
	using namespace std;
	cout << "Food ID : " << foodID << endl;
	cout << "Food Flavour : " << flavour << endl;
	cout << "Food Weight : " << weight << "kg" << endl;
	cout << "Food Unit Price : RM " << unitPrice << endl;
}


bool Food::operator <(Food& other) {
	return this->foodID < other.foodID;
}

int Food::numFood = 0;