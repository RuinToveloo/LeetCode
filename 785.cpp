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
    private: 
        bool bfs(vector<vector<int>>& graph ,vector<int>&color,int start ){
            color[0] = 0 ;
            queue<int> q ; 
            q.push(start);
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
    
                for (auto it : graph[node]){
                    if (color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    } else if (color[node]==color[it]){
                        return false ; 
                    }
                }
            }
            return true ;
        }
    
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n,-1);
    
            for (int i = 0 ;i < n ;i++){
                if (bfs(graph,color, i) == false) {
                    return false ;
                }
            }
            return true;
        }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    
    int result = sol.isBipartite(graph);
    cout << "Result: " << result << endl;

    return 0;
}
