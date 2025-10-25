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

    bool valid(vector<int> &hm, int n) {
        int one = n / 100;
        int two = n / 10 % 10;
        int three = n % 10;
        vector<int> line(10, 0);
        line[one]++;
        line[two]++;
        line[three]++;
        for (int i = 0; i < 10; i++) {
            if (line[i] > hm[i]) return false;
        }
        return true;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> hm(10, 0);
        for (int num: digits) {
            hm[num]++;
        }
        vector<int> ans;
        for (int i = 100; i <= 998; i+=2) {
            if (valid(hm, i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}