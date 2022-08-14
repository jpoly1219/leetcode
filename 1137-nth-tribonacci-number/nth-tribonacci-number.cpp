#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        // recursion alone makes the algorithm too slow.
        // we need to use dynamic programming.
        vector<int> res = {0, 1, 1};
        
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        if (n > res.size()) {
            for (int i = 3; i < n; i++) {
                res.push_back(res.at(i-3) + res.at(i-2) + res.at(i-1));   
            }
        }
        
        return res.at(n-3) + res.at(n-2) + res.at(n-1);
        
        // t3 = t0 + t1 + t2
        // t4 = t1 + t2 + t3
        // t5 = t2 + t3 + t4
        // t6 = t3 + t4 + t5
        
        // if (n == 0) {
            // return 0;
        // }
        // if (n == 1) {
            // return 1;
        // }
        // if (n == 2) {
            // return 1;
        // }
        // if (n == 3) {
            // return 2;
        // }
        // if (n == 4) {
            // return 4;
        // }
        // return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};