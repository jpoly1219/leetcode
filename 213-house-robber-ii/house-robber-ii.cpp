#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> numsL = nums;
        numsL.pop_back();
        
        vector<int> numsR = nums;
        numsR.erase(numsR.begin());

        vector<int> sumsL = {0, numsL[0]};
        vector<int> sumsR = {0, numsR[0]};
        
        for (size_t i = 1; i < numsL.size(); ++i) {
            sumsL.push_back(max(sumsL[i], sumsL[i-1]+numsL.at(i)));
        }
        for (size_t i = 1; i < numsR.size(); ++i) {
            sumsR.push_back(max(sumsR[i], sumsR[i-1]+numsR.at(i)));
        }
        return max(sumsL.back(), sumsR.back());
    }
};