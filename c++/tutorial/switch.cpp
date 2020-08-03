// This program illustrates the use of the Switch statement.

// PLACE YOUR NAME HERE

#include <iostream>
//#include <cctype>
using namespace std;


/*
int main()
{
	char grade;

	cout << "What grade did you earn in Programming I ?" << endl;
	cin >> grade;
	
//switch(grade)
//{
//	case 'A':
//	case 'a':
//	case 'B':
//	case 'b':
//	case 'C':
//	case 'c':
//	case 'D':
//	case 'd':
//		cout<<"You passed"<<endl;
//		break;
//}
	
	
//convert grade to upper case	
//grade = toupper(grade); //from cctype	
	
	
	
	
	
	
	switch( grade )                // This is where the switch statement begins
    {
		case 'A':
		case 'a':  
			cout<< "YOU PASSED!"<<endl;
			cout << "an A - excellent work !" << endl;
			break;
		case 'B':
		case 'b':  
			cout<< "YOU PASSED!"<<endl;
			cout << "you got a B - good job" << endl;
			break;
		case 'C':  
		case 'c':
			cout<< "YOU PASSED!"<<endl;
			cout << "earning a C is satisfactory" << endl;
			break;
		case 'D': 
		case 'd':
			cout<< "YOU PASSED!"<<endl;
			cout << "while  D is passing, there is a problem" << endl;
		   	break;
       	case 'F':
		case 'f':  
			cout << "you failed - better luck next time" << endl;
			break;
        default:   
			cout << "You did not enter an A, B, C, D, or F" << endl;
			break;
	}

    return 0;	
}
*/


int main()
{
	char grade;

	cout << "What grade did you earn in Programming I ?" << endl;
	cin >> grade;

	if( grade=='A' || grade=='a' )                // This is where the switch statement begins
    {
		cout<< "YOU PASSED!"<<endl;
		cout << "an A - excellent work !" << endl;
	}
	
	else if	(grade=='B' || grade=='b') 
	{
		cout<< "YOU PASSED!"<<endl;
		cout << "you got a B - good job" << endl;
	}
		
	else if (grade =='C' || grade=='c') 
	{ 
		cout<< "YOU PASSED!"<<endl;
		cout << "earning a C is satisfactory" << endl;
	}
	
	else if (grade =='D' || grade =='d')
	{
		cout<< "YOU PASSED!"<<endl;
		cout << "while  D is passing, there is a problem" << endl;
	}
	
    else if (grade=='F' || grade=='f')  
		cout << "you failed - better luck next time" << endl;
			
    else 
		cout << "You did not enter an A, B, C, D, or F" << endl;

    return 0;	
}
