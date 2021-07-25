#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string myString = "";
        if (s == "") {
            return 0;
        }
        // read in and ignore any leading whitespace
        while (s != "") {
            if (s.at(0) == ' ') {
                s.erase(0, 1);
            }
            else {
                break;
            }
        }
        
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            if (*it == '-' || *it == '+') {
                if (it != s.begin()) {
                    break;
                }
                myString.push_back(*it);
                it++;
            }

            if ((int)*it >= 48 && (int)*it <= 57) {
                myString.push_back(*it);
            }
            else {
                break;
            }
        }

        // at this point a pre-formatted myString should've been made
        int ans = 0;
        bool sign = true;
        for (string::iterator it = myString.begin(); it != myString.end(); it++) {
            if (*it == '-') {
                sign = false;
                it++;
            }
            else if (*it == '+') {
                sign = true;
                it++;
            }
            int digit = *it - '0';
            if (digit < 0) {
                return 0;
            }
            if (abs(ans) > 214748364 && sign) {
                return 2147483647;
            }
            else if (abs(ans) > 214748364 && !sign) {
                return -2147483648;
            }
            else if (abs(ans) == 214748364 && (sign && digit > 7)) {
                return 2147483647;
            }
            else if (abs(ans) == 214748364 && (!sign && digit >= 8)) {;
                return -2147483648;
            }
            ans = ans*10 + digit;
        }

        if (!sign) {
            return -1 * ans;
        }
        return ans;
    }
};