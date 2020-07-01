#include<iostream>
#include<cmath>
using namespace std;

int getRange(int a, int b, int c);

int main()
{
	for (int i = 0; i < 6; i++) {
		cout << static_cast<char>(65 + i);
		for (int j = 1; j < 6 - i; j++)
			cout << j;
		cout << endl;
	}

	return 0;
}

int getRange(int a, int b, int c)
{
	int max=fmax(a, (fmax(b, c)));
	int min = fmin(a, (fmin(b, c)));

	int def = max - min;

	return def;
}
/*
#include <fstream>
#include<iomanip>

int main()
{
	ofstream gameFile;
	double highscore = 100;

	gameFile.open("gameLog.txt");
	gameFile << setprecision(2) << fixed << showpoint;
	gameFile << highscore;

}
*/