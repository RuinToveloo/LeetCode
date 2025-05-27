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
    struct Node {
        int val;
        vector<Node*> child;

        Node(int v) {
            val = v;
            child = {};
        }
    };

    int dfs(Node* now, const int k, int &ans) {
        if (now == nullptr) {
            cout << "ERROR" << endl;
            return -1;
        }
        int sum = 0;
        for (Node* kid: now->child) {
            sum+=dfs(kid, k, ans);
        }
        sum+=now->val;
        sum %= k;
        if (sum == 0) ans++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<Node*> list;
        for (int num: values) {
            Node *now = new Node(num);
            list.push_back(now);
        }
        map<Node*, vector<Node*>> hm;
        for (vector<int> line: edges) {
            hm[list[line[0]]].push_back(list[line[1]]);
            hm[list[line[1]]].push_back(list[line[0]]);
        }
        queue<pair<Node*, Node*>> q;
        q.push({list[0], nullptr});

        while (!q.empty()) {
            auto [now, parent] = q.front();
            q.pop();

            for (Node* neighbor : hm[now]) {
                if (neighbor != parent) {
                now->child.push_back(neighbor);
                q.push({neighbor, now});
            }
        }
    }
        /* Tree Building Done */
        int res = dfs(list[0], k, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    int n  = 5;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    int k = 6;

    int result = sol.maxKDivisibleComponents(n, edges, values, k);

    cout << "Result: " << result << endl;
    return 0;
}