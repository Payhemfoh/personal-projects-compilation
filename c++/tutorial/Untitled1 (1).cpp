//function demonstration
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main(){
	
	int option = 0;
	double fahrenheit = 0.0;
	double celcius = 0.0;
	char next = '\0';
	
	cout << setprecision(2) << showpoint << fixed;
	
	do {
	
		cout << "Temperature converter" << endl;
		cout << "---------------------" << endl;
		cout << "1. Celcius to Fahrenheit" << endl;
		cout << "2. Fahrenheit to Celcius" << endl;
		cout << "3. End the program." << endl;
		cout << "\nEnter option.";
		cin >> option;
	
	
		if (option == 1){
			//convert c to f
			//display result
			cout << "Please input the value of celcius." << endl ;
			cin >> celcius;
		
			fahrenheit = celcius * (double)9/5 + 32;
			cout << celcius <<" celcius = " << fahrenheit << " fahrenheit" << endl ;
		
		}else if (option == 2){
			//convert f to c
			cout << "Please input the value of fahrenheit." << endl ;
			cin >> fahrenheit;
		
			celcius = (fahrenheit - 32) * 5 / (double) 9;
			cout << fahrenheit <<" fahrenheit = " << celcius << " celcius" << endl ;
		
		}else if (option == 3){
			cout << "Thank you for using temperature converter. Have a nice day." << endl;
			break;
		}else {
			cout << "Invalid Option! \nPlease reenter again." << endl << endl;
		}
		
		cout << "\nDo you want to continue? [Y/N]: " << endl;
		cin >> next;
		
		next = toupper(next);
	
	}while (next == 'Y');
	
	
	return 0;
} 
