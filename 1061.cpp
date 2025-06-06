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

class DisjointSet{
    vector<int>parent,size;
 public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
	}
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] =findPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int up = findPar(u); 
        int uv = findPar(v); 
        if(up == uv) return; 
        if(up < uv) {
            parent[uv] = up; 
        }
        else {
            parent[up] = uv;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DisjointSet ds(26);
        for(int i=0;i<n;i++){
            ds.unionBySize(s1[i]-'a',s2[i]-'a');
        }
        string res="";
        for(int i=0;i<baseStr.size();i++){
            res+=(char)(ds.findPar(baseStr[i]-'a')+'a');
        }
        return res;
    }
};

int main() {
    Solution sol;

    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";

    string result = sol.smallestEquivalentString(s1, s2, baseStr);

    cout << "Result: " << result << endl;
    return 0;
}