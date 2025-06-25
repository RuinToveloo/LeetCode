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

class ThroneInheritance {
public:

    struct Node {
        string name;
        vector<Node *> child;
        int status;
    
        Node(string str) {
            name = str;
            status = 1;
        }
    };

    unordered_map<string, Node*> hm;
    Node *root;

    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        hm[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node *now = new Node(childName);
        hm[parentName]->child.push_back(now);
        hm[childName] = now;
    }
    
    void death(string name) {
        hm[name]->status = -1;
    }

    void helper(Node *now, vector<string> &ans) {
        if (now == nullptr) return;
        if (now->status == 1) ans.push_back(now->name);
        for (Node *next: now->child) {
            helper(next, ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main() {
    return 0;
}