#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int remainder = 0;
        vector<int> remainders;

        int y = x;
        if (y < 0) {
            y *= -1;
        }
        if (y == 0) {
            return 0;
        }
        while (y >= 1) {
            remainder = y % 10;
            remainders.push_back(remainder);
            y /= 10;
        }

        // delete leading zeros
        for (auto it = remainders.rbegin(); it != remainders.rend(); it++) {
            if (*it == 0) {
                remainders.erase(remainders.begin());
            }
            else {
                break;
            }
        }


        vector<int> max = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        vector<int> min = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
        int i = 0;
        int count = 0;
        if (remainders.size() == 10) {
            for (auto it = remainders.rbegin(); it != remainders.rend(); it++) {
                
            }
        }
    }
};