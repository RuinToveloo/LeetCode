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
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = -1, totalWeight = 0;
        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight = totalWeight + weight;
        }
        while (maxWeight < totalWeight) {
            int midWeight = maxWeight + (totalWeight - maxWeight) / 2;
            int daysNeeded = 1, currWeight = 0;
            for (int weight : weights) {
                if (currWeight + weight > midWeight) {
                    daysNeeded++;
                    currWeight = 0;
                }
                currWeight = currWeight + weight;
            }
            if (daysNeeded > days) {
                maxWeight = midWeight + 1;
            } else {
                totalWeight = midWeight;
            }
        }
        return maxWeight;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int result = sol.getWordsInLongestSubsequence(weights, 5);
    cout << result << endl;

    return 0;
}
