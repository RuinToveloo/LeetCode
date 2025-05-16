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
        bool differByOneChar(string word1, string word2) {
            if (word1.length() != word2.length()) return false;
            int diffCount = 0;
            for (int i = 0; i < word1.length(); i++) 
                diffCount += word1[i] != word2[i];
            return diffCount == 1;
        }
        
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = groups.size();
            vector<int> dp(n, 1), parent(n, -1);
            int maxi = 0;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (groups[i] != groups[j] && 
                            differByOneChar(words[i], words[j]) && 
                                dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
                maxi = max(maxi, dp[i]);
            }
            
            vector<string> result;
            for (int i = 0; i < n; i++) {
                if (maxi == dp[i]) {
                    while (i != -1) {
                        result.push_back(words[i]);
                        i = parent[i];
                    }
                    break;
                }
            }
            reverse(result.begin(), result.end());
            return result;
        }
};

int main() {
    Solution sol;
    vector<string> words = {"bab","dab","cab"};
    vector<int> groups = {1,2,2};
    vector<string> result = sol.getWordsInLongestSubsequence(words, groups);
    for (string str: result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
