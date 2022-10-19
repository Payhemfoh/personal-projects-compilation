#pragma once

/*
	This abstract class contain the basic function needed by a module in this program
	All of the module created in this program should be inherited from this class
*/
class Module {
private:
	bool moduleLoop;
public:
	Module() { moduleLoop = true; }
	virtual void printMenu() = 0;
	virtual void moduleProcess(int input) = 0;
	bool isContinue() { return this->moduleLoop; }
	void stopLoop() { this->moduleLoop = false; }
};