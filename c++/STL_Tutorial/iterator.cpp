#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <forward_list>
using namespace std;

bool MyFunction(int x,int y) {
    return x > y;
}

/*
    different between i++ and ++i:

    Obj& operator ++(){
        return 
    }

    void operator ++(Obj i){

    }

*/

/*
    Functor(class acts as a function)
    -used in the algorithm
    -smart function
    -can do more things than normal function
    -built-in functors <functional>
        -less / greater
        -less_equal / greater_equal
        -equals / not_equals_to
        -multiplies / minus / plus / divide / modulus / negate

    parameter binding
    bind(multiplies<int>(),placeholder::_1,10));    
    //multiplies recieve 2 parameter
    //but some algorithm only send 1, can bind the parameter to a value                                            
*/
class Add {
    int x;
public:
    Add(int x) {
        this->x = x;
    }
    int operator ()(int x) {
        return x + this->x;
    }
};


int main() {
    /*
     * Iterators
     */
     // 1. Random Access Iterator:  vector, deque, array
    vector<int>::iterator itr;
    auto itr1 = itr + 5;  // advance itr by 5
    auto itr2 = itr - 4;
    if (itr2 > itr1) 
        ++itr;   // faster than itr++
    --itr;

    // 2. Bidirectional Iterator: list, set/multiset, map/multimap
    list<int> itr;
    ++itr;
    --itr;

    // 3. Forward Iterator: forward_list
    forward_list<int> itr;
    ++itr;

    // Unordered containers provide "at least" forward iterators.

    // 4. Input Iterator: read and process values while iterating forward.
    int x = *itr;

    // 5. Output Iterator: output values while iterating forward.
    *itr = 100;



    // Every container has a iterator and a const_iterator
    set<int>::iterator itr;
    set<int>::const_iterator citr;  // Read_only access to container elements

    set<int> myset = { 2,4,5,1,9 };
    for (citr = myset.begin(); citr != myset.end(); ++citr) {
        cout << *citr << endl;
        //*citr = 3;
    }
    for_each(myset.cbegin(), myset.cend(), MyFunction);  // Only in C++ 11
    //add all elements with 3(used functor)
    for_each(myset.begin(), myset.end(), Add(3));


    // Iterator Functions:
    advance(itr, 5);       // Move itr forward 5 spots.   itr += 5;
    distance(itr1, itr2);  // Measure the distance between itr1 and itr2


    /* Iterator Adaptor (Predefined Iterator)
     *  - A special, more powerful iterator
     * 1. Insert iterator
     * 2. Stream iterator
     * 3. Reverse iterator
     * 4. Move iterator (C++ 11)
     */

     // 1. Insert Iterator:
    vector<int> vec1 = { 4,5 };
    vector<int> vec2 = { 12, 14, 16, 18 };
    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
    insert_iterator< vector<int> > i_itr(vec2, it);
    copy(vec1.begin(), vec1.end(),  // source
        i_itr);                   // destination
        //vec2: {12, 14, 4, 5, 16, 18}
    // Other insert iterators: back_insert_iterator, front_insert_iterator


    // 2. Stream Iterator:
    vector<string> vec4;
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(vec4));

    copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

    // Make it terse:
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
        ostream_iterator<string>(cout, " "));




    // 3. Reverse Iterator:
    vector<int> vec = { 4,5,6,7 };
    reverse_iterator<vector<int>::iterator> ritr;
    for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
        cout << *ritr << endl;   // prints: 7 6 5 4

}