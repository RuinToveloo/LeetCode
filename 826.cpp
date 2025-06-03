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
private:
    void sort_func(vector<int> &difficulty, vector<int> &profit) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < n; i++) {
            difficulty[i] = jobs[i].first;
            profit[i] = jobs[i].second;
        }
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort_func(difficulty, profit);
        sort(worker.begin(), worker.end());

        int ans = 0, best = 0, j = 0;
        int n = difficulty.size();

        for (int skill : worker) {
            while (j < n && difficulty[j] <= skill) {
                best = max(best, profit[j]);
                j++;
            }
            ans += best;
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> difficulty = {13,37,58};
    vector<int> profit = {4,90,96};
    vector<int> worker = {34,73,45};

    int result = sol.maxProfitAssignment(difficulty, profit, worker);

    cout << "Result: " << result << endl;
    return 0;
}