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
    struct Flower {
        int plantTime;
        int growTime;
        Flower(int plant, int grow) {
            plantTime = plant;
            growTime = grow;
        }
    };

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<Flower> list;
        for (int i = 0; i < n; i++) {
            list.push_back(Flower(plantTime[i], growTime[i]));
        }

        sort(list.begin(), list.end(), [&](Flower f1, Flower f2) {
            return f1.growTime > f2.growTime;
        });

        int now = 0;
        int ans = 0;
        for (Flower flower: list) {
            now+=flower.plantTime;
            int bloom = now + flower.growTime;
            ans = max(ans, bloom);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> plantTime = {1, 4, 3};
    vector<int> growTime  = {2, 3, 1};

    int result = sol.earliestFullBloom(plantTime, growTime);
    cout << "Result: " << result << endl;
    return 0;
}