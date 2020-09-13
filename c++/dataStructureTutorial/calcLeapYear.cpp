#include <iostream>
#include <vector>

bool isLeapYear(int year) {
	bool result = false;
	
	if(year%100==0){
		if(year%400==0)
			result = true;
	}
	else{
		if(year%4==0 && year%100!=0)
			result = true;
	}
	return result;
}

int main() {
	using namespace std;
	
	vector<int> leapYearList;
	int begin = 0, end = 0;
	cout << "Enter the begin year:";
	cin >> begin;
	cout << "Enter the end year:";
	cin >> end;

	for (int year = begin; year <= end; ++year) {
		if (isLeapYear(year))
			leapYearList.push_back(year);
	}

	if (leapYearList.empty()) {
		cout << "There are no leap year between " << begin << " and " << end << endl;
	}
	else {
		cout << "The leap years between " << begin << " and " << end << " are :" << endl;
		for (int year : leapYearList)
			cout << year << " ";
	}

	return 0;
}
