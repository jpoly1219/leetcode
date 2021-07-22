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
    }
};