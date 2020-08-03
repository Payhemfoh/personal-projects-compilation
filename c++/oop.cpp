#include<iostream>
#include<string>
using namespace std;

//class
class People{
	//cannot be access outside the class except friend function
	private:
		string name;
		int age;
	//can be access outside the class
	public:
		//constructor
		People(string x, int y)
		//member initializer
		:name(x),age(y)
		{
			cout<<name<<endl<<age<<endl;
		}
		//virtual for polymorfisom
		//abstract is pure virtual class
		virtual void printInfo()
		{
			cout<<name<<endl<<age<<endl;
		}
		void printmessage(){
			cout<<"age="<<age<<endl;
			cout<<"this->age="<<this->age<<endl;
			cout<<"(*this).age="<<(*this).age<<endl;
		}
		
		/*
		//operator overloading
		People operator +(People object){
			People new_object;
			new_object.name="Bob";
			new_object.age=num+object.age;
			return (new_object);
		}
		*/
		//deconstructor
		~People(){
			cout<<"The object will be destroy"<<endl;
		}
		
	//function prototype for friend function
	friend void changeAge(People&);
};  



//operator overloading
/*
	<return data_type>  <functionname--operator> <operator>(parameter)
	
People People::operator +(People object){
	People new_object;
	new_object.age=num+object.age;
	return (new_object);
}
*/

//Inheritance
//public and private will copy to this class from base class w
//without constructor but the constructor of base class still work since the
//people class will be run first before student class
class Student: public People
{
	private:
		string name;
		int age;
	public:
		//constructor
		Student(string x, int y)
		//member initializer
		:name(x),age(y)
		{
			cout<<name<<endl<<age<<endl;
		}
};

//friend function
void changeAge(People& object){
	object.age=27;
	cout<<"The age changed to "<<object.age<<endl;
}

int main()
{
	People Winsom("Winsom",17);
	Winsom.printInfo();
	
	changeAge(Winsom);
	Winsom.printmessage();
	
	//inheritance
	Student Mary("Mary",14);
	Mary.printInfo();
	return 0;
}


//function template
template <class FIRST,class SECOND>
FIRST adding(SECOND a,SECOND b){
	return a+b;
}

//class template
template <class T>
class Hello{
	private:
		T first,second;
	public:
		Hello(T a,T b)
		:first(a),second(b)
		{
		}
		T bigger();
};

template <>
class Hello<char>{
	private:
		char first,second;
	public:
		Hello(char a,char b)
		:first(a),second(b)
		{
			cout<<first<<endl<<second<<endl;
		}
};
template <class T>
Hello::bigger()
{
	return (first>second?first:second);
}

/* at main
int main()
{
	Hello <int> object(10,20);
	cout<<object.bigger();
}
*/

//exception handling
try{
	int momAge=30;
	int sonAge=40;
	
	if(sonAge>momAge){
		throw 1;
	}
}
/*
//... can catch any type of throw message
catch(...){

}
*/

catch(int x){
	cout<<"Son cannot be elder than mother, error number : "<<x<<endl;
	
}
