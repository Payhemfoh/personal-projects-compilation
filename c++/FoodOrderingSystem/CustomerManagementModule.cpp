#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include "CustomerManagementModule.h"
#include "InputModule.h"


CustomerManagementModule::CustomerManagementModule(std::list<Customer>* customerList,std::list<Order>* orderList)
	:Module()
	{
		this->customerList = customerList; 
		this->orderList = orderList;
	}


CustomerManagementModule::~CustomerManagementModule() {
	std::cout << "Returning to main module..." << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}


void CustomerManagementModule::printMenu() {
	using namespace std;
	cout << "Welcome to Customer Management Module" << endl;
	std::cout << std::string(50, '-') << std::endl;
	cout << "1. Create New Customer Profile" << endl;
	cout << "2. Modify Customer Profile" << endl;
	cout << "3. Delete Customer Profile" << endl;
	cout << "4. Display Customer Profile" << endl;
	cout << "5. Return to Main Menu" << endl;
}


void CustomerManagementModule::moduleProcess(int input) {
	switch (input) {
	case 1:
		createNewProfile();
		break;
	case 2:
		modifyProfile();
		break;
	case 3:
		deleteProfile();
		break;
	case 4:
		displayProfile();
		break;
	case 5:
		stopLoop();
		break;
	}
}


void CustomerManagementModule::createNewProfile() {
	std::string name(""), address(""), contactNo("");

	name = InputModule::getStringInput("Enter customer name : ");
	address = InputModule::getStringInput("Enter customer address : ");
	contactNo = InputModule::getStringInput("Enter customer contact no : ");


	//create customer data
	Customer temp(name, address, contactNo);
	customerList->push_back(temp);
	
	//sort the list after added new data into the list
	customerList->sort();
}


void CustomerManagementModule::modifyProfile() {
	int input = 0;
	bool mainLoop = true;
	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Customer::getNumCustomer() + 1);
		input = InputModule::getIntegerInput("Enter Customer ID :");
		std::cout << std::string(50, '-') << std::endl;

		if (input>0 && input < Customer::getNumCustomer() + 1) {
			int choice = 0;
			bool innerLoop = true;
			std::list<Customer>::iterator cptr = std::find_if(
				customerList->begin(),
				customerList->end(),
				std::bind([](Customer& temp, int value) {return temp.getCustomerID() == value; }, std::placeholders::_1, input));

			do {
				//display customer information
				cptr->printDetails();

				//display choice
				printSelectionMenu();
				choice = InputModule::getIntegerInput("Your choice : ");
				std::cout << std::string(50, '-') << std::endl;

				//user enter new input
				switch (choice) {
				case 1:
				{
					std::string input = InputModule::getStringInput("Enter the new name of the customer : ");
					cptr->setName(input);
					std::cout << "The customer name had been changed." << std::endl;
					std::cout << std::string(50, '-') << std::endl;
				}
				break;
				case 2:
				{
					std::string input = InputModule::getStringInput("Enter the new address of the customer : ");
					cptr->setAddress(input);
					std::cout << "The customer address had been changed." << std::endl;
					std::cout << std::string(50, '-') << std::endl;
				}
				break;
				case 3:
				{
					std::string input = InputModule::getStringInput("Enter the new contact no of the customer : ");
					cptr->setContactNo(input);
					std::cout << "The customer contact no had been changed." << std::endl;
					std::cout << std::string(50, '-') << std::endl;
				}
				break;
				case 4:
					innerLoop = false;
					break;
				default:
					std::cout << "Invalid input! Please try again!" << std::endl;
				}
			} while (innerLoop);
		}
		else if (input == Customer::getNumCustomer() + 1) {
			mainLoop = false;
			std::cout << "Returning to module homepage..." << std::endl;
			std::cout << std::string(50, '-') << std::endl;
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (mainLoop);
}


void CustomerManagementModule::deleteProfile() {
	int input = 0;
	char choice = '\0';
	bool mainLoop = true;
	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Customer::getNumCustomer() + 1);
		input = InputModule::getIntegerInput("Your option : ");
		std::cout << std::string(50, '-') << std::endl;

		if (input > 0 && input < Customer::getNumCustomer() + 1) {
			
			std::list<Customer>::iterator cptr = std::find_if(
				customerList->begin(),
				customerList->end(),
				std::bind([](Customer& temp, int value) {return temp.getCustomerID() == value; }, std::placeholders::_1, input));
			
			//display customer information
			cptr->printDetails();

			bool confirmationLoop = true;
			//confirmation
			do {
				std::cout << std::string(50, '-') << std::endl;
				std::cout << "Are you sure you want to delete the customer profile of "
					<< cptr->getCustomerID() << " : " << cptr->getName() << "?[Y/N]" <<std::endl;
				choice = InputModule::getCharacterInput("Your choice : ");
				std::cout << std::string(50, '-') << std::endl;

				
				switch (choice) {
				case 'y':
				case 'Y':
					{
						/*
							loop through each order
							if contain same customer id, then delete the order.
							if customer id > cptr, then customer id - 1
						*/
						for (std::list<Order>::iterator optr = orderList->begin(); optr != orderList->end();++optr) {
							int customerID = cptr->getCustomerID();
							while(optr->getCustomerID() == customerID) {
								//delete the object and increase iterator by 1
								optr = orderList->erase(optr);
								Order::setNumOrder(Order::getNumOrder() - 1);

								if (optr == orderList->end())
									break;
							}
							//exit loop directly if optr already reach the end
							if (optr == orderList->end())
								break;

							if (optr->getCustomerID() > customerID) {
								optr->setCustomerID(optr->getCustomerID() - 1);
							}
						}

						std::list<Customer>::iterator currentPoint = cptr++;
						customerList->erase(currentPoint);
						std::for_each(cptr, customerList->end(), [](Customer& f) {f.setCustomerID(f.getCustomerID() - 1); });
						Customer::setNumCustomer(Customer::getNumCustomer() - 1);
						std::cout << "The food has been deleted from the menu." << std::endl;
						confirmationLoop = false;
					}
					break;
				case 'n':
				case 'N':
					confirmationLoop = false;
					std::cout << "The remove process had been canceled." << std::endl;
					break;
				default:
					std::cout << "Invalid Input! Please try again!" << std::endl;
				}
			} while (confirmationLoop);
		}
		else if (input == Customer::getNumCustomer() + 1) {
			mainLoop = false;
			std::cout << "Returning to module homepage..." << std::endl;
			std::cout << std::string(50, '-') << std::endl;
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (mainLoop);
}


void CustomerManagementModule::displayProfile() {
	int input = 0;
	bool mainLoop = true;
	do {
		printList();
		printf("Enter %d to return to module homepage.\n", Customer::getNumCustomer() + 1);
		input = InputModule::getIntegerInput("Your option : ");
		std::cout << std::string(50, '-') << std::endl;

		if (input > 0 && input < Customer::getNumCustomer() + 1) {
			for (Customer& temp : *customerList) {
				if (temp.getCustomerID() == input) {
					temp.printDetails();
					break;
				}
			}
		}
		else if (input == Customer::getNumCustomer() + 1) {
			mainLoop = false;
			std::cout << "Returning to module homepage..." << std::endl;
			std::cout << std::string(50, '-') << std::endl;
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (mainLoop);
}


void CustomerManagementModule::printList() {
	printf("%-12s|%-20s\n", "Customer ID", "Name");
	std::cout << std::string(50, '-') << std::endl;
	for (Customer& temp : *customerList) {
		temp.print();
	}
	std::cout << std::string(50,'-') << std::endl;
}


void CustomerManagementModule::printSelectionMenu() {
	using namespace std;
	std::cout << std::string(50, '-') << std::endl;
	cout << "1. Name" << endl;
	cout << "2. Address" << endl;
	cout << "3. Contact No" << endl;
	cout << "4. Exit" << endl;
	std::cout << std::string(50, '-') << std::endl;
}
