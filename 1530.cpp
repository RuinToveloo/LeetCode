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
    public:
        map<TreeNode*, TreeNode*> t;
        void dfs1(map<TreeNode*, TreeNode*> &t, TreeNode* now, vector<TreeNode*> &lfs) {
            if (now == nullptr) return;
            if (now->left == nullptr && now->right == nullptr) {
                // leaf
                lfs.push_back(now);
                return;
            }
            if (now->left != nullptr) {
                t[now->left] = now;
            }
            if (now->right != nullptr) {
                t[now->right] = now;
            }
            dfs1(t, now->left, lfs);
            dfs1(t, now->right, lfs);
        }
    
        void dfs2(TreeNode *now, 
                 int distance, int &ans, TreeNode* last) {
                if (now == nullptr) return;
                if (distance < 0) return;
                if (now->left == nullptr && now-> right == nullptr) {
                    ans++;
                    return;
                }
                if (t[now] != last) {
                    dfs2(t[now], distance-1, ans, now);
                }
                if (now->left != last) {
                    dfs2(now->left, distance-1, ans, now);
                }
                if (now->right != last) {
                    dfs2(now->right, distance-1, ans, now);
                }
            }
    
        int countPairs(TreeNode* root, int distance) {
            int ans = 0;
            vector<TreeNode*> lfs;
            TreeNode *iter = root;
            t[root] = nullptr;
            dfs1(t, root, lfs);
            for (TreeNode* now : lfs) {
                // now is the leaf
                dfs2(t[now], distance-1, ans, now);
            }
            return ans / 2;
        }
};    

int main() {
    return 0;
}
