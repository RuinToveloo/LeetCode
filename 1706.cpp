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

    int dfs(vector<vector<int>>& g, int i, int j, int pos, const int n, const int m) {
        if (pos == -1 && i == n-1) {
            return j;
        }
        if (pos == -1) {
            return dfs(g, i+1, j, 1, n, m);
        }
        // pos == 1
        if (g[i][j] == 1) {
            if (j+1 == m || g[i][j+1] == -1) {
                return -1;
            }
            return dfs(g, i, j+1, -1, n, m);
        }

        // now is -1
        if (j-1 < 0 || g[i][j-1] == 1) {
            return -1;
        }
        return dfs(g, i, j-1, -1, n, m);
    }

    vector<int> findBall(vector<vector<int>>& g) {
        vector<int> ans;
        int n = g.size();
        int m = g[0].size();
        for (int j = 0; j < m; j++) {
            ans.push_back(dfs(g, 0, j, 1, n, m));
        }
        return ans;
    }
};

int main() {
    return 0;
}