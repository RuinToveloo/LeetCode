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
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end(), [&](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });
    
            vector<int> prev = pairs[0];
            int ans = 1;
    
            for (int i = 1; i < pairs.size(); i++) {
                vector<int> cur = pairs[i];
                if (cur[0] > prev[1]) {
                    ans++;
                    prev = cur;
                }
            }
    
            return ans;        
        }
};

int main() {
    Solution sol;
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    
    int result = sol.findLongestChain(pairs);
    cout << "Longest chain " << result << endl;

    return 0;
}
