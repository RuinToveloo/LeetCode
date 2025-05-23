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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode *, int> l;
    int deepest = 0;

    void helper(TreeNode* now, int level, TreeNode *p) {
        if (now == nullptr) {
            deepest = max(deepest, level-1);
            return;
        }
        parent[now] = p;
        l[now] = level;
        helper(now->left, level+1, now);
        helper(now->right, level+1, now);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return root;
        helper(root, 0, nullptr);
        vector<TreeNode*> list;
        for (auto it: l) {
            if (it.second == deepest) {
                list.push_back(it.first);
            }
        }

        map<TreeNode *, int> findit;
        for (TreeNode *iter: list) {
            while (iter != nullptr) {
                findit[iter]++;
                iter = parent[iter];
            }
        }

        TreeNode *ans = root;
        int level = 0;

        for (auto it: findit) {
            if (it.second == list.size()) {
                if (l[it.first] > level) {
                    level = l[it.first];
                    ans = it.first;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}