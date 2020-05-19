#include<iostream>
#include "Hello.h"
using namespace std;

class MyClass{
	private:
		string name;
	public:
		MyClass(string x){
			setName(x);
		}
		void setName(string input){
			name=input;
		}
		string getName(){
			return name;
		}
};

int main()
{
	Hello object;
	return 0;
}
