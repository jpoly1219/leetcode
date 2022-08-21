#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> combo[nums.size()];
        int maximum = 0;
        int counter = 0;
        for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
            if (counter == 0) {
                combo[0].push_back(*i);
                maximum = *i;
            }
            if (counter >= 1) {
                int currMax = *i;
                combo[counter].push_back(*i);
                int prev = *i+combo[counter-1].back();
                if (currMax != max(currMax, prev)) {
                    currMax = prev;
                    combo[counter].push_back(prev);
                }

                maximum = max(maximum, currMax);
            }
            counter++;
        }
        return maximum;
    }
};