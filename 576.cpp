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
    int MOD = 1e9+7;
    bool invalid(int i, int j, int n, int m) {
        return i < 0 || j < 0 || i == n || j == m ||
            (i == 0 && j == 0) || (i == 0 && j == m-1) ||
            (i == n-1 && j == 0) || (i == n-1 && j == m-1);
    }

    bool inside(int i, int j, int n, int m) {
        return i >= 1 && i <= n-2 && j >= 1 && j <= m-2;
    }

    bool outside(int i, int j, int n, int m) {
        return !inside(i, j, n, m) && !invalid(i, j, n, m);
    }

    int findPaths(int n, int m, int maxMove, int r, int c) {
        n+=2; m+=2; r++; c++;
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
        if (maxMove == 0) return 0;
        dp[r-1][c] = 1;
        dp[r+1][c] = 1;
        dp[r][c-1] = 1;
        dp[r][c+1] = 1;
        for (int k = 2; k <= maxMove; k++) {
            vector<vector<int>> temp(n, vector<int>(m, 0));
            for (int i = 1; i < n-1; i++) {
                for (int j = 1; j < m-1; j++) {
                    if (dp[i][j] == 0) continue;
                    if (inside(i-1, j, n, m)) {
                        temp[i-1][j] += dp[i][j];
                        temp[i-1][j] %= MOD;
                    } else {
                        dp[i-1][j] += dp[i][j];
                        dp[i-1][j] %= MOD;
                    }
                    if (inside(i+1, j, n, m)) {
                        temp[i+1][j] += dp[i][j];
                        temp[i+1][j] %= MOD;
                    } else {
                        dp[i+1][j] += dp[i][j];
                        dp[i+1][j] %= MOD;
                    }
                    if (inside(i, j-1, n, m)) {
                        temp[i][j-1] += dp[i][j];
                        temp[i][j-1] %= MOD;
                    } else {
                        dp[i][j-1] += dp[i][j];
                        dp[i][j-1] %= MOD;
                    }
                    if (inside(i, j+1, n, m)) {
                        temp[i][j+1] += dp[i][j];
                        temp[i][j+1] %= MOD;
                    } else {
                        dp[i][j+1] += dp[i][j];
                        dp[i][j+1] %= MOD;
                    }
                }
            }

            for (int i = 1; i < n-1; i++) {
                for (int j = 1; j < m-1; j++) {
                    dp[i][j] = temp[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (outside(i, j, n, m)) {
                    ans+=dp[i][j];
                    ans %= MOD;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;

    int result = sol.findPaths(1, 3, 3, 0, 1);

    cout << "Result: " << result << endl;
    return 0;
}