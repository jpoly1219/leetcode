#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp;
        if (nums.size() == 1) {
            dp.push_back(0);
        } else {
            for (size_t i = 0; i < nums.size()-1; ++i) {
                if (i == 0) {
                    if (nums.at(i) == 0) {
                        return false;
                    }
                    dp.push_back(i + nums.at(i));
                }
                if (i > 0) {
                    int currMax = i + nums.at(i);
                    if (dp.at(i-1) < i) {
                        return false;
                    }
                    dp.push_back(max(dp.at(i-1), currMax));
                }
            }
        }

        if (dp.back() >= nums.size()-1) {
            return true;
        } else {
            return false;
        }
    }
};