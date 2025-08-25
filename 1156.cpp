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
    void helper(vector<char> vec, vector<int> line, int &ans) {
        int n = vec.size();
        for (int i = 0; i < n-1; i++) {
            int sum = line[i];
            if (line[i+1] == 1 && i+2 < n && vec[i+2] == vec[i]) {
                bool find = false;
                int j = n-1;
                while (j > i+2) {
                    if (vec[j] == vec[i]) {
                        find = true;
                        break;
                    }
                    j--;
                }
                if (find) {
                    ans = max(ans, line[i] + line[i+2] + 1);
                } else {
                    ans = max(ans, line[i] + line[i+2]);
                }
            }
            else /*if (line[i+1] != 1) */{
                bool find = false;
                int j = n-1;
                while (j > i+1) {
                    if (vec[j] == vec[i]) {
                        find = true;
                        break;
                    }
                    j--;
                }
                if (find) {
                    ans = max(ans, line[i] + 1);
                }
            }
            // cout << i << " " << ans << endl;
        }
    }


    int maxRepOpt1(string text) {
        int n = text.size();
        char c = text[0];
        int count = 1;
        vector<char> vec;
        vector<int> line;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (text[i] == c) {
                count++;
                continue;
            } else {
                ans = max(ans, count);
                vec.push_back(c);
                line.push_back(count);
                count = 1;
                c = text[i];
            }
        }
        ans = max(ans, count);
        vec.push_back(c);
        line.push_back(count);

        helper(vec, line, ans);
        reverse(vec.begin(), vec.end());
        reverse(line.begin(), line.end());
        helper(vec, line, ans);
        return ans;
    }
};

int main() {
    return 0;
}