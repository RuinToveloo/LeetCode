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
private:
    vector<int> grayCode(int n) {
        map<int, vector<int>> hm;
        if (n == 1) return {0, 1};
        if (n == 2) return {0, 1, 3, 2};
        if (n == 3) return {0, 1, 3, 2, 6, 7, 5, 4};

#if 0
        vector<int> line = {1, 2};
        int index = 3;
        hm[index++] = line;
        while (index <= 16) {
            // n is starting with 4 upto 16
            int diff = pow(2, index-3);
            int i = line.size()-1;
            while (i >= 0) {
                line.emplace_back(line[i--] + diff);
            }
            hm[index++] = line;
            if (index == n+1) break;
        }
        // for (auto it: hm) {
        //     cout << it.first << endl;
        //     print_(it.second);
        // }
        
        print_(line);
#endif


        vector<int> line = {0, 1, 3, 2};
        int index = 3;
        while (index <= n) {
            // index start with 3 up to 16;
            int diff = pow(2, index-1);
            int i = line.size()-1;
            while (i >= 0) {
                line.emplace_back(line[i--]+diff);
            }
            index++;
        }
        return line;

    }

public:

    void print_(vector<int> l) {
        for (int k: l) {
            cout << k << " "; 
        }
        cout << endl;
    }

    vector<int> circularPermutation(int n, int start) {
        vector<int> code = grayCode(n);
        vector<int> ans;
        bool todo = false;
        for (int num: code) {
            if (num == start) {
                todo = true;
            }
            if (todo) ans.push_back(num);
        }
        for (int num: code) {
            if (num == start) return ans;
            ans.push_back(num);
        }
        return {};
    }
};


int main() {
    Solution sol;

    vector<int> res = sol.circularPermutation(16, 7);
    sol.print_(res);
    return 0;
}