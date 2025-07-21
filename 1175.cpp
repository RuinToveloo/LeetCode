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
    int MOD = 1e9 + 7;

    bool isprime(int k) {
        if (k == 1) return false;
        for (int i = 2; i < k; i++) {
            if (k % i == 0) return false;
        }
        return true;
    }


    long long fac(int n) {
        long long ans = 1;
        for (int i = n; i >= 1; i--) {
            ans *= i;
            ans %= MOD;
        }
        return (int)ans;
    }

    int numPrimeArrangements(int n) {
        int prime = 0;
        for (int i = 1; i <= n; i++) {
            if (isprime(i)) prime++;
        }
        int p = fac(prime);
        int np = fac(n - prime);
        long long ans = (fac(prime) * fac(n - prime))  %  MOD;
        return ans;
    }
};

int main() {
    return 0;
}