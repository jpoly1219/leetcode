#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i+1] == target) {
                output = {i, i + 1};
            }
        }
        return output;
    }
};