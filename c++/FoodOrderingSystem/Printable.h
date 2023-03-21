#pragma once

/*
	This is the interface used to print the detail of the object
	print() method should display the simplified detail of object inline (a straight line)
	printDetails() method should display the details of object line by line
*/
class Printable {
public:
	virtual void print() = 0;
	virtual void printDetails() = 0;
};