#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> res = {1, 2};
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (res.size() != n) {
            for (size_t i = 2; i < n; ++i) {
                res.push_back(res.at(i-1)+res.at(i-2));
            }
        }
        return res.back();
    }
};

/*
    n = 1 (n1) 1
    1

    n = 2 (n2) 2
    1+1, 2

    n = 3 (n3 = n1+n2) 3
    1+1+1, 1+2, 2+1

    n = 4 (n4 = n1+n3, n2+n2, n3+n1) 5
    1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2

    n = 5 (n5 = n1+n4, n2+n3, n3+n2, n4+n1) 8
    1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1

    is this a fibonacci sequence?
*/