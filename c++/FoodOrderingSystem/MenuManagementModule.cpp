#include<iostream>
#include <string>
#include <algorithm>
#include <functional>
#include "MenuManagementModule.h"
#include "InputModule.h"


MenuManagementModule::MenuManagementModule(std::list<Food>* foodList, std::list<Order>* orderList)
	:Module(), foodList(foodList), orderList(orderList) {}


MenuManagementModule:: ~MenuManagementModule() {
	std::cout << "Returning to main module..." << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}


void MenuManagementModule::printMenu() {
	using namespace std;
	cout << "Welcome to Menu Management Module" << endl;
	std::cout << std::string(50, '-') << std::endl;
	cout << "1. View Menu" << endl;
	cout << "2. Add Menu" << endl;
	cout << "3. Edit Menu" << endl;
	cout << "4. Delete Menu" << endl;
	cout << "5. Exit" << endl;
}


void MenuManagementModule::moduleProcess(int input) {
	switch (input) {
	case 1:
		viewMenu();
		break;
	case 2:
		addMenu();
		break;
	case 3:
		editMenu();
		break;
	case 4:
		deleteMenu();
		break;
	case 5:
		stopLoop();
		break;
	default:
		std::cout << "Invalid Input! Please try again!" << std::endl;
	}
}


void MenuManagementModule::viewMenu() {
	bool loop = true;
	int option = 0;
	std::string breakLine(50, '-');

	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Food::getNumFood() + 1);
		option = InputModule::getIntegerInput("Your option: ");
		std::cout << breakLine << std::endl;

		if (option > 0 && option < Food::getNumFood() + 1) {
			for (Food& temp : *foodList) {
				if (temp.getFoodID() == option) {
					temp.printDetails();
				}
			}
		}

		else if (option == Food::getNumFood() + 1) {
			loop = false;
		}

		else {
			std::cout << "Invalid Input!" << std::endl;
		}

	} while (loop);
}


void MenuManagementModule::addMenu() {
	std::string flavour = "";
	double weight = 0.0;
	double unitPrice = 0.0;

	flavour = InputModule::getStringInput("Please enter food flavour : ");
	weight = InputModule::getDoubleInput("Please enter food weight(kg) : ");
	unitPrice = InputModule::getDoubleInput("Please enter food unit price(RM) : ");
	std::cout << std::string(50,'-') << std::endl;

	//create new food data
	Food f = Food(flavour, weight, unitPrice);
	foodList->push_back(f);

	foodList->sort();
}


void MenuManagementModule::editMenu() {
	bool loop = true;
	int option = 0;
	std::string breakLine(50, '-');

	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Food::getNumFood() + 1);
		option = InputModule::getIntegerInput("Your option: ");
		std::cout << breakLine << std::endl;

		if (option > 0 && option < Food::getNumFood() + 1) {
			std::list <Food> ::iterator ptr;

			ptr = find_if(foodList->begin(), foodList->end(),
				std::bind([](Food& f, int value) {return f.getFoodID() == value; }, std::placeholders::_1, option)
			);

			bool innerloop = true;
			do {
				
				ptr->printDetails();

				std::cout << "1. Food Flavour" << std::endl;
				std::cout << "2. Food Weight" << std::endl;
				std::cout << "3. Unit Price  " << std::endl;
				std::cout << "4. Exit " << std::endl;

				std::cout << breakLine << std::endl;

				int num = InputModule::getIntegerInput("Your option : ");
				std::cout << breakLine << std::endl;

				switch (num) {
					case 1:
						{

						std::string input = InputModule::getStringInput("Enter new food flavour:");
						ptr->setFlavour(input);
						std::cout << "The food flavour has been changed." << std::endl;
						std::cout << breakLine << std::endl;

					    } 
						break;
					
					case 2:
						{
							double input = 0.0;
							do {
								input = InputModule::getDoubleInput("Enter new food weight:");
								if (input <= 0) {
									std::cout << "The food weight should not less than 0! Please try again!" << std::endl;
								}
							}while (input <= 0);
							ptr->setWeight(input);
							std::cout << "The food weight has been changed." << std::endl;
							std::cout << breakLine << std::endl;
						}
						break;
					
					case 3:
						{
						double newInput = 0.0;
						do {
							newInput = InputModule::getDoubleInput("Enter new food price:");
							if (newInput <= 0) {
								std::cout << "The unit price should not less than 0! Please try again!" << std::endl;
							}
						} while (newInput <= 0);
						ptr->setUnitPrice(newInput);
						std::cout << "The food price has been changed." << std::endl;
						std::cout << breakLine << std::endl;
						}
						break;
					
					case 4:
						innerloop = false;
						break;

					default: 
						std::cout << "Invalid Input! Please try again!" << std::endl; 
				}

			} while (innerloop);
		}

		else if (option == Food::getNumFood() +1) {
			loop = false; 
		}

		else {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (loop);
}


void MenuManagementModule::deleteMenu() {
	bool loop = true;
	int option;
	std::string breakLine(50, '-');

	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Food::getNumFood() + 1);
		option = InputModule::getIntegerInput("Your option: ");
		std::cout << breakLine << std::endl;

		if (option > 0 && option < Food::getNumFood() + 1) {
			std::list <Food> ::iterator ptr;

			ptr = find_if(foodList->begin(), foodList->end(),
				std::bind([](Food& f, int value) {return f.getFoodID() == value; }, std::placeholders::_1, option)
			);

			ptr->printDetails();

			bool confirmation = true;

			do {
				char choice;

				std::cout << "Do you want to delete the food of" << ptr->getFoodID() << ":"
					<< ptr->getFlavour() << "from the menu? [Y/N]" << std::endl;

				choice = InputModule::getCharacterInput("Your option: ");

				switch (choice) {
				case 'y':
				case 'Y': 
					{
						/*
							loop through each order
							if contain same food id, then delete the order.
							if food id > cptr, then food id - 1
						*/
						for (std::list<Order>::iterator optr = orderList->begin(); optr != orderList->end(); ++optr) {
							int foodID = ptr->getFoodID();
							while (optr->getFoodID() == foodID) {
								//delete the object and increase iterator by 1
								optr = orderList->erase(optr);
								Order::setNumOrder(Order::getNumOrder() - 1);

								if (optr == orderList->end())
									break;
							}
							//exit loop directly if optr already reach the end
							if (optr == orderList->end())
								break;

							if (optr->getFoodID() > foodID) {
								optr->setFoodID(optr->getFoodID() - 1);
							}
						}

						std::list<Food>::iterator currentPoint = ptr++;
						foodList->erase(currentPoint);
						std::for_each(ptr, foodList->end(), [](Food& f) {f.setFoodID(f.getFoodID() - 1); });
						Food::setNumFood(Food::getNumFood() - 1);
						std::cout << "The food has been deleted from the menu." << std::endl;
						confirmation = false;
					}
					break;

				case 'n':
				case 'N':
					std::cout << "The food was not deleted from the menu." << std::endl;
					confirmation = false; 
					break;

				default:
					std::cout << "Invalid option! Please try again!" << std::endl;
				}

			} while (confirmation);

		}

		else if (option == Food::getNumFood() + 1) {
			loop = false;
		}

		else {
			std::cout << "Invalid Input!" << std::endl;
		}


	} while (loop);
}


void MenuManagementModule::printList() {
	std::string breakLine(50, '-');

	printf("%-8s|%-20s|%-10s\n", "Food ID", "Food Flavour", "Unit Price");
	std::cout << breakLine << std::endl;
	for (Food& temp : *foodList) {
		temp.print();
	}
	std::cout << breakLine << std::endl;
}