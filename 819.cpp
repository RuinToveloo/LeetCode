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
    string to_lower(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = (s[i] - 'A' + 'a');
            }
        }
        return s;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph = to_lower(paragraph);
        set<string> ban;
        for (string s: banned) {
            ban.insert(s);
        }
        string s = "";
        map<string, int> hm;
        for (char c: paragraph) {
            if (c == ' ' || c == '!' || c == '?' || c == ',' || c == ';' || c == '.' || c == '\'') {
                if (s == "" || ban.contains(s)) {
                    s = "";
                    continue;
                }
                hm[s]++;
                s = "";
            } else {
                s+=c;
            }
        }
        if (s != "" && !ban.contains(s)) hm[s]++;
        string ans = "";
        int count = -1;
        for (auto it: hm) {
            cout << it.first << " " << it.second << endl;
            if (it.second > count) {
                count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}