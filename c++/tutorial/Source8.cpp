#include<iostream>
using namespace std;

int main()
{
	int revenue[5] = { 0 };
	int repeat = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Enter Salesman #" << i + 1 << " revenue:";
		cin >> revenue[i];
	}

	cout << "Sales Revenue Bar Chart (Each * = RM100)" << endl;
	for (int i = 0; i < 5; i++) {
		repeat = revenue[i]/100;
		cout << "Salesman #" << i + 1 << ':';
		for (int i = 0; i < repeat; i++) {
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}