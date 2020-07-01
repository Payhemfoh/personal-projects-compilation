#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/*
	string class
*/
int main() {
	//constructors
	string s1("Hello");
	string s2("Hello", 3);	//Hel
	string s3(s1, 2);	//llo
	string s4(s1, 2, 2);	//ll
	string s5(5, 'a');	//aaaaa
	string s6({ 'a','b','c' });//abc
	string s7(s1.begin(), s1.end());	//Hello

	//size
	s1 = "Goodbye";
	s1.size();	s1.length();	//same ==7
	s1.capacity();	//size of storage space currently allocated
	s1.reserve(100);	//allocate 100 char for the string
	s1.reserve(5);	//capacity() == 7
	s1.shrink_to_fit();	//capacity() == size()

	s1.resize(9);	//Goodbye\0\0
	s1.resize(12, 'x');	//Goodbye\0\0xxx
	s1.resize(3);	//Goo

	//access single element
	s1 = "Goodbye";
	s1[2];	//'o'
	s1.at(2);//'o' provide bound check
	s1.at(20);//throw exception of out_of_range
	s1[20];	//undefined behavior

	//like vector, string do not have push_front() and pop_front()
	s1.front();	//'G'
	s1.end();	//'e'
	s1.push_back('z');//Goodbyez
	s1.pop_back();	//Goodbye
	s1.begin(); s1.end();

	//ranged access
	//assign, append, insert, replace
	s2 = "Dragon Land";

	s1.assign(s2);
	s1.assign(s2,2,4);	//agon
	s1.assign("Wisdom");	//Wisdom
	s1.assign("Wisdom",3);	//Wis
	//s1.assign(s2, 3);	//Error
	s1.assign(3,'x');//xxx
	s1.assign({ 'a','b','c' });	//abc

	s1.append(" def");	//abc def
	s1.insert(2,"mountain",4);//abmounc def
	s1.replace(2,5,s2,3,3);	//abgon def

	s1.erase(1,4);	//a def
	s2.substr(2,4);	//agon

	s1 = "abc";
	s1.c_str();	//"abc\0"
	s1.data();	//"abc"

	s1.swap(s2);

	/*
	----------Member function----------
	-copy
	-find
	-compare
	*/
	s1 = "abcdefg";
	char buf[20];
	size_t len = s1.copy(buf, 3);	//buf = abc len=3
	len = s1.copy(buf, 4, 2);	//buf = cdef len = 4

	s1 = "If a job is worth doing, it's worth doing well";
	size_t found = s1.find("doing");	//found = 17
	found = s1.find("doing", 20);	//found==35
	found = s1.find("doing well", 0);	//found ==35
	found = s1.find("doing well", 0,5);	//found ==17

	found = s1.find_first_of("doing");	//found ==6
	found = s1.find_first_of("doing", 10);	//found==12
	found = s1.find_first_of("doing", 10,1);	//found ==17

	found = s1.find_last_of("doing");	//found ==39
	found = s1.find_first_not_of("doing");	//found==0
	found = s1.find_last_not_of("doing");	//found ==44

	s1.compare(s2);	//return +ive if s1>s2, -ive if s1<s2, 0 if equal
	if(s1>s2){}	// if (s1.compare(s2)>0)
	s1.compare(3, 2, s2);

	s3 = s1 + s2;	//concat the strings

	/*
	-----non-member functions-----
	*/
	cout << s1 << endl;
	cin >> s1;
	getline(cin, s1);
	getline(cin, s1, ';');

	//convert number into string
	s1 = to_string(8);
	s1 = to_string(2.3e7);	//23000000
	s1 = to_string(0xa4);	//164
	s1 = to_string(034);	//28

	s1 = "190";
	int i = stoi(s1);	//190

	s1 = "190 monkeys";
	size_t pos;
	i = stoi(s1, &pos);	//i=190 pos=3

	s1 = "a monkey";
	i = stoi(s1, &pos);	//exception of invalid_argument
	i = stoi(s1, &pos, 16);	//i==10

	//stol,stod,stof,stc

	//stringstream
	//lexical_cast()

	/*
	----------algorithm----
	*/

	s1 = "Variety is the spice of life.";
	int num = count(s1.begin(), s1.end(), 'e');
	num = count_if(s1.begin(), s1.end(), [](char c) {return c < 'f' && c >= 'a'; });

	s1 = "Goodness is better than beauty";
	string::iterator itr = search_n(s1.begin(), s1.end(), 2, 's');
	s1.erase(itr, itr + 5);
	s1.insert(itr, 3, 'x');
	s1.replace(itr, itr + 3, 3, 'y');

	is_permutation(s1.begin(), s1.end(), s2.begin());
	replace(s1.begin(), s1.end(), 'e', ' ');
	transform(s1.begin(), s1.end(), s2.begin(),
		[](char c) {
			if (c < 'n')
				return 'a';
			else
				return 'z';
		});

	s1 = "abcdefg";
	rotate(s1.begin(), s1.begin() + 3, s1.end());	//defgabc
	
	string s;
	u16string s16;
	u32string s32;
	wstring ws;
	//to_wstring();
	
	return 0;
}