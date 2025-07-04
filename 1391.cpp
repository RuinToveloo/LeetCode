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
    int n = 0;
    int m = 0;
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }


    bool hasValidPath(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        int i = 0;
        int j = 0;
        vector<vector<bool>> v(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (q.size()) {
            pair<int, int> p = q.front();
            q.pop();
            i = p.first;
            j = p.second;
            if (i == n-1 && j == m - 1) return true;
            if (!valid(i, j)) continue;
            if (v[i][j]) continue;
            v[i][j] = true;

            if (g[i][j] == 1) {
                if (j+1 < m && 
                    (g[i][j+1] == 1 || g[i][j+1] == 3 || g[i][j+1] == 5)) {
                        if (!v[i][j+1]) q.push({i, j+1});
                }
                if (j-1 >= 0 && 
                    (g[i][j-1] == 1 || g[i][j-1] == 4 || g[i][j-1] == 6)) {
                        if (!v[i][j-1]) q.push({i, j-1});
                }
            }

            if (g[i][j] == 2) {
                if (i+1 < n && 
                    (g[i+1][j] == 2 || g[i+1][j] == 5 || g[i+1][j] == 6)) {
                        if (!v[i+1][j]) q.push({i+1, j});
                }
                if (i-1 >= 0 && 
                    (g[i-1][j] == 2 || g[i-1][j] == 3 || g[i-1][j] == 4)) {
                        if (!v[i-1][j]) q.push({i-1, j});
                }
            }

            if (g[i][j] == 3) {
                if (i+1 < n && 
                    (g[i+1][j] == 2 || g[i+1][j] == 5 || g[i+1][j] == 6)) {
                        if (!v[i+1][j]) q.push({i+1, j});
                }
                if (j-1 >= 0 && 
                    (g[i][j-1] == 1 || g[i][j-1] == 4 || g[i][j-1] == 6)) {
                        if (!v[i][j-1]) q.push({i, j-1});
                }
            }

            if (g[i][j] == 4) {
                if (i+1 < n && 
                    (g[i+1][j] == 2 || g[i+1][j] == 5 || g[i+1][j] == 6)) {
                        if (!v[i+1][j]) q.push({i+1, j});
                }
                if (j+1 < m && 
                    (g[i][j+1] == 1 || g[i][j+1] == 3 || g[i][j+1] == 5)) {
                        if (!v[i][j+1]) q.push({i, j+1});
                }
            }

            if (g[i][j] == 5) {
                if (i-1 >= 0 && 
                    (g[i-1][j] == 2 || g[i-1][j] == 3 || g[i-1][j] == 4)) {
                        if (!v[i-1][j]) q.push({i-1, j});
                }
                if (j-1 >= 0 && 
                    (g[i][j-1] == 1 || g[i][j-1] == 4 || g[i][j-1] == 6)) {
                        if (!v[i][j-1]) q.push({i, j-1});
                }
            }

            if (g[i][j] == 6) {
                if (i-1 >= 0 && 
                    (g[i-1][j] == 3 || g[i-1][j] == 4 || g[i-1][j] == 2)) {
                        if (!v[i-1][j]) q.push({i-1, j});
                }
                if (j+1 < m && 
                    (g[i][j+1] == 1 || g[i][j+1] == 3 || g[i][j+1] == 5)) {
                        if (!v[i][j+1]) q.push({i, j+1});
                }
            }

        }
        return false;
    }
};


// 1 left->right
// 2 up->down
// 3 left->down
// 4 right->down
// 5 up->left
// 6 up->right

int main() {
    return 0;
}