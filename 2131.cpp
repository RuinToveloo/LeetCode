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
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string, int> hm;
        vector<int> vec(26, 0);
        for (string s: words) {
            if (s[0] == s[1]) vec[s[0]-'a']++;
            else hm[s]++;
        }
        for (auto it: hm) {
            string s = it.first;
            string ss = s;
            reverse(ss.begin(), ss.end());
            int val = min(it.second, hm[ss]);
            ans += (4 * val);
        }
        ans /= 2;
        bool odd = false;
        for (int num : vec) {
            if (num % 2 == 1) odd = true;
            ans += (num / 2 * 4);
        }
        if (odd) ans+=2;
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"ab","ty","yt","lc","cl","ab"};

    int result = sol.longestPalindrome(words);

    cout << "Result: " << result << endl;
    return 0;
}