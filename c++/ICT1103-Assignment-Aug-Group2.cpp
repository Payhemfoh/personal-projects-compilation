//This is the residential management system for the Pearl Avenue 
#include<iostream>
#include<iomanip>
#include<cctype>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstring>
using namespace std;

//global variable and constant value
int const ACC_ARRAY_SIZE	=5;
int const CHAR_ARRAY_SIZE	=50;
int const PHONE_SIZE		=12;
int const SETW_SIZE			=25;
int const SETW_PAYMENT_SIZE	=20; 

//structure data
struct Date
{
	int d;						//Day
	int m;						//Month
	int y;						//Year
};

struct Customer
{
	int acc_no;								//Account No (C#####)
	char name[CHAR_ARRAY_SIZE];				//Resident name
	char address[CHAR_ARRAY_SIZE];			//Resident address
	int plot_no;							//Identifier of the house
	char contact_no[PHONE_SIZE];			//Handphone number
	Date last_payment;						//format:dd-mm-yyyy
	long double monthly_payment;			//Monthly Payment Amount
	double balance;							//Advance payment
	
	bool operator()(Customer i,Customer j)
	{
		return (i.acc_no<j.acc_no);
	}
}cust;

struct Payment
{
	int ref_no;
	Date date;
	int cus_no;
	long double payment_amount;
	char payment_type;
	string payment_method;
};

//functions
//enter modules functions
void enter_main_program();
void enter_addcust_module(vector<Customer>&);
void enter_customer_module(vector<Customer>&);
void enter_deduction_module(vector<Customer>&); 
void enter_delete_module(vector<Customer>&);
void enter_edit_module(vector<Customer>&);
void enter_list_module(vector<Customer>&);
void enter_outstand_module(vector<Customer>&);
void enter_payment_module(vector<Customer>&);
void enter_search_module(vector<Customer>&);

//display functions
void display_customer(vector<Customer>&,int);
void display_customer_menu();
void display_edit_menu();
void display_error(string);
void display_invalid(string);
void display_setw(string);
void display_success(string);
void display_title(string);
void display_main_menu();

//get input functions
void get_account_input(int*,string,char,int);
void get_char_input(char*,string,int);
void get_charArr_input(char* arr,string,int);
void get_date_input(Date*,string,int);
void get_long_double_input(double*,string,int);
void get_double_input(double*,string,int);
void get_payment_input(vector<Customer>&,Payment*,bool*,int*,int);
void get_payref_input(int*,string,char,int);
void get_phoneArr_input(char* arr,string,int);

//functional functions
bool search_customer(vector<Customer>&,int*);
void add_customer(vector<Customer>&);
void clear_window();
void edit_customer(vector<Customer>&,int);
void load_customer(vector<Customer>&);
void payType_to_payMethod(char*,string*);
void save_customer(vector<Customer>&);
void save_payment(Payment,vector<Customer>&,int,double,double);
void stop();

//validation functions
bool account_no_validation(vector<Customer>&,int);
bool customer_validation(vector<Customer>&,Payment*,int*);
bool date_validation(Payment*);
bool name_validation(vector<Customer>&,char*);
bool pay_amount_validation(vector<Customer>&,Payment*,int);
bool plot_no_validation(vector<Customer>&,int);

//main function
int main()
{	
	enter_main_program();
	return 0;
}


/*
-----------------------------------display functions------------------------------------------------------------------------------
*/
//display the certain customer information
void display_customer(vector<Customer>& customers,int i) 
{
	//display account number
	display_setw("Account No");
	cout<<": C"<<customers[i].acc_no<<endl;
	//display name
	display_setw("Name");
	cout<<": "<<customers[i].name<<endl;
	//display address
	display_setw("Address");
	cout<<": "<<customers[i].address<<endl;
	//display plot number
	display_setw("Plot No");
	cout<<": "<<customers[i].plot_no<<endl;
	//display contact number
	display_setw("Contact No");
	cout<<": "<<customers[i].contact_no<<endl;
	//display last payment date
	if(customers[i].last_payment.d==0&&customers[i].last_payment.m==0&&customers[i].last_payment.y==0)
	{
		display_setw("Last Payment Date No");
		cout<<": "<<"No record"<<endl;
	}
	else if(customers[i].last_payment.d!=0&&customers[i].last_payment.m!=0&&customers[i].last_payment.y!=0)
	{
		display_setw("Last Payment Date No");
		cout<<": "<<customers[i].last_payment.d<<"-"<<customers[i].last_payment.m<<"-"<<customers[i].last_payment.y<<endl;
	}
	else
		display_error("display of date!!");
	//display monthly payment amount
	display_setw("Monthly Payment Amount");
	cout<<": RM"<<customers[i].monthly_payment<<endl;
	//display account balance
	display_setw("Account Balance");
	cout<<": RM"<<customers[i].balance<<endl<<endl;
};

//customer module menu
void display_customer_menu()
{
	display_title("Customer Management Module");
	cout<<"1. New Record"<<endl;
	cout<<"2. Search Record"<<endl;
	cout<<"3. Delete Record"<<endl;
	cout<<"4. Edit Record"<<endl;
	cout<<"5. List Records"<<endl;
	cout<<"6. Outstanding Records"<<endl;
	cout<<"*. Deduct Monthly Payments"<<endl;
	cout<<"7. Exit\n"<<endl;
}

//edit module menu (customer module)
void display_edit_menu()
{
	cout<<"1.Name"<<endl;
	cout<<"2.Address"<<endl;
	cout<<"3.Plot No"<<endl;
	cout<<"4.Contact No"<<endl;
	cout<<"5.Monthly Payment Amount"<<endl;
	cout<<"6.Balance" <<endl;
	cout<<"7.Exit"<<endl;
}

//display error message
void display_error(string text)
{
	cout<<"Oops!!Somethings went wrong at the "<<text<<endl;
	exit(-1);
}
//invalid message
void display_invalid(string text)
{
	cout<<"Invalid "<<text<<", Please try again!!"<<endl<<endl;
}

//display string with format
void display_setw(string promptText)
{
	cout<<left<<setw(SETW_SIZE)<<promptText;
}

//success message
void display_success(string promptText)
{
	cout<<endl<<promptText<<" successfully."<<endl<<endl;
}

//format of display title
void display_title(string title)
{
	cout<<"<<"<<title<<">>"<<endl;
	cout<<"-------------------------------------------"<<endl;
}

//main menu
void display_main_menu()
{
	display_title("Resident Management System");
	cout<<"1) Customer Management"<<endl;
	cout<<"2) Payment"<<endl;
	cout<<"3) Exit"<<endl<<endl;
}

/*
-----------------------------------get input functions------------------------------------------------------------------------------
*/
//get account type data input
void get_account_input(int* account,string promptText,char header,int setw_size)
{
	int acc=0,repeat=0;
	do{
	cout<<setw(setw_size)<<promptText<<": "<<header;
	cin>>acc;
		do{
			if(!cin)
			{
				cin.clear();
				cin.ignore();
				cin>>acc;
			}
		}while(!cin);
		
		if(acc<=0 || acc>=100000)
		{
			display_invalid("account number, account no should contain 1 to 5 digits");
			repeat=1;
		}
		else if(acc>0 && acc<100000)
		{
			cin.ignore(CHAR_ARRAY_SIZE,'\n');
			*account=acc;
			repeat=0;
		}
		else
			display_error("input of customer account number");
	}while(repeat!=0);
}

//get char type input
void get_char_input(char* value,string prompt_text,int setw_size)
{
	char input='\0';
	cout<<left<<setw(setw_size)<<prompt_text;
	cin.get(input);
	
	do{
		if(!cin)
		{
			cin.clear();
			cin.ignore();
			cin.get(input);
		}
	}while(!cin);
	
	*value=input;
	cin.ignore(CHAR_ARRAY_SIZE,'\n');
}

//get character array type input
void get_charArr_input(char* arr,string promptText,int setw_size)
{
	cout<<left<<setw(setw_size)<<promptText<<": ";
	cin.get(arr,CHAR_ARRAY_SIZE);
	cin.ignore(CHAR_ARRAY_SIZE,'\n');
	
	do{
		if(!cin)
		{
			cin.clear();
			cin.ignore();
			cin.get(arr,CHAR_ARRAY_SIZE);
		}
	}while(!cin);
}

//get Date type input
void get_date_input(Date* input,string prompt_text,int setw_size)
{
	string date;
	cout<<setw(setw_size)<<prompt_text<<": ";
	cin>>date;
	istringstream daySS(date.substr(0,2));
	istringstream monthSS(date.substr(3,2));
	istringstream yearSS(date.substr(6,4));
	daySS>>input->d;
	monthSS>>input->m;
	yearSS>>input->y;
}

void get_plot_no_input(int* input,string prompt_text,int setw_size)
{
	int plot=0;
	int repeat=0;
	do{
	cout<<setw(setw_size)<<prompt_text<<": ";
	cin>>plot;

	do{
		if(!cin)
		{
			cin.clear();
			cin.ignore();
			cin>>plot;
		}
	}while(!cin);
	
	if(plot<=0 || plot>=1000)
	{
		display_invalid("plot no, Plot number should only have 3 digit!!");
		repeat=1;
	}
	else if(plot>=1 && plot<=999)
	{
		*input=plot;
		cin.ignore(CHAR_ARRAY_SIZE,'\n');
		repeat=0;
	}
	else
		display_error("get plot number input.");
	}while(repeat!=0);
	
}

//get long double type input
 void get_long_double_input(long double* input,string prompt_text,int setw_size)
{
	double value=0.0;
	int repeat=0;
	
	do{
	cout<<left<<setw(setw_size)<<prompt_text<<": RM ";
	cin>>value;
	cin.ignore(CHAR_ARRAY_SIZE,'\n');

	//limitation to enter is 1 million
	if(value<0 || value>10000000)
	{
		display_invalid("Invalid value!!");
		repeat=1;
	}
	else if(value>=0 && value<=10000000)
	{
		*input=value;
		repeat=0;
	}
	else
		display_error("input of long double value!!");
	}while(repeat==1);
}

//get double type input
 void get_double_input(double* input,string prompt_text,int setw_size)
{
	double value=0.0;
	int repeat=0;
	
	do{
	cout<<left<<setw(setw_size)<<prompt_text<<": RM ";
	cin>>value;
	cin.ignore(CHAR_ARRAY_SIZE,'\n');

	//limitation to enter is 1 million
	if(value<-100000 || value>10000000)
	{
		display_invalid("Invalid value!!");
		repeat=1;
	}
	else if(value>=-100000 && value<=10000000)
	{
		*input=value;
		repeat=0;
	}
	else
		display_error("input of double value!!");
	}while(repeat==1);
}

//get payment type input
void get_payment_input(vector<Customer>& customers,Payment* input,bool* search,int* result,int setw_size)
{
	bool validation='\0';
	int repeat_valid=0,repeat_date=0,repeat_cus=0,repeat_amount=0;
	//reference number input
	get_payref_input(&input->ref_no,"Payment Ref No",'P',setw_size);
	
	//date input and validation
	do{
		get_date_input(&input->date,"Payment Date",setw_size);
		validation=date_validation(input);
		if(validation==false)
			repeat_valid=1;
		else if(validation==true)
			repeat_valid=0;
		else
			display_error("validation of the date!!");
	}while(repeat_valid==1);
	
	//customer no input and validation
	do{
		get_account_input(&input->cus_no,"Customer No",'C',setw_size);
		validation=customer_validation(customers,input,result);
		if(validation==false)
		{
			repeat_valid=1;
			*search=false;
			cout<<"Account No is not exist in Database, Please re-enter!"<<endl;
		}
		else if(validation==true)
		{
			repeat_valid=0;
			*search=true;
		}	
		else
		{
			display_error("validation of the customer!!");
		}
	}while(repeat_valid==1);
	
	//payment amount input and validation
	do{
		get_long_double_input(&input->payment_amount,"Payment Amount",setw_size);
		validation=pay_amount_validation(customers,input,*result);
		if(validation==false)
			repeat_valid=1;
		else if(validation==true)
			repeat_valid=0;
		else
		    display_error("validation of the payment amount!!");
	}while(repeat_valid==1);
	
	//payment_type input and validation
	do{
		get_char_input(&input->payment_type,"Payment Type \n[1-Cash\n 2-Cheque\n 3-Online]\nYour option : ",setw_size);
		if(input->payment_type=='1' || input->payment_type=='2' || input->payment_type=='3')
			repeat_valid=0;
		else
		{
			display_invalid("Invalid payment type!!");
			repeat_valid=1;
		}
	}while(repeat_valid==1);
	
	//convert payment type to payment method
	payType_to_payMethod(&input->payment_type,&input->payment_method);
	
}

void get_payref_input(int* reference,string promptText,char header,int setw_size)
{
	int acc=0,repeat=0;
	
	do{
	cout<<setw(setw_size)<<promptText<<": "<<header;
	cin>>acc;

		do{
			if(!cin)
			{
				cin.clear();
				cin.ignore();
				cin>>acc;
			}
		}while(!cin);
		
		if(acc<=0 || acc>=1000000)
		{
			display_invalid("payment ref no, ref no should contain 1 to 6 digits");
			repeat=1;
		}
		else if(acc>0 && acc<1000000)
		{
			cin.ignore(CHAR_ARRAY_SIZE,'\n');
			*reference=acc;
			repeat=0;
		}
		else
			display_error("input of payment refenrence number");
	}while(repeat!=0);	
}

void get_phoneArr_input(char* arr,string promptText,int setw_size)
{
	cout<<left<<setw(setw_size)<<promptText<<": ";
	cin.getline(arr,CHAR_ARRAY_SIZE);
}

/*
-----------------------------------enter modules functions------------------------------------------------------------------------------
*/
//add customer module
void enter_addcust_module(vector<Customer>& customers)
{
	add_customer(customers);
	int size=customers.size();
	sort(customers.begin(),customers.end(),cust);
	save_customer(customers);
	cout<<"The customer is successfully added into the database!!"<<endl;
	stop();
}

// customer modules
void enter_customer_module(vector<Customer>& customers)
{
	char option='\0';
	int repeat_customer=1;
	do{
		display_customer_menu();
		get_char_input(&option,"Enter Option : ",0);
		
		clear_window();
		
		switch(option)
		{
			case '1':
				enter_addcust_module(customers);
				repeat_customer=1;
				break;
			case '2':
				enter_search_module(customers);
				repeat_customer=1;
				break;
			case '3':
				enter_delete_module(customers);
				repeat_customer=1;
				break;		
			case '4':
				enter_edit_module(customers);
				repeat_customer=1;
				break;		
			case '5':
				enter_list_module(customers);					
				repeat_customer=1;
				break;	
			case '6':
				enter_outstand_module(customers);
				repeat_customer=1;						
				break;
			case '*':
				enter_deduction_module(customers);
				repeat_customer=1;
				break;
			case '7':
				repeat_customer=0;
				break;
			default:
				display_invalid("choice");
				repeat_customer=1;
		}
	}while(repeat_customer==1);
}

//reduce all customers balance with monthly payment
void enter_deduction_module(vector<Customer>& customers)
{
	char option='\0';
	int repeat=0;
	int size=customers.size();
	
	display_title("Deduction of Monthly Payment");
	
	if(size==0)
	{
		cout<<"No record found in the database!!"<<endl;
	}
	else if(size>0)
	{
		do{
			cout<<"Are you sure you want to deduct all the customers' balance with monthly payment?"<<endl;
			cout<<"1. Yes\n2. No"<<endl;
			get_char_input(&option,"Enter your option:",SETW_PAYMENT_SIZE);
			switch(option)
			{
				case '1':
					for(int i=0;i<size;i++)
						customers[i].balance-=customers[i].monthly_payment;
					save_customer(customers);
					cout<<"The changes had been saved in the database."<<endl;
					repeat=0;
					break;
				case '2':
					cout<<"The records had not been changed."<<endl;
					repeat=0;
					break;
				default:
					display_invalid("option");
					repeat=1;
			}
		}while(repeat!=0);
	}
	stop();
	clear_window();
	
}

//delete customer module
void enter_delete_module(vector<Customer>& customers)
{
	int record=0,repeat=0;
	bool search='\0';
	int size=customers.size();
	char input='\0';
	
	display_title("Delete Record");
	if(size==0){
		cout<<"No customer found in the database!!"<<endl;
		stop();
		return;
	}
	
	size=customers.size();
	
	search=search_customer(customers, &record);
		
	if(search==false)
	{
		cout<<"Customer Not Found!!"<<endl;
	}
	else if(search==true)
	{
		cout<<"-----------------------------------------"<<endl;
		display_customer(customers,record);
		cout<<"-----------------------------------------"<<endl;
		do{
			cout<<"Are you sure you want to delete the record?"<<endl;
			cout<<endl<<"1.Yes\n2.No\n"<<endl;
			get_char_input(&input,"Your option : ",0);
			cout<<endl;
			switch(input)
			{
				case '1':
					customers.erase(customers.begin()+record);
					save_customer(customers);
					display_success("The record had been removed from the database");
					repeat=0;
					break;
				case '2':
					cout<<"The record will not be deleted."<<endl;
					repeat=0;
					break;
				default:
					display_invalid("Invalid option!!");
					repeat=1;
			}
		}while(repeat!=0);
	}
	else
	    display_error("delete record module!!") ;
	
	stop();
}

//edit customer information module
void enter_edit_module(vector<Customer>& customers)
{
	int record		=0;
	bool search		='\0';
	int size		=customers.size();
	
	display_title("Edit Record");
	
	if(size==0){
		cout<<"No customer found in the database!!"<<endl;
		stop();
		return;
	}
	
	search=search_customer(customers, &record);
	cout<<endl;
	
	if(search==false)
	{
		cout<<"Customer Not Found!!"<<endl;
		stop();
		clear_window();
	}
	else if(search==true)
	{
		display_customer(customers,record);
		edit_customer(customers,record);
	}
	else
		display_error("edit record module!!") ;
}

//list customers module
void enter_list_module(vector<Customer>& customers)
{
	display_title("List Records");
	int size=customers.size();
	
	if(size==0)
		cout<<"No record found in the database!!"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"Record "<<i+1<<endl;
		cout<<"---------------"<<endl;
		display_customer(customers,i);
	}
	
	stop();
}

//the main program
void enter_main_program()
{
	vector<Customer> customers;
	int whole_repeat=1;
	
	load_customer(customers);

	char option='\0';
	do{
		int size=customers.size();
		clear_window();
		display_main_menu();
		get_char_input(&option,"Enter Option : ",0);
		switch(option)
		{
		case '1':
			clear_window();
			enter_customer_module(customers);
			clear_window();
			break;
		case '2':
			clear_window();
			enter_payment_module(customers);
			clear_window();
			break;
		case '3':
			whole_repeat=0;
			cout<<endl<<"The program will be closed soon. Please come again!!"<<endl;
			break;
		default:
			display_invalid("choice");
		}
	}while(whole_repeat==1);
} 

//list outstanding customer module
void enter_outstand_module(vector<Customer>& customers)
{
	int counter=0;
	display_title("Outstanding Records");
	int size=customers.size();
	
	for(int i=0;i<size;i++)
	{
		if(customers[i].balance<0)
		{
			counter++;
			cout<<"Record "<<counter<<endl;
			cout<<"---------------"<<endl;
			display_customer(customers,i);
		}
	}
	if(counter==0)
	{
		cout<<"No outstanding record found in database!!"<<endl<<endl;
	}
	
	stop();
}

//payment module
void enter_payment_module(vector<Customer>& customers)
{
	bool search='\0';
	double old_balance	=0.0;
	double new_balance	=0.0;
	int result			=0;
	int repeat_payment	=1;
	int size=customers.size();
	Payment input;
	
	//display menu and get input
	display_title("Payment module");
	
	if(size==0){
		cout<<"No customer found in the database!!"<<endl;
		cout<<"Payment unable to process!!"<<endl;
		stop();
		return;
	}
	
	char save_record='\0';
	get_payment_input(customers,&input,&search,&result,SETW_PAYMENT_SIZE);
	
	if (search==true)
	{
		//change customer balance
		old_balance=customers[result].balance;
		new_balance=old_balance+input.payment_amount;
		customers[result].balance=new_balance;
		
		//save record
		do
		{
			get_char_input(&save_record,"Save Record [Y/N] : ",0);
			save_record=toupper(save_record);
			switch (save_record)
			{
				case 'Y':
					{
						save_payment(input,customers,result,old_balance,new_balance);	
						repeat_payment=0; 
						break;
					}
					
				case 'N':
					cout<<endl<<"The record will not be saved."<<endl<<endl;
					repeat_payment=0;
					break;
					
				default:
					display_invalid("choice");
					repeat_payment=1;
			}
		}while(repeat_payment==1);
		
		//print payment info for review
		if(new_balance!=0)
		{
			//calculate additional payment amount and next month payment amount
			double additional= input.payment_amount;
			double next_payment=customers[result].monthly_payment;
			
			if(next_payment<=0)
				next_payment=0;
				
			cout<<"Payment Amount: RM"<<input.payment_amount<<endl;
			if(customers[result].balance>0)
			{
			cout<<"\nRM"<<additional<<" was credited to customer account balance."<<endl;
			cout<<"Current monthly payment revised to RM "<<next_payment<<endl;
			cout<<"\nCurrent Account Balance: RM"<<customers[result].balance<<endl;
			}
		}
		
		//change customer last payment date
		customers[result].last_payment.d=input.date.d;
		customers[result].last_payment.m=input.date.m;
		customers[result].last_payment.y=input.date.y;
		
		save_customer(customers);
		stop();
	}	
}

//search customer module
void enter_search_module(vector<Customer>& customers)
{
	int record=0;
	bool search='\0';
	int size=customers.size();
	
	display_title("Search Record");
	
	if(size==0){
		cout<<"No customer found in the database!!"<<endl;
		stop();
		return;
	}
	
	search=search_customer(customers, &record);
	cout<<endl;
	
	if(search==false)
	{
		cout<<"Customer Not Found!!"<<endl;
	}
	else if(search==true)
	{
		display_customer(customers,record);
	}
	else
	    display_error("search record module!!") ;
	stop();
}

/*
-----------------------------------functional functions------------------------------------------------------------------------------
*/
//search customer with customer account no
bool search_customer(vector<Customer>& customers,int* result)
{
	int search=0;
	int size=customers.size();	
	get_account_input(&search,"Enter Customer Account No  ",'C',SETW_SIZE);
							
	for(int i=0;i<customers.size();i++)
	{
		if(customers[i].acc_no==search)
		{
		*result=i;
		return true;
		break;
		}
		if(*result>=size)
		{
			display_invalid("Customer Account Not Found!!");
			return false;
		}
	}
}

//add new customer and request input
void add_customer(vector<Customer>& customers)
{
	Customer c1;
	string acc;
	bool valid='\0';
	int loop=0;
	display_title("New Record");
	do{
		get_account_input(&c1.acc_no,"1.Account No",'C',SETW_SIZE);	
		valid=account_no_validation(customers,c1.acc_no);
		if(valid==true)
			loop=0;
		else if(valid==false)
			loop=1;
		else
			display_error("customer account no validation");
	}while(loop!=0);
	
	do{
		get_charArr_input(c1.name,"2.Name",SETW_SIZE);
		valid=name_validation(customers,c1.name);
		if(valid==true)
			loop=0;
		else if(valid==false)
			loop=1;
		else
			display_error("customer account no validation");
	}while(loop!=0);
	
	get_charArr_input(c1.address,"3.Address",SETW_SIZE);
	
	do{
		get_plot_no_input(&c1.plot_no,"4.Plot No",SETW_SIZE);
		valid=plot_no_validation(customers,c1.plot_no);
		if(valid==true)
			loop=0;
		else if(valid==false)
			loop=1;
		else
			display_error("customer account no validation");
	}while(loop!=0);
	
	get_phoneArr_input(c1.contact_no,"5.Contact No",SETW_SIZE);
	get_long_double_input(&c1.monthly_payment,"6.Monthly Payment : ",SETW_SIZE);
				
	c1.last_payment.d=0;
	c1.last_payment.m=0;
	c1.last_payment.y=0;
	c1.balance=0;
		
	customers.push_back(c1);
}

void clear_window()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cout<<"\n"<<endl;
		 
}

//edit customer information
void edit_customer(vector<Customer>& customers,int result)
{
	int repeat_option	=1;
	int size=sizeof(customers[result].contact_no);
	char option			='\0';
	
	do
	{
		display_title("Edit Record");
		display_edit_menu();
		get_char_input(&option,"Enter your option : ",0);
		cout<<endl;
		
		switch(option)
		{
			Customer input;
			
			case '1':		
				get_charArr_input(input.name,"New Customer Name",SETW_SIZE);
				for(int i=0;i<CHAR_ARRAY_SIZE;i++)
				{
					customers[result].name[i]=input.name[i];
				}
				display_success("The customer information changed");
				break;
								
			case '2':
				get_charArr_input(input.address,"New Customer Address",SETW_SIZE);
				for(int i=0;i<CHAR_ARRAY_SIZE;i++)
				{
					customers[result].address[i]=input.address[i];
				}
				display_success("The customer information changed");
				break;
								
			case '3':
				get_plot_no_input(&input.plot_no,"New Customer Plot No",SETW_SIZE);
				customers[result].plot_no=input.plot_no;
				display_success("The customer information changed");
				break;
				
			case '4':
				get_phoneArr_input(input.contact_no,"New Customer Contact No",SETW_SIZE);
				for(int i=0;i<size;i++)
					customers[result].contact_no[i]=input.contact_no[i];
				display_success("The customer information changed");
				break;
				
			case '5':
				get_long_double_input(&input.monthly_payment,"New Monthly Payment Amount",SETW_SIZE);
				customers[result].monthly_payment=input.monthly_payment;
				display_success("The customer information changed");
				break;
			
			case '6':
				get_double_input(&input.balance,"New Customer Balance",SETW_SIZE);
				customers[result].balance=input.balance;
				display_success("The customer information changed");
				break;
				
			case '7':
				repeat_option=0;
				break;
			default:
				display_invalid("option");
		}
	}while(repeat_option==1);
	stop();
}

//loading customer from database
void load_customer(vector<Customer>& customers)
{
	fstream file;
	Customer customer;
	
	file.open("customer.dat", ios::in | ios::binary);
	
	if(file.fail())
	{
		cout<<"Fail to open the file for loading data!!"<<endl;
		exit(-1);
	}
	
	file.read(reinterpret_cast<char*>(&customer),sizeof(customer));
	
	while(!file.eof())
	{
		customers.push_back(customer);
		
		file.read(reinterpret_cast<char*>(&customer),sizeof(customer));
	}
	
	file.close();
}

//convert payment type input to payment method
void payType_to_payMethod(char* type,string* method)
{
	switch(*type)
	{
		case '1':
			*method="Cash";
			break;
		case '2':
			*method="Cheque";
			break;
		case '3':
			*method="Online Banking";
			break;
		default:
			*method="Error occur!!";
	}
}

//save the customer data into database
void save_customer(vector<Customer>& customers)
{
	fstream file;
	Customer customer;
	int size=customers.size();
	
	if(file.fail())
	{
		cout<<"Fail to open the file for writing record!!"<<endl;
		exit(-1);
	}
	
	file.open("customer.dat", ios::out | ios::binary);
	
	
		for (int i=0; i<size; i++)
		{
			//extract student object from array
			Customer customer =customers[i];
			
			//write the record to the file
			file.write(reinterpret_cast<char*>(&customer), sizeof(customer));
		}
}

//output the payment record file
void save_payment(Payment input,vector<Customer>& customers,int result,double old_balance,double new_balance)
{
	ofstream file;
	file.open("Payment.txt");
	file<<left;
	
	file<<setw(SETW_PAYMENT_SIZE)<<"Referencing No : "<<"P"<<input.ref_no<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Payment Date : ";
	file<<input.date.d<<"-"<<input.date.m<<"-"<<input.date.y<<endl;
	file<<"-------------------------------------------------------------------------"<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer No : "<<"C";
	file<<input.cus_no<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Name : "<<customers[result].name<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Address : "<<customers[result].address<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Plot No : "<<customers[result].plot_no<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Contact No : "<<customers[result].contact_no<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Monthly Payment Amount : "<<"RM"<<customers[result].monthly_payment<<endl;
	file<<"-------------------------------------------------------------------------"<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Payment Method : "<<input.payment_method<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Payment Amount : "<<"RM"<<input.payment_amount<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Balance(old) : "<<"RM"<<old_balance<<endl;
	file<<setw(SETW_PAYMENT_SIZE)<<"Customer Balance(new) : "<<"RM"<<new_balance<<endl;
	
	cout<<endl<<"The record had been saved in the payment.txt file"<<endl<<endl;
}

void stop()
{
	char key;
	cout<<"\nPress any key to continue..."<<endl;
	cin.get(key);
	if(key!='\0')
		clear_window();
}

/*
--------------------------------------------------------------------validation functions-----------------------------------------------------------------------------
*/
bool account_no_validation(vector<Customer>& customers,int acc_no)
{
	int result=0;
	int i=0;
	int size=customers.size();
	
	if(size>0)
	{
		//search the customer
		while(i<=size)
		{
			if(result>=size)
			{
				result=i;
				return true;
			}
			else if(acc_no==customers[i].acc_no)
			{
				display_invalid("Account No, Already exist or wrong input!");
				return false;
			}
			else if (!customers[i].acc_no){
				break;
			}
			i++;
		}
	}
	else if(size==0)
		return  true;
	else
		display_error("customer account validation");
}

bool customer_validation(vector<Customer>& customers,Payment* input,int* result)
{
	int i=0;
	int size=customers.size();
	//search the customer
	
	while(i<=size)
	{
		if(input->cus_no==customers[i].acc_no)
		{
			*result=i;
			return true;
		}
		else if(*result>=size)
		{
			display_invalid("Customer Account Not Found!!");
			return false;
		}
		i++;
	}	
}

bool date_validation(Payment* input)
{	
	//this program only can used from 2019 to 2100 year
	if(input->date.y<2019 || input->date.y>2100)
	{
		display_invalid("Invalid Date!!");
		return false;
	}
	
	switch(input->date.m)
	{
		//when the month has 31 day
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(input->date.d<=0 || input->date.d>=32)
			{
				display_invalid("Invalid Date!!");
				return false;
			}
			else if(input->date.d>=1 && input->date.d<=31)
				return true;
			else
		    	display_error("validation of the date!!");
			break;
			
		//when the month has 30 day
		case 4:
		case 6:
		case 9:
		case 11:
			if(input->date.d<=0 || input->date.d>=31)
			{
				display_invalid("Invalid Date!!");
				return false;
			}
			else if(input->date.d>=1 && input->date.d<=30)
				return true;
			else
			    display_error("validation of the date!!");
			break;
		
		//calculate the day in february since year%2==0 has 29 days else 28 days
		case 2:
			if(input->date.y%4==0)
			{
				if(input->date.d<=0 || input->date.d>=30)
				{
					display_invalid("Invalid Date!!");
					return false;
				}
				else if(input->date.d>=1 && input->date.d<=29)
					return true;
				else
			    	display_error("validation of the date!!");
			}
			else if(input->date.y%4!=0)
			{
				if(input->date.d<1 || input->date.d>28)
				{
					display_invalid("Invalid Date!!");
					return false;
				}
				else if(input->date.d>=1 && input->date.d<=28)
					return true;
				else
			    	display_error("validation of the date!!");
			}
			else
		        display_error("validation of the date!!");
			break;
		default:
			display_invalid("Invalid Date!!");
			return false;
	}
}

bool name_validation(vector<Customer>& customers,char* name)
{
	bool result='\0',alpha='\0';
	int i=0;
	int size=customers.size();
	
	if(size>0)
	{
		//search the customer
		while(i<=size)
		{
			result=strcmp(customers[i].name,name);
			if(i>=size)
				return true;
			
			else if(result==0)
			{
				display_invalid("Name, Already exist or wrong input!");
				return false;
			}
			
			else if (!customers[i].acc_no){
				break;
			}
			i++;
		}	
	}
	else if(size==0)
		return  true;
	else
		display_error("customer name validation");
}

bool pay_amount_validation(vector<Customer>& customers,Payment* input,int result)
{
	double minimum=0.0;
	double dif=0.0;
	
	cout<<setprecision(2)<<showpoint<<fixed;
	
	minimum=customers[result].monthly_payment-customers[result].balance;
	if(input->payment_amount<minimum)
	{
		cout<<"The payment amount did not reach the minimum amount: RM "<<minimum<<endl;
		return false;
	}
	else if(input->payment_amount>=minimum)
		return true;
	else
		display_error("validation of the payment amount!!");
}

bool plot_no_validation(vector<Customer>& customers,int plot)
{
	int result=0;
	int i=0;
	int size=customers.size();
	if(size>0)
	{
		//search the customer
		while(i<=size)
		{
			if(result>=size)
			{
				result=i;
				return true;
			}
			if(plot==customers[i].plot_no)
			{
				display_invalid("Plot No, Already exist or wrong input!");
				return false;
			}
			if (!customers[i].acc_no){
				break;
			}
			i++;
		}
	}
	else if(size==0)
		return  true;
	else
		display_error("customer plot number validation");
}
