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
    bool valid(vector<int> &vec) {
        int n = vec.size();
        if (n == 1) return true;
        for (int i = 1; i < n; i++) {
            if (vec[i] < vec[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (valid(nums)) return 0;
        int j = 2;
        int indexi = 0;
        int temp = nums[0] + nums[1];
        while (j < n) {
            int sum = nums[j] + nums[j-1];
            if (sum < temp) {
                temp = sum;
                indexi = j-1;
            }
            j++;
        }
        nums.erase(nums.begin() + indexi);
        nums.erase(nums.begin() + indexi);
        nums.insert(nums.begin() + indexi, temp);
        return 1 + minimumPairRemoval(nums);
    }
};

int main() {
    return 0;
}