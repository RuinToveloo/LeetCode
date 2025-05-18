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
        int colorTheGrid(int m, int n) {
            int MOD = 1e9 + 7;
            vector<int> states;
            
            function<void(int, int)> gen = [&](int i, int code) {
                if (i == m) {
                    states.push_back(code);
                    return;
                }
                for (int c = 0; c < 3; c++) {
                    if (i > 0 && code % 3 == c) continue;
                    gen(i + 1, code * 3 + c);
                }
            };
            
            gen(0, 0);
            
            int S = states.size();
            vector<vector<int>> can(S);
            for (int i = 0; i < S; i++) {
                for (int j = 0; j < S; j++) {
                    int a = states[i];
                    int b = states[j];
                    bool ok = true;
                    for (int k = 0; k < m; k++) {
                        if (a % 3 == b % 3) {
                            ok = false;
                            break;
                        }
                        a /= 3;
                        b /= 3;
                    }
                    if (ok) can[i].push_back(j);
                }
            }
    
            vector<int> dp(S, 1);
            for (int col = 1; col < n; col++) {
                vector<int> ndp(S, 0);
                for (int i = 0; i < S; i++) {
                    for (int j : can[i]) {
                        ndp[j] += dp[i];
                        ndp[j] %= MOD;
                    }
                }
                dp = ndp;
            }
    
            int ans = 0;
            for (int x : dp) {
                ans += x;
                ans %= MOD;
            }
            return ans;
        }
   };
    

int main() {
    Solution sol;
    int n = 5;
    int m = 5;
    int result = sol.colorTheGrid(m, n);
    cout << "Result: " << result << endl;

    return 0;
}
