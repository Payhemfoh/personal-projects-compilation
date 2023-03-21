#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <functional>
#include "Printable.h"
#include "Module.h"
#include "Customer.h"
#include "Food.h"
#include "Order.h"
#include "OrderingModule.h"
#include "CustomerManagementModule.h"
#include "MenuManagementModule.h"
#include "MainModule.h"

/*
	This is the main program of the system. The system will be started from here
*/
int main(int argc, char** argv) {
	MainModule system;
	int input = 0;
	do {
		system.printMenu();
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "Enter your option:";
		std::cin >> input;
		std::cout << std::string(50, '-') << std::endl;
		system.moduleProcess(input);
	} while (system.isContinue());
	return 0;
}