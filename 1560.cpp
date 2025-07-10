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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        vector<int> line(n+1, 0);
        for (int i = 1; i < rounds.size(); i++) {
            int s = rounds[i-1];
            int e = rounds[i];
            if (s < e) {
                for (int j = s; j < e; j++) {
                    line[j]++;
                }
            } else {
                for (int j = s; j <= n; j++) {
                    line[j]++;
                }
                for (int j = 1; j < e; j++) {
                    line[j]++;
                }
            }
        }
        line[rounds[rounds.size()-1]]++;
        int maxi = 0;
        for (int num: line) {
            maxi = max(maxi, num);
        }
        for (int i = 1; i <= n; i++) {
            if (line[i] == maxi) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}