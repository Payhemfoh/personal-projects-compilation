//Dynamic pointer
#include<iostream>
using namespace std;

int main()
{
	//good practice to set the pointer to NULL
	int *ptr = NULL;
	
	//*ptr = 5;//no memory run-time error
	ptr=new int;//allocate memory for the pointer
	
	//become widow which is no pointer point to it
	//after new
	*ptr=5;
	
	cout<<*ptr;
	//suggestion to delete before new to prevent lower of performance
	ptr=new int;
	
	*ptr = 10;
	
	cout<<*ptr;
	//destroy pointer memory
	//only delete 10 and 5 still stay at memory location
	delete ptr;
	
	//point to null to prevent pointer point to any way we dont know
	ptr=NULL;
	
	//can check by ptr!=NULL
	return 0;
}
