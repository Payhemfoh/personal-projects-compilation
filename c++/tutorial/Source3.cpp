#include<iostream>
#include<cstring>
using namespace std;

struct vegetable {
	char name[20] = {'\0'};
	double price;
	double unitSold;
};
int main()
{
	//declare variable
	vegetable vege1;
	//assign price
	vege1.price = 3.55;
	//input string
	strcat_s(vege1.name,"veg1");
	//declare array
	vegetable vege2[100];
	//initialize
	for (int i = 0; i < 100; i++)
		vege2[i].price = 0;
	return 0;
}