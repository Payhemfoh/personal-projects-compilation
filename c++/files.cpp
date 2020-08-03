#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//output data into file
	ofstream file;
	
	//open file,if file not found, file will be created automatically
	file.open("tuna.txt");
	//ofstream file("text.txt");
	
	//.is_open()  used to check either file is opened?
	//.fail()  check either file is fail to open
	if(file.is_open())
		cout<<"The file is open"<<endl;
	else
		cout<<"Error in open the file"<<endl;
	
	//better to put inside file.is_open()
	//output data into file
	file<<"Hello World"<<endl;
	
	int idN0;
	string name;
	double money;
	
	//for loop of cin
	while(cin >> idNo >> name >>money){
		file<<idNo<<' '<<name<<' '<<money<<endl;
	}
	
	//close file to free the memory and buffer used in the file
	file.close();
	
	//reading data into file
	ifstream file("tuna.txt");
	//ifstream file;
	//file.open("tuna.txt");
	
	int id;
	string user;
	double balance;
	
	//loop for file-in loop will stop automaticcally when eof
	//can use file.eof() to check either the file is end
	while(file>> id >> user >> balance){
		cout<<id<<' '<<user<<' '<<balance<<endl;
	}
	
	file.close();
	
	return 0;	
}



//string class

string s1("Hello");
string s2,s3;

//both method are same
s2=s1;
s3.assign(s1);

//to display sepecific character
//value inside the bracket is index
//can use addition
cout<< s1.at(3);

//s1.length() to return size
for(int x=0;x<s1.length();x++)
	cout<<s1.at(x);

//substring function
//substr ---- substring   (location/index of first character, size/number of character)
string x1("I like to eat sandwich");
cout<< s1.substr(2,4) <<endl;

//swap function (to swap string)
string one("apples");
string two("oranges");

cout<<one <<two <<endl;
//one is main character and two is target to swap
one.swap(two);

//find function(find substring in string)
//will return location of first found of substring in the string
string h1("Ham is delicious and I am eating");
cout<<s1.find("am") <<endl;

//reverse find, find from the back
cout<<s1.rfind("am")<<endl;

//string erase function
//will erase all the character after the index
string a1("Hello World");
a1.erase(5);

//replace function
//(index of character began to replace, size/ length,  "string")
a1.replace(3,2,"olalala");

//insert function
//(index of character began to insert,"string")
a1.insert(5," i like pizza ");
