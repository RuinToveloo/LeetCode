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
        int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
            int n = books.size();
            vector<int> dp(n+1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i <= n; i++) {
                int rem_w = 0;
                int max_h = 0;
                for (int j = i; j > 0; j--) {
                    rem_w += books[j-1][0];
                    if (rem_w > shelfWidth) break;
                    max_h = max(max_h, books[j-1][1]);
                    dp[i] = min(dp[i], dp[j-1] + max_h);
                }
            }
            return dp[n];
        }
};

int main() {
    Solution sol;

    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth = 4;
    int result = sol.minHeightShelves(books, shelfWidth);

    cout << "Result: " << result << endl;
    return 0;
}