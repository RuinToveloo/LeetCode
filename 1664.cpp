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

class Solution {
public:
    void print_(vector<int> l) {
        for (int num: l) {
            cout << num << " ";
        }
        cout << endl;
    }

    int get_it(vector<int> &l, int index, const int n) {
        if (index < 0 || index >= n) return 0;
        return l[index];
    }

    int waysToMakeFair(vector<int>& nums) {
        vector<int> even_front;
        vector<int> odd_front;
        vector<int> even_end;
        vector<int> odd_end;
        int even = 0;
        int odd = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) even+=nums[i];
            else odd+=nums[i];
            even_front.push_back(even);
            odd_front.push_back(odd);
        }
        even = 0;
        odd = 0;
        for (int i = n-1; i >= 0; i--) {
            if (i % 2 == 0) even+=nums[i];
            else odd+=nums[i];
            even_end.push_back(even);
            odd_end.push_back(odd);
        }
        reverse(even_end.begin(), even_end.end());
        reverse(odd_end.begin(), odd_end.end());

        // print_(odd_front);
        // print_(even_front);
        // print_(odd_end);
        // print_(even_end);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            even = get_it(even_front, i-1, n);
            odd = get_it(odd_front, i-1, n);
            // if (i % 2 == 0) {
                even+=get_it(odd_end, i+1, n);
                odd+=get_it(even_end, i+1, n);
            // }
            if (odd == even) ans++;
        }

        return ans;
    }


//          2 1 6 4
// odd_f.   0 1 1 5
// even_f.  2 2 8 8
// odd_end  5 5 4 4 
// even_end 8 6 6 0
};

int main() {
    return 0;
}