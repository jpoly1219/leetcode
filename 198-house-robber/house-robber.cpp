#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // int pre = 0;
        // int cur = 0;
        // for (size_t i = 0; i < nums.size(); ++i) {
        //     int temp = max(pre + nums.at(i), cur);
        //     pre = cur;
        //     cur = temp;
        // }
        // return cur;

        // initialize memo
        // 0 when there are no houses to rob, nums[0] when there is only one house to rob.
        // as we loop over nums, max for each iteration will be added.
        vector<int> sums = {0, nums[0]};

        // we already checked for i = 0, so start with i = 1
        for (size_t i = 1; i < nums.size(); ++i) {
            // is it better to use the previous max or the current max?
            sums.push_back(max(sums[i], sums[i-1]+nums.at(i)));
        }
        return sums.back();
    }
};