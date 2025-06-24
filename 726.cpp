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
    map<string, int> hm;

    void helper(string s, int times) {
        cout << s << " " << times << endl;
        int n = s.size();
        if (n == 0) return;
        if (s[0] == '(') {
            int open = 1;
            string before = "";
            int index = -1;
            for (int i = 1; i < n; i++) {
                if (open == 0) {
                    index = i;
                    break; // (kg) --- 2 ---
                }
                if (s[i] == '(') open++;
                else if (s[i] == ')') open--;
                before+=s[i];
            }
            before.pop_back();
            if (index == -1) index = n-1;
            int num = 0;
            while (index < n) {
                if (s[index] >= '0' && s[index] <= '9') {
                    num = num * 10 + s[index] - '0';
                    index++;
                } else {
                    break;
                }
            }
            if (num == 0) num = 1;
            helper(before, times * num);
            string after = "";
            while (index < n) {
                after+=s[index++];
            }
            // cout << "after : " << after << endl;
            helper(after, times);
            return;
        }

        // s[0] != '('
        if (s[0] == ')' || !(s[0] >= 'A' && s[0] <= 'Z')) {
            return;
            cout << "ERROR" << endl;
        }

        string name = "";
        int index = 0;
        int num = 0;
        while (index < n) {
            if (s[index] >= 'A' && s[index] <= 'Z') {
                if (name == "") name+=s[index];
                else {
                    // having name: KgK or Kg2K
                    num = (num == 0) ? 1 : num;
                    hm[name] += num * times;
                    num = 0;
                    name = "";
                    name+=s[index];
                }
            } else if (s[index] >= 'a' && s[index] <= 'z') {
                name+=s[index];
            } else if (s[index] >= '0' && s[index] <= '9') {
                num = num * 10 + s[index] - '0';
            } else if (s[index] == '(') {
                if (name != "") {
                    num = (num == 0) ? 1 : num;
                    hm[name] += times * num;
                }
                name = "";
                num = 0;
                break;
            } else {
                cout << "WHY " << s[index] << endl;
                return;
            }
            index++;
        }
        if (name != "") {
            num = (num == 0) ? 1 : num;
            hm[name] += times * num;
        }
        string rem = "";
        while (index < n) {
            rem+=s[index++];
        }
        helper(rem, times);

    }

    string countOfAtoms(string formula) {
        helper(formula, 1);
        vector<string> vec;
        for (auto it: hm) {
            vec.push_back(it.first);
        }
        string ans = "";
        for (string s: vec) {
            ans+=s;
            if (hm[s] == 1) continue;
            ans+=to_string(hm[s]);
        }
        return ans;
    }
};

int main() {
    return 0;
}