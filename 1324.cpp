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
    vector<string> printVertically(string s) {
        vector<string> line;
        string temp = "";
        size_t len = 0;
        for (char c: s) {
            if (c == ' ') {
                if (temp != " ") line.push_back(temp);
                len = max(len, temp.size());
                temp = "";
            } else { 
                temp+=c;
            }
        }
        len = max(len, temp.size());
        line.push_back(temp);
        

        int n = (int) len;
        vector<string> ans(n, "");
        for (string str: line) {
            for (int i = 0; i < str.size(); i++) {
                ans[i].push_back(str[i]);
            }
            for (int j = str.size(); j < len; j++) {
                ans[j].push_back(' ');
            }
        }
        for (string &now: ans) {
            while (now.back() == ' ') {
                now.erase(now.size()-1, 1);
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}