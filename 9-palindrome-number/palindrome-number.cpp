#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x%10 == x) {
            return true;
        }

        vector<int> digits = {};
        while (true) {
            int digit = x % 10;
            digits.push_back(digit);
            if (x/10 == 0) {
                break;
            }
            x /= 10;
        }
        
        vector<int>::iterator revPtr = digits.end()-1;
        for (auto i = digits.begin(); i != digits.end(); ++i) {
            if (*i != *revPtr) {
                return false;
            }
            if (distance(i, revPtr) == 0) {
                return true;
            }
            if (distance(i, revPtr) == 1) {
                return true;
            }
            revPtr--;
        }

        return false;
    }
};