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
#include <random>
//all the member in stl used std namespace
using namespace std;

/*
	Main notes:
	Algorithms
	-mostly loops
	-always process range in half-open way [start,end)
	-mostly return a pair of iterator point to a position from a range of data
	-sometimes need 2 range to process
	-some algorithm work with functions
	-can work with native c++ array also
	-most algorithm provide simple form and generalized form

	-non-modifying algorithm(do not change element values)
	-count
	-min & max
	-compare
	-linear search
	-attribute

	-value-changing algorithm(changes the element values
	-copy
	-move
	-transform
	-swap
	-fill
	-replace
	-remove

	-order-changing algorithm(change the order of element)
	-reverse
	-rotate
	-permute
	-shuffle

	-sorting
	-required random access iterator:vector,deque,array

	-heap algorithm
	-first element always the largest
	-add or move takes O log n time

	-sorted data algorithm
	-require data begin pre-sorted
	-binary search
	-merge
	-set operations

	-numeric algorithm (in <numeric>)
	-accumulate
	-inner product
	-partial sum
	-adjacent difference
*/

bool isOdd(int i) {
	return i % 2;
}

int main(int argc, char** argv)
{
	//vector
	vector<int> vec1 = { 5,27,23,51 };
	vector<int> vec2(3);
	
	//iterators
	vector<int>::iterator vec1_itr;
	/*
	--------algorithms------
	*/

	//min_element return the smallest value in the range
	vec1_itr = min_element(vec1.begin(), vec1.end());	//vec_itr => 5

	//sort
	sort(vec1.begin(), vec1.end());	//vec: {5, 23, 27, 51}
	//reverse
	reverse(vec1.begin(), vec1.end());	//vec: {51, 27, 23, 5}	vec_itr => 51

	/*
	copy process with 2 range:
	vec1_itr to vec1.end()	-	data to be copy(source)
	vec2.begin()			-	position to be insert(destination)
	*/
	vec1_itr = find(vec1.begin(), vec1.end(), 27);
	//vec2 must have at least 3 empty space
	copy(vec1_itr, vec1.end(), vec2.begin());
	//the above statement will replaced the current existing date.

	//can use insert_iterator
	copy(vec1_itr, vec1.end(), back_inserter(vec2));	//insert data into vec2 instead of overwrite
	//above statement is safe but low efficient
	
	//can use built-in insert statement
	vec2.insert(vec2.end(), vec1_itr, vec1.end());		//efficient and safe

	vec1_itr = find_if(vec1.begin(), vec1.end(), isOdd);







	/*
	--------------non-modifying algorithm---------------------
	*/
	vector<int> vec = { 9,60,90,8,45,87,90,69,69,55,7 };
	vector<int> vec2 = { 9,60,70,8,45,87 };
	vector<int>::iterator itr, itr2;
	pair<vector<int>::iterator, vector<int>::iterator>pair_of_itr;

	//counting
	//return num, param:range            operation
	int n = count(vec.begin(), vec.end(), [](int x) {return x < 50; });	//4


	//min && max
	//return the position of largest digit
	itr = max_element(vec.begin(), vec.end());
	//return the first max value
	itr = max_element(vec.begin(), vec.end(), [](int x, int y) {return (x % 10) < (y % 10); });
	//return first min value
	itr = min_element(vec.begin(), vec.end());
	//return pair contain first of min and last of max
	pair_of_itr = minmax_element(vec.begin(), vec.end());
	

	//linear searching - used only when data is not sorted
	//if data is sorted, binary search is more efficient
	//return the first match
	itr = find(vec.begin(), vec.end(), 55);
	itr = find_if(vec.begin(), vec.end(), [](int x) {return x < 10; });
	itr = find_if_not(vec.begin(), vec.end(), [](int x) {return x < 10; });
	//search 2 consecutive 69 element
	itr = search_n(vec.begin(), vec.end(), 2, 69);
	//generalized form: search_n()

	//search subrange
	vector<int> sub = { 45,87,90 };
	//search first subrange
	itr = search(vec.begin(), vec.end(), sub.begin(), sub.end());
	//search last subrange
	itr = find_end(vec.begin(), vec.end(), sub.begin(), sub.end());
	//generalized form: search & find_end

	//search any_of
	vector<int> items = { 87,69 };
	//search any element match any one in items
	itr = find_first_of(vec.begin(), vec.end(), items.begin(),items.end());
	//search any element match after the operation
	itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(), [](int x, int y) {return x == y * 4; });

	//search adjacent
	//find first 2 adjacent items that are same
	itr = adjacent_find(vec.begin(), vec.end());
	//find first 2 adjacent items that satisfy the operation
	itr = adjacent_find(vec.begin(), vec.end(), [](int x, int y) {return x == y * 4; });

	
	//compare range
	//equal check either the vector are same
	if (equal(vec.begin(), vec.end(), vec2.begin()))
		cout << "vec and vec2 are same" << endl;
	//is_permutation check either has same element but different order
	else if (is_permutation(vec.begin(), vec.end(), vec2.begin()))
		cout << "vec and vec2 have same elements but different order" << endl;
	
	//find first difference
	pair_of_itr = mismatch(vec.begin(), vec.end(), vec2.begin());
	
	//lexicographical comparison: 1-by-1 comparison with "<"
	lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
	// {1,2,3,5}<{1,2,4,5}	check until first difference and 3<4
	//{1,2}<{1,2,3}			{1,2} has less element
	

	//cehck attributes
	//check either the vector is sorted
	is_sorted(vec.begin(), vec.end());

	//return iterator point to the place where elements are no sorted
	itr = is_sorted_until(vec.begin(), vec.end());

	//check if the vector is partitioned according to the condition
	is_partitioned(vec.begin(), vec.end(), [](int x) {return x > 80; });

	//check if data is a heap
	is_heap(vec.begin(), vec.end());
	//point to first place where it is no longer a heap

	itr = is_heap_until(vec.begin(), vec.end());


	//check all data match condition
	all_of(vec.begin(), vec.end(), [](int x) {return x > 80; });
	//check if any data match condition
	any_of(vec.begin(), vec.end(), [](int x) {return x > 80; });
	//check if all data do not match condition
	none_of(vec.begin(), vec.end(), [](int x) {return x > 80; });
	
	
	/*
	------------------modifying algorithms----------------
	*/
	vec = { 9,60,70,8,45,87,90 };
	vec2 = { 0,0,0,0,0,0,0,0,0,0,0 };
	

	//copy - copy any things from source to destination
	//make sure the size in destination larger than the size to copy
	copy(vec.begin(), vec.end(), vec2.begin());
	//copy if meet condition
	copy_if(vec.begin(), vec.end(), vec2.begin(), [](int x) {return x < 60; });
	//copy n things from source to destionation
	copy_n(vec.begin(), 4, vec2.begin());
	//copy from back to start
	copy_backward(vec.begin(), vec.end(), vec2.end());


	//move - move items from one page to another
	vector<string> vec3 = { "apple","orange","pear","grape" };
	vector<string> vec4 = { "","","","","","" };

	move(vec3.begin(), vec3.end(), vec4.begin());
	/*
		vec3: {"","","",""}	//undefined
		vec4: {"apple","orange","pear","grape","",""}
	*/

	move_backward(vec3.begin(), vec3.end(), vec4.end());
	//vec4: {"","","apple","orange","pear","grape"}


	//transform
	vec = { 9,60,70,8,45,87,90 };
	vec2 = { 9,60,70,8,45,87,90 };
	vector<int> vec5 = { 0,0,0,0,0,0,0,0,0,0,0 };

	//perform operation and save data into other vector
	transform(vec.begin(), vec.end(), vec3.begin(), [](int x) {return x - 1; });

	transform(vec.begin(), vec.end(), vec2.begin(), vec3.begin(), [](int x, int y) {return x + y; });

	//swap
	//swap the elements in vectors
	swap_ranges(vec.begin(), vec.end(), vec2.begin());

	//fill
	//used to fill the vector with certain value
	vec = { 0,0,0,0,0 };
	fill(vec.begin(), vec.end(), 9);
	fill_n(vec.begin(), 3, 9);
	//use value generating function to fill the vector
	generate(vec.begin(), vec.end(), rand);
	generate_n(vec.begin(), 3, rand);


	//replace
	//replace the orginal value (6) with new value(9) in vector
	replace(vec.begin(), vec.end(), 6, 9);
	//replace if meet condition
	replace_if(vec.begin(), vec.end(), [](int x) {return x < 80; }, 9);
	//replace the value and copy the remain to next vector
	replace_copy(vec.begin(), vec.end(), vec2.begin(), 6, 9);
	

	//remove
	//remove fixed value from vector
	remove(vec.begin(), vec.end(), 3);
	//remove if meet condition
	remove(vec.begin(), vec.end(), [](int x) {return x > 80; });
	//remove the value and copy the remain value to next vector
	remove_copy(vec.begin(), vec.end(), vec2.begin(), 6);
	//remove consecutive equal elements
	unique(vec.begin(), vec.end());
	//generalize:unique
	//remove consecutive element and copy to next vector
	unique(vec.begin(), vec.end(), vec2.begin());


	/*
	-------------order-changing algorithms----------------
	*/
	vec = { 9,60,70,8,45,87,90 };
	vec2 = { 0,0,0,0,0,0,0 };
	
	//reverse
	reverse(vec.begin(), vec.end());
	//vec = {90,87,45,8,70,60,9}
	reverse_copy(vec.begin(), vec.end(), vec2.begin());
	//vec2={90,87,45,8,70,60,9}


	//rotate
	//rotate from vec.begin() until end() till vec.begin()+3 become first element
	rotate(vec.begin(), vec.begin() + 3, vec.end());

	//rotate and copy result to destination vector
	rotate_copy(vec.begin(), vec.begin() + 3, vec.end(), vec2.begin());


	//permute
	//lexicographically next greater permutation
	next_permutation(vec.begin(), vec.end());
	//lexicographically next  smaller permutation
	prev_permutation(vec.begin(), vec.end());

	//sorted in ascending order: lexicographically smallest
	//sorted in descending order: lexicographically largest


	//shuffle
	//rearrange elements randomly
	random_shuffle(vec.begin(), vec.end());
	random_shuffle(vec.begin(), vec.end(), rand);
	//better random number generation in random class
	shuffle(vec.begin(), vec.end(), default_random_engine());


	/*
	---------------------sorting-----------------------
	*/
	vec = { 9,1,10,2,45,3,90,4,9,5,8 };
	//default: sort with < (ascending order)
	sort(vec.begin(), vec.end());
	//sort with the lambda function
	sort(vec.begin(), vec.end(), [](int x, int y) {return (x % 10) < (y % 10); });
	//sort for the fixed range
	partial_sort(vec.begin(), vec.begin() + 5, vec.end(),greater<int>());
	//move the num of data meet criteria to front but not sorted
	nth_element(vec.begin(), vec.end() + 5, vec.end(), greater<int>());
	//if meet criteria, move to front and sort
	partition(vec.begin(), vec.end(), [](int x) {return x < 10; });
	//only move but not sorted
	stable_partition(vec.begin(), vec.end(), [](int x) {return x < 10; });

	
	/*
	----------------heap algorithm--------------------------
	*/
	vec = { 9,1,10,2,45,3,90,4,9,5,8 };
	//convert vector into heap
	make_heap(vec.begin(), vec.end());

	//remove largest element in heap
	pop_heap(vec.begin(), vec.end());
	//swap vec[0] with vec[size-1]
	//heapify [vec.begin(),vec.end()-1)
	vec.pop_back();	//remove last item


	//add new element
	vec.push_back(100);
	push_heap(vec.begin(), vec.end());	//Heapify last item


	//Heap Sorting:
	//only work on heap
	sort_heap(vec.begin(), vec.end());

	/*
	----------------sorted data algorithm---------------------
	*/
	//binary search
	//check if data in the range
	bool found = binary_search(vec.begin(), vec.end(), 9);

	vector<int> s = { 9,45,66 };
	//search either all elements in range 2 included in range1
	found = includes(vec.begin(), vec.end(), s.begin(), s.end());

	//search position
	//search first position of data
	itr = lower_bound(vec.begin(), vec.end(), 9);
	//search last position of data
	itr = upper_bound(vec.begin(), vec.end(), 9);
	//return both first and last position
	pair_of_itr = equal_range(vec.begin(), vec.end(), 9);


	//Merge
	//merge 2 range of sorted data into 1 range of sorted data
	vec = { 8,9,9,10 };
	vec2 = { 7,9,10 };
	vector<int>vec_out(10);
	merge(vec.begin(), vec.end(), vec2.begin(), vec2.end(),vec_out.begin());

	vec = { 1,2,3,4,1,2,3,4,5 };
	//sort one vector which contain 2 part of sorted data
	inplace_merge(vec.begin(), vec.begin() + 4, vec.end());


	//set operation
	vec = { 8,9,9,10 };
	vec2 = { 7,9,10 };
	//merge keep every things, union only save one copy if both contain same element
	set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
	//keep data only if both vector have same element
	set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
	//keep data only when vec1 have but vec2 did not have
	set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
	//keep data in vec1 but not vec2 and in vec2 but not vec1
	set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
	
	

	/*
	----------------numeric algorithm-------------------------
	*/
	//accumulate the vector with initial value
	int x = accumulate(vec.begin(), vec.end(), 0);
	x = accumulate(vec.begin(), vec.end(), 0,multiplies<int>());
	//vec[0]*vec[1]...


	//calculate inner product of 2 range of data
	x = inner_product(vec.begin(), vec.begin() + 3, vec.end() - 3, 10);
	//10 + (vec[0] * vec[4])+...
	x = inner_product(vec.begin(), vec.begin() + 3, vec.end() - 3, 10,multiplies<int>(),plus<int>());
	//10 * (vec[0]+vec[4]) * ...


	//calculate partial sum and save result in destination
	partial_sum(vec.begin(), vec.end(), vec2.begin());
	/*
	vec2[0] = vec[0]
	vec2[1] = vec[0] + vec[1]
	vec2[2] = vec[0] + vec[1] + vec[2]
	*/


	//calculate the adjacent different and save result in destination
	adjacent_difference(vec.begin(), vec.end(), vec2.begin());
	/*
	vec2[0] = vec[0]
	vec2[1] = vec[1] - vec[0]
	vec2[2] = vec[2] - vec[1]
	*/
	return 0;
}