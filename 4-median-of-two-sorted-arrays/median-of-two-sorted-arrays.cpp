#include <vector>
#include <iostream>

using namespace std;

vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2);

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        
        vector<int> nums3 = mergeArrays(nums1, nums2);
        int arrayLength = nums3.size();
        if (arrayLength % 2 == 0) {
            int med1 = nums3.at((arrayLength / 2) - 1);
            int med2 = nums3.at(arrayLength / 2);
            median = (med1 + med2) / 2.0;
        }
        else if (arrayLength % 2 == 1) {
            median = nums3.at((arrayLength - 1) / 2);
        }
        else {
            cout << "error2" << endl;
        }
        return median;
    }
};

vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums3;
    while (nums1.size() > 0 && nums2.size() > 0) {
        if (nums1.at(0) < nums2.at(0)) {
            nums3.push_back(nums1.at(0));
            nums1.erase(nums1.begin());
        }
        else if (nums2.at(0) < nums1.at(0)) {
            nums3.push_back(nums2.at(0));
            nums2.erase(nums2.begin());
        }
        else if (nums1.at(0) == nums2.at(0)) {;
            nums3.push_back(nums1.at(0));
            nums3.push_back(nums1.at(0));
            nums1.erase(nums1.begin());
            nums2.erase(nums2.begin());
        }
        else {
            cout << "error1" << endl;
        }
    }
    if (nums1.size() == 0) {
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());
    }
    if (nums2.size() == 0) {
        nums3.insert(nums3.end(), nums1.begin(), nums1.end());
    }
    for(int i = 0; i < nums3.size(); i++) {
        cout << nums3[i] <<  " ";
    }
    cout << endl;
    return nums3;
}