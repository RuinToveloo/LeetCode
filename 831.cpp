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
    string isPhone(string s) {
        int n = s.size();
        if (n == 10) {
            s.insert(s.begin() + 3, '-');
            s.insert(s.begin() + 7, '-');
        }
        if (n == 11) {
            s.insert(s.begin(), '+');
            s.insert(s.begin() + 2, '-');
            s.insert(s.begin() + 6, '-');
            s.insert(s.begin() + 10, '-');
        }
        if (n == 12) {
            s.insert(s.begin(), '+');
            s.insert(s.begin() + 3, '-');
            s.insert(s.begin() + 7, '-');
            s.insert(s.begin() + 11, '-');
        }

        if (n == 13) {
            s.insert(s.begin(), '+');
            s.insert(s.begin() + 4, '-');
            s.insert(s.begin() + 8, '-');
            s.insert(s.begin() + 12, '-');
        }
        bool cando = false;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '-') cando = true;
            if (cando && s[i] >= '0' && s[i] <= '9') {
                s[i] = '*';
            }
        }
        return s;
    }


    string isMail(string s) {
        int index = -1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '@') {
                index = i;
                break;
            }
        }
        string ans = "";
        ans+=s[0];
        for (int i = 0; i < 5; i++) {
            ans+="*";
        }
        for (int i = index-1; i < n; i++) {
            ans+=s[i];
        }
        return ans;
    }


    string maskPII(string s) {
        bool phone = true;
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            } else if (s[i] == '@') {
                phone = false;
            } else if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == ' ') {
                s.erase(s.begin() + i);
                i--;
            }
        }
        if (phone) return isPhone(s);
        return isMail(s);
    }
};

int main() {
    return 0;
}