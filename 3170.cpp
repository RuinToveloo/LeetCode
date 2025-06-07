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
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> vec;
        for (int i = 0; i < 26; i++) {
            vec.push_back({});
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                vec[s[i]-'a'].push_back(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (vec[j].size() != 0) {
                        vec[j].pop_back();
                        break;
                    }
                }
            }
        }
        string str = "";
        for (int i = 0; i < n; i++) {
            str+='*';
        }
        for (int i = 0; i < 26; i++) {
            for (int pos: vec[i]) {
                str[pos] = i + 'a';
            }
        }
        string ans = "";
        for (char c: str) {
            if (c == '*') continue;
            ans+=c;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "aaba*";
    string result = sol.clearStars(s);

    cout << "Result: " << result << endl;
    return 0;
}