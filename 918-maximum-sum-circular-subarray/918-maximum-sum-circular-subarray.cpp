#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> newNums = nums;
        for (size_t i = 0; i < nums.size()-1; ++i) {
            newNums.push_back(newNums.at(i));
        }
        int numsSum = 0;
        for (auto i : nums) {
            numsSum += i;
        }

        int currMax = findMaxSum(nums);
        if (currMax == numsSum) {
            return currMax;
        }

        for (size_t i = 1; i < (newNums.size()-nums.size())+1; ++i) {
            // vector<int> subvector(newNums.begin()+i, newNums.begin()+i+nums.size());
            currMax = max(currMax, max(currMax+nums.at(i-1), nums.at(i-1)));
        }
        return currMax;
    }

    int findMaxSum(vector<int>& nums) {
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