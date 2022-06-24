#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (size_t i = 0; i < floor(s.size()/2); i++) {
            char* front = &(s[i]);
            char* back = &(s[s.size()-1-i]);
            char tempBack = *back;
            char tempFront = *front;

            s[i] = tempBack;
            s[s.size()-1-i] = tempFront;
        }

        if (s.begin() == 0) {
            return;
        }
        s.begin()++;
        s.rbegin()++;
        reverseString(s);
        char temp1 = *s.begin();
        char temp2 = *s.rbegin();

        *s.begin() = temp2;
        *s.rbegin() = temp1;
    }
};

// h, e, l, l, o -> o, l, l, e, h