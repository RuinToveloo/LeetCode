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
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> prefixIndex;
        int score = 0;
        int ans = 0;
        for (int i = 0; i < hours.size(); ++i) {
            if (hours[i] > 8) score++;
            else score--;

            if (score > 0) {
                ans = i + 1;
            } else {
                if (prefixIndex.count(score - 1)) {
                    ans = max(ans, i - prefixIndex[score - 1]);
                }
            }

            if (!prefixIndex.count(score)) {
                prefixIndex[score] = i;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> hours = {9,9,6,0,6,6,9};

    int result = sol.longestWPI(hours);

    cout << "Result: " << result << endl;
    return 0;
}