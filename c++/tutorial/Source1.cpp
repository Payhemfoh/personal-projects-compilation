#include<iostream>
using namespace std;

int main()
{
	int marks[100];
	for (int i = 0; i < 100; i++)
		cin >> marks[i];

	int firstDivision[100][2];
	int num = 0;
	for (int i = 0; i < 100; i++) {
		if (marks[i] >= 70) {
			firstDivision[i][0] = i;
			firstDivision[i][1] = marks[i];
		}
	}
		
}