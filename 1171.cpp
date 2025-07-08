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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int num) {
        val = num;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> l;
        ListNode *iter = head;
        while (iter != nullptr) {
            l.push_back(iter->val);
            iter = iter->next;
        }
        bool dowhile = true;
        while (l.size() != 0 && dowhile) {
            int n = l.size();
            bool change = false;
            for (int i = 0; i < n; i++) {
                int sum = 0;
                // start at i
                for (int j = i; j < n; j++) {
                    sum+=l[j];
                    if (sum == 0) {
                        // from i to j
                        change = true;
                        vector<int> ll;
                        for (int k = 0; k < i; k++) {
                            ll.push_back(l[k]);
                        }
                        for (int k = j+1; k < n; k++) {
                            ll.push_back(l[k]);
                        }
                        l = ll;
                        break;
                    }
                }
                if (change) {
                    break;
                }
            }
            if (!change) dowhile = false;
        }

        int index = 0;
        int n = l.size();
        if (n == 0) return nullptr;
        iter = head;
        while (index < n) {
            iter->val = l[index++];
            if (index == n) break;
            iter = iter->next;
        }
        iter->next = nullptr;
        return head;
    }
};

int main() {
    return 0;
}