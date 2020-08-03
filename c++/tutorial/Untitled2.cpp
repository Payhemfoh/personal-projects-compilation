//function demonstration
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;

//function prototype
void displayMenu ();
int enterInteger(string );
double getDouble(string );
void calcFahrenheit(double celcius, double &fahrenheit);
void calcCelcius(double fahrenheit, double &celcius);
void processOption (int option);
char askYesNo (string );
void startApplication();

int main(){
	
	startApplication();
	
	return 0;
} 

void displayMenu (){
	cout << "Temperature converter" << endl;
	cout << "---------------------" << endl;
	cout << "1. Celcius to Fahrenheit" << endl;
	cout << "2. Fahrenheit to Celcius" << endl;
	cout << "3. End the program." << endl;
}

/*get integer-prompt user to enter integer and return back value*/
//int shi return type  
int enterInteger(string promptText){
	
	int option = 0;
	
	cout << "\n" << promptText;
	cin >> option;
	
	return option;
}

//get double value - accept and return a double value
double getDouble(string promptText){
	
	double value = 0.0;
	
	cout << "\n" << promptText << endl ;
	cin >> value;
	
	return value;
}

void calcFahrenheit(double celcius, double &fahrenheit){

	//formula for celcius to fahrenheit
	fahrenheit = celcius * (double)9/5 + 32;
}

void calcCelcius(double fahrenheit, double &celcius){

	celcius = (fahrenheit - 32) * 5 / (double) 9;
}

//core function to process the user options
void processOption (int option){
	double celcius = 0.0;
	double fahrenheit = 0.0;
	if (option == 1){
		//convert c to f
		//display result
			
		celcius = getDouble ("Enter celcius");
		
		calcFahrenheit (celcius, fahrenheit);
			
		cout << celcius <<" celcius = " << fahrenheit << " fahrenheit" << endl ;
		
	}else if (option == 2){
		//convert f to c
		fahrenheit = getDouble ("Enter fahrenheit");
		
		calcCelcius(fahrenheit, celcius);
			
		cout << fahrenheit <<" fahrenheit = " << celcius << " celcius" << endl ;
		
	}else if (option == 3){
		cout << "Thank you for using temperature converter. Have a nice day." << endl;
		
		//end the loop
		//break;
		//return; (no suggested)
		exit (0); //terminate the program
	}else {
		cout << "Invalid Option! \nPlease reenter again." << endl << endl;
	}
}

char askYesNo (string promptText){
	char next = '\0';
	cout << promptText << endl;
	cin >> next;
	
	next = toupper(next);
	
	return next;
}

void startApplication(){
	int option = 0;
	char next = '\0';
	
	cout << setprecision(2) << showpoint << fixed;
	
	
	
	do {
		//display menu to user 
		displayMenu ();
		
		//# ###      ###  #####
		option = enterInteger ("Enter an option");
	
		processOption (option); //process user option
		
		next = askYesNo( "\nDo you want to continue? [Y/N]: " );
	
	}while (next == 'Y');
}
