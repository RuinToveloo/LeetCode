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
        int to_int(string s) {
            int ans = 0;
            for (int i = 0; i < s.size(); i++) {
                ans = ans * 10 + s[i] - '0';
            }
            return ans;
        }
    
        string smallestNumber(string pattern) {
            int n = pattern.size();
            int ans = INT_MAX;
            stack<string> sk;
            for (int i = 1; i <= 9; i++) {
                sk.push(to_string(i));
            }
            while (sk.size()) {
                string s = sk.top();
                sk.pop();
                int now = to_int(s);
                if (s.size() == n+1) {
                    ans = min(ans, now);
                    continue;
                }
                vector<int> line(10, -1);
                for (char c: s) {
                    line[c-'0'] = 1;
                }
                char dir = pattern[s.size()-1];
                for (int i = 1; i <= 9; i++) {
                    if (line[i] != -1) continue;
                    if ((dir == 'D' && i+'0' < s[s.size()-1]) ||
                        (dir == 'I' && i+'0' > s[s.size()-1])) {
                            sk.push(to_string(now * 10 + i));
                    }
                }
            }
    
            return to_string(ans);
        }
};

int main() {
    Solution sol;
    string pattern = "IIIDIDDD";
    string result = sol.smallestNumber(pattern);
    cout << "Result: " << result << endl;

    return 0;
}
