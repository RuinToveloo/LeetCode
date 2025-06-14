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
    int minMaxDifference(int num) {
        vector<int> l;
        while (num > 9) {
            l.insert(l.begin(), num % 10);
            num /= 10;
        }
        l.insert(l.begin(), num);
        int target_min = l[0];
        int target_max = l[0];
        int n = l.size();
        for (int i = 0; i < n; i++) {
            if (l[i] != 9) {
                target_max = l[i];
                break;
            }
        }
        int minn = 0;
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            minn = minn * 10 + ((l[i] == target_min) ? 0 : l[i]);
            maxx = maxx * 10 + ((l[i] == target_max) ? 9 : l[i]);
        }
        return maxx - minn;
    }
};

int main() {
    Solution sol;

    int num = 902939;
    int result = sol.minMaxDifference(num);

    cout << "Result: " << result << endl;
    return 0;
}