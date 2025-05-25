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

    bool dfs(vector<vector<int>>& g, int i, int j, int val, vector<vector<bool>> &v) {
        int n = g.size();
        if (i < 0 || i == n || j < 0 || j == n) return false;
        if (v[i][j]) return false;
        if (g[i][j] > val) return false;
        if (i == n-1 && j == n-1) return true;
        v[i][j] = true;
        return dfs(g, i-1, j, val, v) || dfs(g, i+1, j, val, v) ||
               dfs(g, i, j-1, val, v) || dfs(g, i, j+1, val, v);
    }

    int swimInWater(vector<vector<int>>& g) {
        int right = 50*50;
        int left = 0;
        int n = g.size();
        int ans = INT_MAX;
        int mid = (right + left) / 2;
        while (left <= right) {
            vector<vector<bool>> v(n, vector<bool>(n, false));
            if (dfs(g, 0, 0, mid, v)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (right + left) / 2;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> g = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    int result = sol.swimInWater(g);

    cout << "Result: " << result << endl;
    return 0;
}