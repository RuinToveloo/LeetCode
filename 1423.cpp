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
        int maxScore(vector<int>& cardPoints, int k) {
            vector<int> right;
            vector<int> left;
            int n = cardPoints.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum+=cardPoints[i];
                left.push_back(sum);
            }
            sum = 0;
            for (int i = n-1; i >= 0; i--) {
                sum+=cardPoints[i];
                right.push_back(sum);
            }
            sum = max(left[k-1], right[k-1]);
            for (int i = 0; i < k-1; i++) {
                sum = max(sum, left[i] + right[k-2-i]);
            }
            return sum;
        }
};

int main() {
    Solution sol;
    int k = 3;
    vector<int> points = {1,2,3,4,5,6,1};
    int result = sol.maxScore(points, k);
    cout << "Result: " << result << endl;

    return 0;
}
