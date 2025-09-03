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

    char helper(int &a, int &b, int &c) {
        int num = max(a, max(b, c));
        if (num == 0) {
            return '?';
        }
        if (num == a) {
            a--;
            return 'a';
        } else if (num == b) {
            b--;
            return 'b';
        }
        c--;
        return 'c';
    }

    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        while (1) {
            // cout << ans << endl;
            char res = '.';
            int n = ans.size();
            if (n >= 2) {
                if (ans[n-1] == ans[n-2]) {
                    char ch = ans[n-1];
                    if (ch == 'a') {
                        int tempa = 0;
                        res = helper(tempa, b, c);
                        if (res != '?') {
                            ans+=res;
                        }
                    } else if (ch == 'b') {
                        int tempb = 0;
                        res = helper(a, tempb, c);
                        if (res != '?') {
                            ans+=res;
                        }
                    } else {
                        int tempc = 0;
                        res = helper(a, b, tempc);
                        if (res != '?') {
                            ans+=res;
                        }
                    }
                } // repeat end
                else {
                    res = helper(a, b, c);
                    if (res != '?') ans+=res;
                }
            } else {
                res = helper(a, b, c);
                if (res != '?') ans+=res;
            }
            if (res == '?') break;
        }
        return ans;
    }
};

int main() {
    return 0;
}