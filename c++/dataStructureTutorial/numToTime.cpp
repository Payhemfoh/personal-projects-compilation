#include <iostream>
using namespace std;

int main() {
	int number = 0,hour = 0, minute =0;

	cout << "Enter a number:";
	cin >> number;

	hour = number / 100;
	minute = number % 100;
	while (minute > 60) {
		minute -= 60;
		hour += 1;
	}
	printf("The converted time is %02d:%02d", hour, minute);
	return 0;
}