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
        vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
            vector<vector<int>> ans(m, vector<int>(n, 0));
            vector<vector<int>> empty;
            if (original.size() != n * m) return empty;
            int i = 0;
            int j = 0;
            int index = 0;
            while (i < m && j < n) {
                ans[i][j] = original[index++];
                j++;
                if (j == n) {
                    j = 0;
                    i++;
                }
            }
            return ans;
        }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = sol.construct2DArray(nums, 2, 2);

    for (vector<int> line: res) {
        for (int item: line) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}