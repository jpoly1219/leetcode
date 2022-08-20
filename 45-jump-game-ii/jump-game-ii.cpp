#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = 0;
        vector<int> count[nums.size()];

        if (nums.size() == 1) {
            return 0;
        } else if (nums.size() == 2) {
            return 1;
        } else {
            for (size_t i = 0; i < nums.size()-1; ++i) {
                if (i == 0) {
                    count[0].push_back(0);
                }
                dest = i + nums.at(i);
                if (dest >= nums.size()-1) {
                    return count[i].at(0)+1;
                }
                int newStep = count[i].at(0)+1;
                for (size_t j = i+1; j < dest+1; ++j) {
                    count[j].push_back(newStep);
                }
            }
        }

        return 0;
    }
};