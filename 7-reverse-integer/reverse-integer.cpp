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
            remainders.push_back(0);
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

        
    }
};