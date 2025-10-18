#include <iostream>     // Input/output stream operations
#include <string>       // String manipulation (std::string)
#include <vector>       // Dynamic arrays (std::vector)
#include <algorithm>    // Common algorithms (sort(), find(), etc.)
#include <cmath>        // Mathematical functions (sqrt(), pow(), etc.)
#include <cstdlib>      // General utility functions (malloc(), free(), rand(), etc.)
#include <ctime>        // Date and time functions
#include <fstream>      // File input/output operations
#include <map>          // Sorted associative containers (std::map)
#include <set>          // Unique sorted elements (std::set)
#include <list>         // Doubly linked list (std::list)
#include <queue>        // Queues (std::queue, std::priority_queue)
#include <stack>        // Stack container (std::stack)
#include <tuple>        // Tuple container (std::tuple)
#include <iterator>     // Iterator utilities
#include <limits>       // Numeric limits (std::numeric_limits)
#include <memory>       // Smart pointers (std::unique_ptr, std::shared_ptr)
#include <type_traits>  // Compile-time type checking and manipulation
#include <thread>       // Multithreading (std::thread)
#include <atomic>       // Atomic operations
#include <condition_variable>  // Synchronization primitives
#include <exception>    // Exception handling (std::exception)
#include <stdexcept>    // Standard exceptions (std::runtime_error, std::out_of_range)
#include <cassert>      // Assertions (assert())
#include <cctype>       // Character handling functions (isdigit(), tolower(), etc.)
#include <sstream>      // String stream operations (std::stringstream)
#include <numeric>      // Numeric operations (accumulate(), iota(), etc.)
#include <climits>      // For INT_MIN

using namespace std;

// hashtable implement using array (no use of std::vector, no hashmap)

// int [10]  keys;  // all initialize to -1
// int [10]  vals;  // all initialize to -1

int *keys;
int *vals;

// O(1)  performance for best case 

void insert(int key, int val)
{
    int index = key % 10; /* find the index of the key */
  // if the key is already there, we overwrite the val 
  // cout << "here enter " << key << " " << val << " " << keys[index] << endl;
  if (keys[index] == -1) {
    /* no stored yet */
    keys[index] = key;
    vals[index] = val;
  } else {
    // resolve conflict -- collision
    bool check = false; /* check is true if we can insert it into the rest of the array */
    for (int i = index + 1; i < 10; i++) {
        if (keys[i] == -1) {
            // cout << "here fix collision " << key << " " << val << " " << i << endl;
            /* here is the empty space */
            check = true;
            keys[i] = key;
            vals[i] = val;
            break;
        }
    }
    /* if the rest of the position are all full */
    if (!check) {
        /* check the head of the array and insert to empty*/
        for (int i = 0; i < index; i++) {
            if (keys[i] == -1) {
                keys[i] = key;
                vals[i] = val;
                break;
            }
        }
    }
    /* by default, it is graunteed it can be inserted */
  }
  
}

int query(int key) {
    int index = key % 10;
    return vals[index];
}

void replace(int index) {
    int i = index + 1;
    while (i != index) {
        if (i == 10) i = 0; /* from tail to head */
        if (keys[i] % 10 == index) {
            /* found it */
            keys[index] = keys[i];
            vals[index] = vals[i];
            keys[i] = -1;
            vals[i] = -1;
            replace(i);
            break;
        }
        i++;
    }
}

void remove(int key)
{
    bool removed = false;
    int pos = -1; // position of the just removed element
    /* remove the position */
    for (int i = 0; i < 10; i++) {
        if (keys[i] == key) {
            vals[i] = -1;
            keys[i] = -1;
            removed = true;
            pos = i;
            break;
        }
    }
    if (pos != -1) replace(pos);
}

int main() {
    /* setup */
    keys = new int[10];
    vals = new int[10];
    for (int i = 0; i < 10; i++) {
        keys[i] = -1;
        vals[i] = -1;
    }

    /* test case */
    // insert <21, 343>
    insert(21, 343);
    // cout << "inserted <21, 343>" << endl;
    // query(21) 
    // cout << "query(21) " << query(21) << endl;


    // insert<121, 9>  
    insert(121, 9);
    // cout << "inserted <121, 9>" << endl;
    // remove(21)
    remove(21);
    // cout << "removed 21" << endl;


    // cout << "debug: " << keys[1] << " " << vals[1] << endl;
    // cout << "debug: " << keys[2] << " " << vals[2] << endl;


    // query(121)
    // cout << "query(121) " << query(121) << endl;

    delete[] keys;
    delete[] vals;

    return 0;
}


/*
 *assume all key/value >= 0

no more than 10 elements 

insert <21, 343>    
   ==>  21 %10 ==> index==1    array idx==1     key[1] = 21 ;  val[1] =343

query(21) == >343
  21 % 10 == > 1 ==>  check key[1] ==> 21,  return val[1]

insert<121, 9>  
   ==> 121 % 10 ==>1       key[1] is already occupied.  linear probing. key[2] == -1 ==> key[2]= 121,  val[2] = 9


remove(21)
query(121) ==>   121 % 10 == >1    key[1] ?  ==> return 9 instead of 343
*/