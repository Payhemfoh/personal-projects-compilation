#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	int com=0,u=0;
	
	cout<<"scissor, Rock & Paper Game"<<endl;
	cout<<"1- Scissor, 2- Rock, 3-Paper"<<endl;
	cout<<"Please enter your option:";
	cin>>u;
	
	//step 1:generate computer option
	com=rand() %3 +1;
	
	//step 2:compare the option
	switch(u)
	{
		case 1://user scissor
			switch(com)
			{
				case 1://com scissor
					cout<<"Draw Game!"<<endl;
					break;
					
				case 2://com rock
					cout<<"Computer win!!"<<endl;
					break;
					
				case 3://com paper
					cout<<"User win!!"<<endl;
					break;
					
			}
	
		case 2: //user rock
		switch(com)
			{
				case 1://com scissor
					cout<<"User win!!"<<endl;
					break;
					
				case 2://com rock
					cout<<"Draw Game!"<<endl;
					break;
					
				case 3://com paper
					cout<<"Computer win!!"<<endl;
					break;
			}
	
		case 3: //user paper
			switch(com)
			{
				case 1://com scissor
					cout<<"Computer win!!"<<endl;
					break;
					
				case 2://com rock
					cout<<"User win!!"<<endl;
					break;
					
				case 3://com paper
					cout<<"Draw Game!"<<endl;
					break;
			}
			
		default:
		cout<<"Invalid option. What a foolish!"<<endl;
	}
	return 0;
}
