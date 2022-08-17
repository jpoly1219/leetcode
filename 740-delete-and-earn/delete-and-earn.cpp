#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        vector<int> newNums;
        for (auto i : nums) {
            if (count.find(i) == count.end()) {
                count.insert(make_pair(i, 1));
                newNums.push_back(i);
            } else {
                count.at(i) += 1;
            }
        }
        sort(newNums.begin(), newNums.end());

        vector<int> dp = {};

        for (size_t i = 0; i < newNums.size(); ++i) {
            if (i == 0) {
                dp.push_back(newNums.at(i) * count.at(newNums.at(i)));
            }
            if (i == 1) {
                int temp = newNums.at(i) * count.at(newNums.at(i));
                if (newNums.at(i) != newNums.at(i-1)-1 && newNums.at(i) != newNums.at(i-1)+1) {
                    temp += dp[i-1];
                }
                dp.push_back(max(dp[i-1], temp));
            }
            if (i >= 2) {
                int temp = newNums.at(i) * count.at(newNums.at(i));
                if (newNums.at(i) != newNums.at(i-1)-1 && newNums.at(i) != newNums.at(i-1)+1) {
                    temp += dp[i-1];
                } else {
                    temp += dp[i-2];
                }
                dp.push_back(max(dp[i-1], temp));
            }
        }
        return dp.back();
    }
};