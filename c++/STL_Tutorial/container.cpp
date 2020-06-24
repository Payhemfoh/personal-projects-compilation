/*
	This file is created for the learning of:
	C++ STL(Standard Template Library)
*/
#include <iostream> //print out
//STL
//algorithm
#include <algorithm>
//functional STL
#include <iterator>
#include <numeric>
#include <functional>	//functor
//containers
#include <vector>	//vector
#include <deque>	//deque
#include <list>		//list
#include <forward_list>	//forward_list
#include <set>		//ordered set, multiset
#include <map>		//ordered map, multimap
#include <unordered_set>	//unordered set,multiset
#include <unordered_map>	//unordered map,multimap
#include <array>	//array
//all the member in stl used std namespace
using namespace std;

/*
	main notes:
	-stl divided into algorithm and containers
	-an iterator is provided to simplified the implementation
	-with iterator, an algorithm can implement to all containers
	-iterator is a class point to the containers' data
	-all containers are required to provide iterator
	
	Algorithms:
	-algorithm dont work on container but iterator

	Containers:
	-three types:
		sequence containers(array and linked list)
		-vector,deque,list,forward list,array

		*Vector:
			-dynamic array grows in one direction(can keep push back but cannot unshift)
			-fast insert and remove at end	:O(1)
			-slow insert and remove at beginning and middle	:O(n)
			-slow search	:O(n)

		*Deque
			-deque similar with vector but can growth both end and beginning
			-fast insert and remove at beginning and end :O(1)
			-slow insert and remove at middle:O(n)
			-slow search :O(n)

		*List
			-double-way link list
			-every element in list has pointer to element in front and behind
			-fast insert and remove at anywhere in list :O(1)
			-slow search :O(n)
			-no random access:[] operator

		*Forward List
			-only forward pointer
			-can only tranverse from front to end but not end to beginning

		*Array
			-same as array but can use common member of containers

		associative containers(binary tree)
		-elements are always sorted
		-by default criteria "<" operator
		-no push_back() and push_front()
		-set,multiset
		-map,multimap


		*Set
			-no duplicate
		*Multiset
			-allow duplicate
		both:-sort according element value
			-value of elements cannot be modified
			-fast search O log n
			-traversing is slow
			-no random access []

		*Map
			-no duplicate
		*Multimap
			-allow duplicate
		both:-elements contain key and value
			-sort according map value
			-key of elements cannot be modified
			-fast search O log n
			-traversing is slow
			-no random access []

		unordered cantainers(hash table)
		-unordered set,multiset
		-unordered map,multimap
		-implemented with hash table(bucket array and entries(linked list))
		-hash function use the value to calculate a value and inserted based on the value
		-fast and effective hash function can reduce time required
			:search/insert O(1)
		-hash collision may degrade the performance -- many element searched in same bucket

		*Unordered set
		*Unordered multiset
			-same as set and multiset


		*Unordered map
		*Unordered multimap
			-same as map and multimap


		no seperate container(Associative Array)
		-map and unordered map
		-can use [] operator



		Container Adapter
		-provide a restricted interface to meet special needs
		-implemented with fundamental container class

		*Stack
			-Last in First out
			-push()
			-pop()
			-top()

		*Queue
			-First in First out
			-push()
			-pop()
			-front()
			-back()

		*Priority queue
			-First item with highest priority
			-push()
			-pop()
			-top()

	-container can also be classified in 2 typesF
		array-based container: vector, deque
			-invalidate pointer
			-every time insert value,need to asign pointer again
		node-based container: others
*/

/*
	why should use stl?
	-code reuse,no need to rewrite again
	-efficiency, fast and less resource consume
	-accurate, less bug
	-simplified code,readable
	-standardized
	-role model of writing library
	-good knowledge of data structures and algorithms
*/
int main(int argc, char** argv)
{
	//create a vector
	vector<int> num;

	//add an element into vector
	num.push_back(8); //num={8}
	num.push_back(2); //num={8,2}
	num.push_back(17); //num={8,2,17}

	//create an iterator of vector class
	vector<int>::iterator itr1;
	//point the iterator to the beginning of vector(num)
	//can also be itr1 = std::begin(num);
	itr1 = num.begin();
	
	//loop through the element in vector by iterator
	for (itr1; itr1 < num.end(); itr1++) {
		//print out the value pointed(iterator is a pointer)
		//can print address by using & but cannot cout directly
		cout << *itr1 << endl;
	}

	itr1 = num.begin();
	vector<int>::iterator itr2 = num.end();
	//sort from start iterator to end iterator
	sort(itr1, itr2);	//num = {2,8,17}


	/*
		-------Common members functions to all containers--------
	*/
	vector<int> temp = { 1,2,3,4 };
	// .empty() check if the container is empty
	if (!temp.empty()) {
		//.size() return size of container
		cout << temp.size() << endl;
	}
	//Copy constructor create a same container as parameter
	vector<int> temp2(temp);

	//.clear() remove all the elements in the container
	temp2.clear();		//temp2.size()==0

	//.swap() change the elements between 2 parameter
	temp.swap(temp2);	//temp.size()==0	temp2.size()==4

	/*
		-------------------Vector-----------------------------
	*/

	vector<int> vec;	//vec.size()==0 ..show the size of the vector
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);	//vec=[4,1,8] vec.size()==3

	//Vector specific operator
	//Vector element can be randomly accessed
	/*
		vec[2] == 8			no check range
		vec.at(2) == 8		throw range_error when out of range
	*/

	/*
		ways to iterate through all elements
		for(int i=0;i<vec.size();i++){
			cout<<vec[i]<<endl
		}
		
		for(vector<int>::iterator i=vec.begin();i<vec.end();i++){
			cout<<*i<<endl;
		}

		//C++ 11
		for(it:vec){
			cout<<it<<endl;
		}
	*/

	//vector is dynamic allocated array in memory
	int* p = &vec[0];	//p[2] == vec.at(2)

	/*
	-----------------Deque--------------------------
	*/
	deque<int> deq = { 4,23,2 };
	deq.push_back(8);	//add the element to the end of deque
	deq.push_front(82); //add the element to the front of deque

	//deque is similar to deque
	//deq[1]==4;

	/*
	-------------------List------------------------
	*/
	list<int> li = { 3,8,5,2 };
	li.push_back(8);	//add the element to the end of list
	li.push_front(82); //add the element to the front of list

	//point the iterator to second element in list
	list<int>::iterator itr3 = find(li.begin(), li.end(), 2);	//itr2->2
	
	li.insert(itr3,3);	//insert 3 to position 2 li = {3,8,3,5,2}

	itr2++;
	li.erase(itr3);		//remove the element with position 3 li={3,8,3,5}

	//splice cut data in li2 and insert into itr3 from itra to itrb
	//li.splice(itr3, li2, itra, itrb);

	/*
	-----------------Array-----------------
	*/
	//syntax: array<type,length>identifier={elements};
	//size cannot be change
	//array of integer may have different of type according to length
	array<int, 3>arr = { 0,1,2 };
	array<int, 4>arr2 = { 0,1,2 };



	/*
	------------------Set------------------------
	*/
	//create set, set cannot have same element like {3,3}
	set<int> myset;
	//insert value into set
	myset.insert(3);	//myset:{3}
	myset.insert(1);	//myset:{1,3}
	myset.insert(8);	//myset:{1,3,8}  O log n

	set<int>::iterator itr5;
	//point the iterator to 3 in set
	itr5 = myset.find(3);	//O log n

	pair<set<int>::iterator, bool> pair1;
	pair1 = myset.insert(3);	//no element inserted to set but return bool insert or not

	if (pair1.second == false)
		itr5 = pair1.first;		//point to the value if false to insert

	myset.insert(itr5, 9);		//myset:{1,3,8,9}	can be hint for insertion of value O log n => O(1)
								//itr5 still point to 3
	myset.erase(itr5);			//remove the element pointed by iterator myset:{1,8,9}
	myset.erase(8);				//remove the element	myset:{1,9}

	/*
	------------------multiset----------------
	*/
	//allow duplicate
	//value of set/multiset cannot be modified
	multiset<int> mymultiset;


	/*
	----------------------map-------------------
	*/
	//create map
	map<char, int> mymap;
	//can only insert with pair
	mymap.insert(pair<char, int>('a', 200));
	mymap.insert(make_pair('z', 210));
	
	map<char, int>::iterator itr6=mymap.begin();
	mymap.insert(itr6, pair<char, int>('b', 100));
	itr6 = mymap.find('z');	// O log n

	for (itr6 = mymap.begin(); itr6 != mymap.end(); itr6++) {
		cout << (*itr6).first << "=>" << (*itr6).second << endl;
	}

	/*
	----------------multimap----------------
	*/
	multimap<char, int> mymultimap;

	/*
	----------------unordered set-------------------
	*/
	unordered_set<int> myunset = { 4,10,25 };
	unordered_set<int>::const_iterator itr7 = myunset.find(10);	//O(1)
	if (itr7 != myunset.end())
		cout << *itr7 << endl;
	myunset.insert(90);	//O(1)

	vector<int> numbers = { 5,87,92 };
	myunset.insert(numbers.begin(), numbers.end());

	//hash table specific APIs:
	//load_factor show ratio of total number of element and total number of bucket
	cout << myunset.load_factor() << endl;
	//show the bucket of the element
	cout << "5 is in bucket #" << myunset.bucket(5) << endl;
	//show total number of bucket
	cout << "Total bucket #" << myunset.bucket_count() << endl;



	/*
	---------------Associative Array-------------------
	-for map and unordered_map only
	*/
	unordered_map<char, string> myunmap = { {'M',"Monday"},{'S',"Sunday"} };

	cout << myunmap['S'] << endl;	//no bound check
	cout << myunmap.at('S') << endl;//got bound check

	numbers[20] = 20;	//error , haven't create yet

	myunmap['W'] = "Wednesday";	//Insert {'W',"Wednesday"}
	myunmap.insert(make_pair('F', "Friday"));//Insert {'F',"Friday}

	myunmap.insert(make_pair('M', "Monday"));	//false, already got the element
	myunmap['M'] = "Monday";	//will modify the value with 'M' key

	//if map is const, the [] operator cannot be used
	//bacause consider write data with use the operator	
	//to display the value in const, use iterator

	return 0;
}