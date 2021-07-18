#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows[numRows];
        int strIndex = 0;

        while (strIndex < s.size()) {
            for (int i = 0; i < numRows; i++) {
                if (strIndex == s.size()) {
                    break;
                }
                rows[i].push_back(s.substr(strIndex, 1));
                strIndex++;
            }
            for (int i = numRows-2; i >= 1; i--) {
                if (strIndex == s.size()) {
                    break;
                }
                rows[i].push_back(s.substr(strIndex, 1));
                strIndex++;
            }
        }
        string final = "";
        for (int i = 0; i < numRows; i++) {
            for (auto j : rows[i]) {
                final += j;
            }
        }

        return final;
    }
};

// row1, row2, row3, row4
// have an iterator that goes back and forth?
/*
vector<char> rows[numRows];
int strIndex = 0;

while (strIndex < s.size()) {
    for (int i = 0; i < numRows; i++) {
        rows[i].push_back(s[strIndex]);
        strIndex++;
    }
    for (int i = 0; i < numRows-1; i++) {
        rows[numRows-i-2].push_back(s[strIndex]);
        strIndex++;
    }
}
string final = "";
for (int i = 0; i < numRows; i++) {
    for (auto j : rows[i]) {
        final.push_back(j);
    }
}

return final;
*/