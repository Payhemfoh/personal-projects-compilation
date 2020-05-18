#include<iostream>
#include<string>
using namespace std;

//abstraction=virtual class
//encapsulation
class People{
	protected:
		string name;
		int age;
		string icNo;
		char bloodType;
	public:
		//polymorphysm
		virtual void print_info(){
			cout<<name<<endl<<age<<endl<<icNo<<endl<<bloodType<<endl;
		}
	
};

//inheritance
class Student : public People
{
	private:
		string studentId;
	public:
		//constructor
		Student(string n,int a,string s,char b)
		{
			name=n;
			age=a;
			studentId=s;
			bloodType=b;
			cout<<"Student registrated!!"<<endl;
		}
		//polymorphyzom
		void print_info(){
			cout<<name<<endl<<age<<endl<<studentId<<endl<<bloodType<<endl;
		}
};

//inheritance
class Employee : public People
{
	private:
		string staffId;
	public:
		//constructor
		Employee(string n,int a,string s,char b)
		{
			name=n;
			age=a;
			staffId=s;
			bloodType=b;
		}
		void print_info(){
			cout<<name<<endl<<age<<endl<<staffId<<endl<<bloodType<<endl;
		}
};
int main(){
	Employee johan("Johan",27,"S54273",'A');
	Student zakrir("Zakrir",13,"P19123",'O');
	johan.print_info();
	zakrir.print_info();
	return 0;
}
