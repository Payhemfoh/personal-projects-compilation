#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct Book {
	string title;
 	string ISBN;
 	string author;
 	string publisher;
 	int quantity;
 	double wholesaleCost;
 	double retailCost;
};

struct Payment {
	int orderID;
	string date;
	string ISBN;
	string title;
	int quantity;
	double price;
};

const int SIZE = 100;
const int PAYMENTSIZE = 50;
const double TAXRATE = 0.06;

void menu();
void inputBook(Book book[], int &);
void printBook(Book book[], int);
void editBook(Book book[], int);
void deleteBook(Book [], int &);
void exportHTML(Book [], int);
void printInventory();
void processInventory(Book book[], int&);
void printSearchOption();
void processSearchOption(Book book[], int);
void processCashier(Book book[], int size, int &orderID);
void printCashier2(Payment payments[], int);
void processMenu(Book [], int &, int &orderID);
void writeFile(Book [],int);
int readFile(Book book[]);

int main(){
	int size = 0, orderID = 0;
	Book book[SIZE];
	
	size = readFile(book);
	processMenu(book, size, orderID);
	writeFile(book,size);

	return 0;
}

void printMenu(){
	cout << "INTI Smart Book Store" << endl
		 << "Main Menu" << endl
		 << "1. Cashier" << endl
		 << "2. Book Database" << endl
		 << "3. Export Book Records" << endl
		 << "4. Exit" << endl;
}

void processMenu(Book book[], int &size, int &orderID){
	int choice = 0, choice2 = 0, i = 0, option = 0;
	Book temp;
	bool discontinue = true;
	
	do{
		printMenu();
		
		cout << "Enter your choice: ";
		cin >> option;
		cout << endl;
	
		switch(option){
			case 1 : 
				processCashier(book, size, orderID);
				break;
			
			case 2 :
				processInventory(book, size);
				break;
				
			case 3 :
				exportHTML(book, size);
				break;
					
			case 4 :
				discontinue = false;
				break;
				
			default : cout << "Invalid Option!!! Please Try Again..." << endl << endl;
		}
	}while(discontinue);
	
}
void inputBook(Book book[], int &size){
	int i = 0;
	Book temp;
	bool discontinue = true;
	char confirm;
	cin.ignore();
	if(size<100){
		do{
			cout << "Enter the Title of the Book: ";
			getline(cin, temp.title);
		
			cout << "Enter the ISBN of the Book: ";
			cin >> temp.ISBN;
			
			cin.ignore();
		
			cout << "Enter the Author of the Book: ";
			getline(cin, temp.author);
		
			cout << "Enter the Publisher of the Book: ";
			getline(cin, temp.publisher);
			cout << endl;
			
			cout << "Enter the Retail Price of the Book: ";
			cin >> temp.retailCost;
			
			cout << "Enter the Wholesale Price of the Book: ";
			cin >> temp.wholesaleCost;
			
			cout << "Enter the Quantity of the Book: ";
			cin >> temp.quantity;
		
			book[size] = temp;
			++size;

			cout << "Do you want to continue? [Y/N]" << endl;
			cin >> confirm;
		
			if(confirm == 'Y' || confirm == 'y'){
				discontinue = false;
			}
			else{
				discontinue;
			}
		}while(discontinue);
	}
	else{
		cout << "The list if full..." << endl;
	}
	
	
}
void editBook(Book book[], int size){
	int pos = -1;
	string input="";
	
	cin.ignore();
	
	cout << "Enter the Title of the Book to be edit: ";
	getline(cin, input);
	cout << endl;

	for (int i=0; i<size; i++){
		if(input == book[i].title){
			pos = i;
			break;
		}
	}
	
	if (pos != -1){
		cout << "Existing Books" << endl
			 << "-------------------" << endl;
		cout << "Title: " << book[pos].title << endl
			 << "ISBN: " << book[pos].ISBN << endl
			 << "Author: " << book[pos].author << endl
			 << "Publisher: " << book[pos].publisher << endl << endl;
		
		string newISBN, newAuthor, newPublisher;
		char option = '\0';

		cout << "Please select the field to edit" <<endl;
		cout << "1.Title" <<endl;
		cout << "2.ISBN" <<endl;
		cout << "3.Author" <<endl;
		cout << "4.Publisher" <<endl;
		cout << "5. Back" << endl;
		
		cout << "Option: ";
		cin >> option;
		cout << endl;

		cin.ignore();
		switch(option){
			case '1':
				cout << "Enter the new title of book: ";
				getline(cin,input);
				
				book[pos].title = input;
				
				cout << "The data had been updated successfully" << endl;
				break;
				
			case '2':
				cout << "Enter the new ISBN of book";
				getline(cin,input);
				
				book[pos].ISBN = input;
				
				cout << "The data had been updated successfully" << endl;
				break;
			
			case '3':
				cout << "Enter the new author of book";
				getline(cin,input);
				
				book[pos].author = input;
				
				cout << "The data had been updated successfully" << endl;
				break;
				
			case '4':
				cout << "Enter the new publisher of book";
				getline(cin,input);
				
				book[pos].publisher = input;
				
				cout << "The data had been updated successfully" << endl;
				break;
				
			case '5':
				break;
			
			default: cout << "Invalid Input!!! Please try again..." << endl;
		}
	}	
}
void deleteBook(Book book[], int &size){
	char confirm = '\0';
	int i = 0;
	int pos = -1;
	book;
	string input = "";
	
	cin.ignore();
	
	cout << "Enter the title of the book that you want to delete: ";
	getline(cin, input);
	
	for (int i=0; i<size; ++i){
		if (input == book[i].title){
			pos = i;
			break;
		}
	}

	if (pos != -1){
        cout << "Existing Books" << endl
        	 << "-------------------" << endl;
        cout << "Title: " << book[pos].title  << endl
        	 << "ISBN: " << book[pos].ISBN << endl
        	 << "Author: " << book[pos].author << endl
        	 << "Publisher: " << book[pos].publisher << endl;
	
       	cout << "Do you want to delete this book? [Y/N]: ";
        cin  >> confirm;

        if (confirm == 'Y' || confirm == 'y'){
            
            Book temp;
		
			for(int i=pos;i<size-1;++i){
				book[i] = book[i+1];
			}	
		
			book[size] = temp;
			size--; 	
            
            cout << "Book deleted successfully...";
        }
       	else
           	cout << "Transaction aborted!";
    }
    else{
    		cout<< "Book not found!" << endl;
       		cout << "Try another book..." << endl;
    }
}
void printBook(Book book[], int size, int index){
	cout << "Title: " << book[index].title << endl;
	cout << "ISBN: " << book[index].ISBN << endl;
	cout << "Author: " << book[index].author << endl;
	cout << "Publisher: " << book[index].publisher << endl << endl;
}
void exportHTML(Book book[], int size){
	fstream bookFile;
	
	cin.ignore();

    bookFile.open("Books records.html", ios::out);

  	if (!bookFile){
    	cout << "Unable to create Book Records.html file!";
   	 	return;
  	}

  	bookFile << setprecision(2) << showpoint << fixed ;
  	//start html header
  	bookFile << "<!DOCTYPE html>\n";
  	bookFile << "<html>\n";
 	bookFile << "<head><title>Books Records</title></head>\n";
  	bookFile << "<body>\n";

  	//start table
  	bookFile << "<table border=\"1\">\n";
  	bookFile << "<tr><th>ISBN</th><th>Title</th></tr>\n";

  	for (int i=0; i<size; i++){
        bookFile << "<tr>\n";
        bookFile << "<td>" << book[i].ISBN << "</td>\n";
        bookFile << "<td>" << book[i].title << "</td>\n";
        bookFile << "<td>" << book[i].author << "</td>\n";
        bookFile << "<td>" << book[i].publisher << "</td>\n";
        bookFile << "</tr>\n";
    }

	bookFile << "</table>\n";
  	//end the html section
  	bookFile << "</body>\n";
  	bookFile << "</html>\n";

  	bookFile.close(); //close the file stream
  	cout << "All data have been exported to Books Records.html file." << endl << endl;
}
void printInventory(){
	cout << "Study Smart Book Store" << endl
		 << "Inventory Database" << endl
		 << endl;
	cout << "1. Search Book" << endl
		 << "2. Add Book" << endl
		 << "3. Edit Book" << endl
	     << "4. Delete Book" << endl
		 << "5. Return to the Main Menu" << endl
		 << endl;
}
void processInventory(Book book[], int &size){
	int option = 0, choice = 0;
	bool discontinue = true;
	
	do{
		printInventory();
	
		cout  << "Enter Your Choice: ";
		cin >> choice;
		cout << endl;
		
		switch(choice){
			case 1 :
				processSearchOption(book, size);
				break;
			case 2 : 
				cout << "Add Book Option" << endl
					 << "------------------" << endl;
									  
				inputBook(book, size);
				break;
						
			case 3 : 
				cout << "Edit Book Option" << endl
					 << "-------------------" << endl;
								 
				editBook(book, size);
				break;
						
			case 4 : 
				deleteBook(book, size);
				break;
							
			case 5 :
				discontinue = false;
				cout << "Returning to Main Menu..." << endl;
				break;
							
			default : cout << "Invalid Option!!! Please Try Again..." << endl << endl;
		}
	}while(discontinue);
}
void printSearchOption(){
	cout << "Search Option" << endl
		 << "----------------" << endl
		 << "1. Search by Title" << endl
		 << "2. Search by ISBN" << endl
		 << "3. Back" << endl << endl;
}
void processSearchOption(Book book[], int size){
	Book temp;
	int choice2 = 0, index = -1;
	string input;
	bool discontinue = true;
	
	do{
		printSearchOption();
		
		cout << "Enter your choice of search: ";
		cin >> choice2;
		
		cin.ignore();
		switch(choice2){
			case 1 :
				cout << "Enter the title of the book: ";
				getline(cin, input);
				cout << endl;
				
				for(int i=0; i<size; ++i){
					if(input == book[i].title){
						index = i;
						break;
					}
				}
				if(index != -1){
					printBook(book, size, index);
				}		
				break;
									
			case 2 :
				cout << "Enter the ISBN of the book: ";
				getline(cin, input);
				cout << endl;
				
				for(int i=0; i<size; ++i){
					if(input == book[i].ISBN){
						index = i;
						break;
					}
				}	
				
				if(index != -1){
					printBook(book, size, index);
				}			
				break;
				
			case 3:
				discontinue = false;
				break;
		}		
	}while(discontinue);	
}
void processCashier(Book book[], int size, int &orderID){
	bool outerLoop;
	
	do{
		string date, input;
		int i = 0, option = 0, paymentsize = 0, pos = -1;
		char confirm;
		bool discontinue = true;
		Payment temp;
		Payment payments[PAYMENTSIZE];
		
		do{
			temp.orderID = orderID;
			cout << "Enter the date [MM/DD/YY]: ";
			cin >> temp.date;
			cout << "Please select title or ISBN: " << endl
				 << "1. Title" << endl
				 << "2. ISBN" << endl;
			cout << "Enter your option: ";
			cin >> option;
			cin.ignore();
			
			switch(option){
				case 1:
					cout << "Enter the title of the book: ";
					getline(cin, input);
					
					for (i=0; i<size; i++){
						if(input == book[i].title){
							pos = i;
							break;
						}
					}
					
					if(pos == -1){
						cout << "Book not found!!!" << endl;
					}
					else{
						temp.title = book[pos].title;
						temp.ISBN = book[pos].ISBN;
						temp.price = book[pos].retailCost;
					}
					break;
				
				case 2:
					cout << "Enter the ISBN of the book: ";
					getline(cin, input);
					
					for (i=0; i<size; i++){
						if(input == book[i].ISBN){
							pos = i;
							break;
						}
					}
					
					if(pos == -1){
						cout << "Book not found!!!" << endl;
					}
					else{
						temp.title = book[pos].title;
						temp.ISBN = book[pos].ISBN;
						temp.price = book[pos].retailCost;
					}
					break;
				
				default: cout << "Invalid Input!!! Please try again..." << endl << endl;
			}
			
			if(pos != -1){
				payments[paymentsize] = temp;
				++size;	
				
				cout << "Enter the quantity: ";
				cin >> temp.quantity;
						
				cout << "Study Smart Book Store" << endl
					 << "Cashier Module" << endl << endl;
						
				cout << "Order ID: " << temp.orderID << endl;
				cout << "Date: " << temp.date << endl;
				cout << "ISBN: " << temp.ISBN << endl
					 << "Title: " << temp.title << endl
					 << "Quantity of the Book: " << temp.quantity << endl
					 << "Price: RM " << temp.price << endl << endl;
			
				cout << "Continue Next Book [Y/N]: ";
				cin >> confirm;
					
				if(confirm == 'Y' || confirm == 'y'){
					discontinue = true;
				}
				else if(confirm == 'N' || confirm == 'n'){
					discontinue = false;
				}
				else{
					cout << "Invalid Option!!! Please try again..." << endl << endl;
				}
			}	
		}while(discontinue);
		
		printCashier2(payments, paymentsize);
		++orderID;
		
		cout << "Do you want to enter the next sale [Y/N]? " << endl;
		cin >> confirm;
		cout << endl;
		
		switch(confirm){
			case 'Y': 
			case 'y':
				break;
			
			case 'N': 
			case 'n': 
				outerLoop = false;
				break;
				
			default: cout << "Invalid Input!!!" << endl << endl;
		}
	}while(outerLoop);
}
void printCashier2(Payment payments[], int size){
	double total = 0;
	double subtotal = 0;
	double tax = 0;
	
	for(int i=0; i<size; i++){
		subtotal += payments[i].price * payments[i].quantity;
	}
	tax = subtotal * TAXRATE;
	total = subtotal + tax;
	
	cout << setw(50) << "Study Smart Book Store" << endl;
	cout << endl << endl;
	cout << setw(10) << "Date:" << payments[size].date << setw(50) << "Order ID:" << payments[size].orderID << endl;
	cout << endl << endl;
	cout << setw(8) << "Qty" << setw(8) << "ISBN" << setw(25) << "Title" << setw(25) << "Price" << setw(15) << "Total" << endl;
	for(int i=0; i<size; i++){
		cout << setw(7) << payments[i].quantity 
			 << setw(8) << payments[i].ISBN 
			 << setw(25) << payments[i].title << fixed << setprecision(2) 
			 << setw(22) << "$" << payments[i].price << fixed
			 << setw(11) << "$" << payments[i].quantity*payments[i].price << endl;
	}
	cout << endl << endl << endl << endl << endl;
	cout << setw(70) << "Sub Total" << setw(10) << subtotal << endl;
	cout << setw(64) << "Tax" << setw(16) << tax << endl;
	cout << setw(66) << "Total" << setw(14) << total << endl;
	cout << endl;
	cout << "Thank you for Shopping at smart study! Land!" << endl;
	cout << endl << endl;
}
void writeFile(Book book[],int size){
	ofstream output("book.dat");
	
	if(output.is_open()){
		for(int i=0;i<size;++i){
			output<<book[i].title<<endl;
			output<<book[i].ISBN<<endl;
			output<<book[i].author<<endl;
			output<<book[i].publisher<<endl;
			output<<book[i].quantity<<endl;
			output<<book[i].wholesaleCost<<endl;
			output<<book[i].retailCost<<endl;
		}
		cout<<"All the data had been writen into the file"<<endl;
	}else{
		cout<<"Failed to open the file! Please try again!"<<endl;
	}
	
	output.close();
}
int readFile(Book book[]){
	int size = 0;
	ifstream input("book.dat");
	
	if(input.is_open()){
		while(!input.eof()){
			Book temp;
			
			input>>temp.title;
			input>>book[size].ISBN;
			input>>book[size].author;
			input>>book[size].publisher;
			input>>book[size].quantity;
			input>>book[size].wholesaleCost;
			input>>book[size].retailCost;
			
			book[size] = temp;
			++size;
		}
		cout<<"All the data had been readed"<<endl;
	}else{
		cout<<"Failed to open the file! Please try again!"<<endl;
	}
	
	input.close();
	return size;
}
