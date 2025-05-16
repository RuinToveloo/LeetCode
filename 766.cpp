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
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++) {
                int starti = i+1;
                int startj = 1;
                while (starti < n && startj < m) {
                    if (matrix[starti][startj] != matrix[starti-1][startj-1]) {
                        return 0;
                    }
                    starti++;
                    startj++;
                }
            }
    
            for (int j = 1; j < m; j++) {
                int starti = 1;
                int startj = j+1;
                while (starti < n && startj < m) {
                    if (matrix[starti][startj] != matrix[starti-1][startj-1]) {
                        return 0;
                    }
                    starti++;
                    startj++;
                }
            }
            return 1;
        }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    
    bool result = sol.isToeplitzMatrix(matrix);
    cout << "Result: " << result << endl;

    return 0;
}
