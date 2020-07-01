#include<iostream>

using namespace std;

void inputCarRental(string&,char&,int&);
int calculateRental(string*,char*,int*);


int main()
{
	string car("");
	char insurance = '\0';
	int day = 0;

	inputCarRental(car, insurance, day);
	int rental=calculateRental(&car, &insurance, &day);

	cout << "The rental price is: RM " << rental << endl;
	return 0;
}

void inputCarRental(string& car, char& insurance, int& day)
{
	int repeat = 0;

	cout << "Enter car type [SEDAN/MPV] : ";
	cin >> car;
	cout << "Enter insurance type [N/P]\t:";
	cin >> insurance;

	do {
		cout << "Enter rental day [1-30]\t:";
		cin >> day;

		if (day >= 1 && day <= 30)
			repeat = 0;
		else
			repeat = 1;
	} while (repeat == 1);
}

int calculateRental(string* car, char* insurance, int* day)
{
	int insuPrice = 0;
	int totalPrice = 0;

	if (car->compare("SEDAN") == 0) {
		if (*insurance == 'N')
			insuPrice = 120;
		else if (*insurance == 'P')
			insuPrice = 120;
		else
			*insurance = 'N';
			insuPrice = 120;
	}
	else if (car->compare("MPV") == 0) {
		if (*insurance == 'N')
			insuPrice = 170;
		else if (*insurance == 'P')
			insuPrice = 300;
		else
			*insurance = 'N';
		insuPrice = 120;
	}
	else {
		*car = "SEDAN";
		if (*insurance == 'N')
			insuPrice = 120;
		else if (*insurance == 'P')
			insuPrice = 120;
		else
			*insurance = 'N';
			insuPrice = 120;
	}

	totalPrice = insuPrice * (*day);
	return totalPrice;
}