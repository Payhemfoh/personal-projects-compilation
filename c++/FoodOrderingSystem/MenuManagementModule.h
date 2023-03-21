#pragma once
#include <list>
#include "Food.h"
#include "Module.h"
#include "Order.h"

/*
	MenuManagementModule class(extends Module)
	This class is the menu management module of the program.
	This module included 4 function which are:
	create new food profile
	modify food profile
	delete food profile
	display food profile
*/
class MenuManagementModule : public Module {
private:
	std::list<Food> *foodList;
	std::list<Order>* orderList;
public:
	/*
	This constructor will point the pointer to the memory location of foodList
	*/
	MenuManagementModule(std::list<Food>* foodList,std::list<Order>* orderList);

	/*
	This destructor will show message to indicate that the user will be redirected to the main module.
	*/
	~MenuManagementModule();

	/*
	This method is used to print the menu of this module for user selection
	*/
	void printMenu();

	/*
	This method will display a list of food data for user selection and
	the full details of the selected food data will be displayed to the user after the selection.
	*/
	void viewMenu();

	/*
	This method will accept the user input
	then, a new Food object will be created and append into the list
	*/
	void addMenu();

	/*
	This method will display a list of food data for user selection.
	After that, the list of attributes of food is listed so that the user can select which data to modify.
	Then, the user input is accepted based on the datatype of the attributes and replace the old data with new input
	*/
	void editMenu();

	/*
	This method will show a list of food data for user selection
	and the confirmation will be show to the user before delete the data.
	If user confirm to delete the data, the data will be removed from the food list
	*/
	void deleteMenu();

	/*
	This method will print a list of food data
	*/
	void printList();

	/*
	This module will call the processing method based on the user input
	*/
	void moduleProcess(int input);
};
