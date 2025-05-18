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
        int knightDialer(int n) {
            int MOD = 1e9+7;
            vector<vector<int>> dp(10, vector<int>(n, 0));
            for (int i = 0; i < 10; i++) {
                dp[i][0] = 1;
            }
            for (int j = 1; j < n; j++) {
                dp[1][j] = (dp[6][j-1] + dp[8][j-1]) % MOD;
                dp[2][j] = (dp[7][j-1] + dp[9][j-1]) % MOD;
                dp[3][j] = (dp[4][j-1] + dp[8][j-1]) % MOD;
                dp[4][j] = ((dp[3][j-1] + dp[9][j-1]) % MOD + dp[0][j-1]) % MOD;
                dp[5][j] = dp[5][j-1];
                dp[6][j] = ((dp[0][j-1] + dp[1][j-1]) % MOD + dp[7][j-1]) % MOD;
                dp[7][j] = (dp[2][j-1] + dp[6][j-1]) % MOD;
                dp[8][j] = (dp[1][j-1] + dp[3][j-1]) % MOD;
                dp[9][j] = (dp[4][j-1] + dp[2][j-1]) % MOD;
                dp[0][j] = (dp[4][j-1] + dp[6][j-1]) % MOD;
            }
            int sum = 0;
            for (int i = 0; i < 10; i++) {
                sum+=dp[i][n-1];
                sum %= MOD;
            }
            return sum == 10 ? 10 : sum - 1;
        }
};

int main() {
    Solution sol;
    int n = 5000;
    int result = sol.knightDialer(n);
    cout << "Result: " << result << endl;

    return 0;
}
