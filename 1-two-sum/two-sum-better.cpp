#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a map that holds the nums as keys, and target-nums as value
        map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            table.insert({nums[i], i});
        }
        // if target-nums[i] == one of the keys, return key value pair
        int index1, index2;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(target-nums[i]) != table.end()) {
                index1 = i;
                index2 = table.find(target-nums[i])->second;
            }
        }

        vector<int> solution = {index1, index2};

        return solution;
        // the code should me maximum O(2n), which is much better than O(n^2)
    }
};