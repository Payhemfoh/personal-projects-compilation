#include<iostream>
using namespace std;

class People
{
public:
	string name;
	int age;
};

People function()
{
	People Jeffery;
	Jeffery.name = "Jeffery";
	Jeffery.age = 18;

	return Jeffery;
}

int main()
{
	People Jeffery;
	Jeffery = function();
	return 0;
}