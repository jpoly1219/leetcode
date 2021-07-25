#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x) {
            int remainder = x % 10;
            if (abs(ans) > 214748364 || (abs(ans) == 214748364 && ((x > 0 && remainder > 7) || (x < 0 && remainder < -8)))) {
                return 0;
            }
            ans = ans*10 + remainder;
            x /= 10;
        }
        return ans;
    }
};

// -2147483648 to 2147483647