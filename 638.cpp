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
    int shoppingOffers(vector<int>& price, vector<vector<int>>& offers, vector<int>& needs) {
        int n = price.size();
        int ans = INT_MAX;
        queue<pair<int, vector<int>>> q;
        q.push({0, needs});
        set<pair<int, vector<int>>> st;
        while (q.size()) {
            pair<int, vector<int>> p = q.front();
            q.pop();
            if (st.find(p) == st.end()) continue;
            st.insert(p);
            int money = p.first;
            vector<int> temp = p.second;
            int total_need = 0;
            for (int item: temp) {
                total_need+=item;
            }
            if (total_need == 0) {
                ans = min(money, ans);
                continue;
            }

            // check offers
            for (vector<int> off: offers) {
                bool cando = true;
                for (int i = 0; i < n; i++) {
                    if (off[i] > temp[i]) {
                        cando = false;
                        break;
                    }
                }
                if (cando) {
                    vector<int> ll = temp;
                    for (int i = 0; i < n; i++) {
                        ll[i]-=off[i];
                    }
                    q.push({money+off[n], ll});
                }
            }

            // check original price
            for (int i = 0; i < n; i++) {
                money+=(temp[i] * price[i]);
            }
            ans = min(money, ans);
        }
        return ans;
    }
};


int main() {
    return 0;
}