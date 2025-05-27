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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> line(n, 0);
        for (vector<int> l: roads) {
            line[l[0]]++;
            line[l[1]]++;
        }
        auto cmp = [](vector<int>& l1, vector<int>& l2) {
            return l1[1] < l2[1];  // max-heap based on second element
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            pq.push({i, line[i]});
        }
        map<int, int> hm; // index to value
        int use = n;
        while (pq.size()) {
            vector<int> l = pq.top();
            pq.pop();
            int index = l[0];
            hm[index] = use;
            use--;
        }

        long long ans = 0;
        for (vector<int> l: roads) {
            ans+=hm[l[0]];
            ans+=hm[l[1]];
        }


        return ans;
    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};

    long long result = sol.maximumImportance(n, roads);

    cout << "Result: " << result << endl;
    return 0;
}