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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e : redEdges) graph[e[0]].emplace_back(e[1], 0);
        for (const auto& e : blueEdges) graph[e[0]].emplace_back(e[1], 1);

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<tuple<int, int, int>> q;

        q.emplace(0, 0, -1);
        vector<int> ans(n, -1);
        ans[0] = 0;

        while (!q.empty()) {
            auto [node, steps, lastColor] = q.front(); q.pop();
            for (auto [nei, color] : graph[node]) {
                if (color != lastColor && !visited[nei][color]) {
                    visited[nei][color] = true;
                    q.emplace(nei, steps + 1, color);
                    if (ans[nei] == -1) ans[nei] = steps + 1;
                }
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;

    int n = 2;
    vector<vector<int>> redEdges = {{0,1},{1,0}};
    vector<vector<int>> blueEdges;

    vector<int> result = sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    for (int num: result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}