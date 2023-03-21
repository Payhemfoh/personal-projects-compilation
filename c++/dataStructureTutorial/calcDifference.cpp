#include <iostream>
#include <vector>

int main() {
	using namespace std;

	double input = 0;
	vector<double> input_list;

	do{
		cout << "Enter a number between 0 and 1,000,000 :";
		cin >> input;
		if (input >= 0 && input <= 1000000)
			input_list.push_back(input);
	} while (input >= 0 && input <= 1000000);

	double highest = input_list.at(0);
	double lowest = input_list.at(0);

	for (double num : input_list) {
		if (num > highest)
			highest = num;
		else if (num < lowest)
			lowest = num;
	}

	printf("Highest:%.2f\tLowest:%.2f\tDifference:%.2f\n", highest, lowest, highest - lowest);
	return 0;
}