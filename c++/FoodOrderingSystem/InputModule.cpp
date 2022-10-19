#include "InputModule.h"
#include <iostream>


int InputModule::getIntegerInput(std::string prompt) {
	int input = 0;

	std::cout << prompt;
	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "The input should be integer numbers ! Please try again!" << std::endl;

		std::cout << prompt;
		std::cin >> input;
	}
	std::cin.ignore(1000, '\n');

	return input;
}


std::string InputModule::getStringInput(std::string prompt) {
	std::string input = "";

	std::cout << prompt;
	while (input.length() == 0) {
		std::getline(std::cin, input);
	}

	return input;
}


char InputModule::getCharacterInput(std::string prompt) {
	char input = '\0';

	std::cout << prompt;
	while (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "The input should be number ! Please try again!" << std::endl;
		std::cout << prompt;
	}
	std::cin.ignore(1000, '\n');

	return input;
}


double InputModule::getDoubleInput(std::string prompt) {
	double input = 0.0;

	std::cout << prompt;
	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "The input should be floating numbers ! Please try again!" << std::endl;

		std::cout << prompt;
		std::cin >> input;
	}
	std::cin.ignore(1000, '\n');

	return input;
}