#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> total = {0, 0};

        for (size_t i = 2; i <= n; ++i) {
            total.push_back(min(total.at(i-1) + cost.at(i-1), total.at(i-2) + cost.at(i-2)));
        }
        return total.at(n);

        // cost.insert(cost.begin(), 0);
        // if (cost.size() == 2) {
        //     return cost.at(1);
        // }
        // if (cost.size() == 3) {
        //     return cost.at(2);
        // }
        // if (cost.size() >= 4) {
        //     int total = cost.at(0);
        //     vector<int> subVec1 {cost.begin()+1, cost.end()};
        //     vector<int> subVec2 {cost.begin()+2, cost.end()};
        //     int res1 = minCostClimbingStairs(subVec1);
        //     int res2 = minCostClimbingStairs(subVec2);
        //     if (res1 > res2) {
        //         return total + res2;
        //     } else {
        //         return total + res1;
        //     }
        // }
        // return 0;
    }
};

/*
    think of the cost array as a stair, where each item is a staircase.
    you can climb at most once or twice.
    
    - start
    - check the cost of going up once and twice.
    - go with the minimum cost.
    - repeat the above three steps.
    - check for null so that you aren't going out of bound at the end.

    ^ this method has a caveat: [0,1,2,2] results in 3 when it should end in 2.
    - int total
    - at each step, comapre recursive calls minCost(vec[i+1:])) and minCost(vec[i+2:]) and add to total the smallest number.
*/