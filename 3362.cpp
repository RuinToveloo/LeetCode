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
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
        });

        int n = nums.size();
        int m = queries.size();
        priority_queue<int> heap;
        vector<int> vec(n + 1, 0);
        int count = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            count += vec[i];
            while (j < m && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while (!heap.empty() && count < nums[i] && heap.top() >= i) {
                count += 1;
                vec[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (count < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2}, {0, 2}, {1, 1}};

    int result = sol.maxRemoval(nums, queries);

    cout << "Result: " << result << endl;
    return 0;
}