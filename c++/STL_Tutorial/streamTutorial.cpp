#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <complex>
using namespace std;

/*
---stream class
	-serial IO interface to external devices (file,stdin/stdout,network,etc)

*/

//endl
/*
ostream& endl(ostream& sm) {	//manipulator - function to manipulate stream
	sm.put('\n');
	sm.flush();
	return sm;
}

ostream& ostream::operator bool(ostream& (*func)(ostream&)) {
	return (*func)(*this);
}
*/


int main() {
	cout << "Hello" << endl;
	/*
		cout: global object of ostream (typedef basic_ostream<char> ostream)
		<<:	ostream& ostream::operator<< (string v);
		manipulators:

		endl: '\n' + flush
		ends: //'\0'
		flush	//flush the screen
		cin>>ws;	read and discard white spaces
		cout<<setw(8)	//set weight
			<<left	//set alignment to left
			<<setfill('_')	//fill empty space with underscore
			<<endl;
		
		cout<<hex<<showbase<<14;	/0xe
	*/
	string s("Hello");
	s[3] = 't';
	//cout[3] = 't';	//error

	{
		ofstream of("MyLog.txt");	//create a file for write if not exist
		of << "Experience is the mother of wisdom" << endl;
		of << 234 << endl << 2.3 << endl;
		of << bitset<8>(14) << endl;
		of << complex<int>(2, 3) << endl;
	}//RAII technique automatic close the file and destroy stream when out of scope

	/*
		IO operation:
		-formatting data <---> communicating data with external devices
		-software engineer principle: low coupling -> reusability
	*/

	{
		ofstream of("MyLog.txt",ofstream::app);	//move pointer to end of file
		of << "Honesty is the best policy" << endl;
	}

	{
		ofstream of("MyLog.txt",ofstream::in|ofstream::out);
		of.seekp(10, ios::beg);	//move output pointer 10 unit from begin
		of << "12345";	//overwrite 5 char
		of.seekp(-5, ios::end);	//move output pointer 5 unit from end
		of << "Noting ventured, nothing gained." << endl;
		of.seekp(-5, ios::cur);	//move output pointer 5 unit from current position
	}

	ifstream inf("MyLog.txt");
	int i;
	inf >> i;
	//Error status: goodbit,badbit,failbit,eofbit
	inf.good();	//everythings are ok
	inf.bad();	//non-recoverable error
	inf.fail();	//failed stream operation
	inf.eof();	//end of file

	inf.clear();	//clear all error status clear(ios::goodbit)
	inf.clear(ios::badbit);	//set new value to error flag

	inf.rdstate();	//read current status flag
	inf.clear(inf.rdstate() & ~ios::failbit);	//calr only failbit

	if (inf)	//similar to if(!inf.fail())
		cout << "Read successfully" << endl;
	
	if (inf >> i)
		cout << "Read successfully" << endl;

	//Handle errors with exceptions
	inf.exceptions(ios::badbit | ios::failbit);	//set exception mask
	//if the bits set, exception of ios::failure will be thrown
	inf.exceptions(ios::goodbit);	//no exception


	//formatting
	cout << 34 << endl;	//34
	cout.setf(ios::oct, ios::basefield);
	cout << 34 << endl;	//42
	cout.setf(ios::showbase);
	cout << 34 << endl;	//042
	cout.setf(ios::hex, ios::basefield);
	cout << 34 << endl;	//0x22

	cout.unsetf(ios::showbase);
	cout << 34 << endl;	//22

	cout.setf(ios::dec, ios::basefield);
	
	cout.width(10);
	cout << 26 << endl;	//        26
	cout.setf(ios::left, ios::adjustfield);//26

	//floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout << 340.1 << endl;	//3.401000e+002
	cout.setf(ios::fixed, ios::floatfield);
	cout << 340.1 << endl;	//340.100000
	cout.precision(3);
	cout << 340.1 << endl;

	int i;
	cin.setf(ios::hex, ios::basefield);
	cin >> i;	//enter 12, i==18

	ios::fmtflags f = cout.flags();
	cout.flags(ios::oct | ios::showbase);


	/*
	--------------member function for unformatted IO
	*/
	//input
	ifstream inf("MyLog.txt");
	char buf[80];
	inf.get(buf, 80);	//read up to 80 chars and save into buf
	inf.getline(buf, 80);//read up to 80 chars or until '\n'
	inf.read(buf, 20);	//read 20 chars
	inf.ignore(3);
	inf.peek();
	inf.unget();	//return a char back to stream (inf.putback(''))
	inf.get();
	inf.gcount();	//return number of chars being read by last unformatted data

	//output
	ofstream of("MyLog.txt");
	of.put('c');
	of.write(buf, 6);	//write first 6 chars of buf
	of.flush();

	/*
	---------stream buffer
		-communicate data to external devices
	*/

	cout << 34 << endl;
	streambuf* pbuf = cout.rdbuf();

	ostream myCout(pbuf);
	myCout << 34;	//34 to stdout

	myCout.setf(ios::showpos);
	myCout.width(20);
	myCout << 12 << endl;	//                 +12
	cout << 12 << endl;	//12

	ofstream of("MyLog.txt");
	streambuf* origBuf = cout.rdbuf();
	cout.rdbuf(of.rdbuf());
	cout << "Hello" << endl;	//output Hello to file

	//redirecting
	cout.rdbuf(origBuf);

	cout << "Goodbye" << endl;	//stdout:Goodbye

	//Stream buffer iterator
	istreambuf_iterator<char> in(cin);
	ostreambuf_iterator<char> o(cout);
	while (*in != 'x') {
		*o = *in;
		++o;
		++i;
	}	//print out the char entered until x is pressed

	//same as above but without criteria
	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
	

	/*
	---------stringstream
		-stream without IO channel
		-read/write string
	*/
	stringstream ss;

	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;
	cout << ss.str() << endl;	//89 Hex: 59 Oct: 131

	int a, b, c;
	string s1;

	ss >> hex >> a;	//formatted input works token by token(space,tab.newline)
	//a=137
	ss >> s1;	//s1="Hex:"
	ss >> dec >> b;	//b=59

	ss.ignore(6);

	ss >> oct >> c;	//c=89

	ostringstream os;	//only deal with output
	istringstream is;	//only deal with input

	return 0;
}

/*
---------create stream-enabled class
*/

class Dog {
public:
	int age;
	string name;
};

ostream& operator<<(ostream& sm, const Dog& d) {
	sm << "My name is " << d.name << " and my age is " << d.age << endl;
	return sm;
}

istream& operator>>(istream& sm, Dog& d) {
	sm >> d.age;
	sm >> d.name;
	return sm;
}

int driver() {
	Dog d{ 2,"Bob" };	//universal initialization
	cout << d;
	cin >> d;
	return 0;
}