#pragma once
#include <string>
/*
	This module contain the methods to get the inputs from the user.
	The input in the program should be get by called the method in this class
*/
class InputModule
{
public:
	/*
		This method will handle the user input and return an user input in Int type.
	*/
	static int getIntegerInput(std::string prompt);
	/*
		This method will handle the user input and return an user input in std::string type.
	*/
	static std::string getStringInput(std::string prompt);
	/*
		This method will handle the user input and return an user input in Char type.
	*/
	static char getCharacterInput(std::string prompt);
	/*
		This method will handle the user input and return an user input in Double type.
	*/
	static double getDoubleInput(std::string prompt);
};

