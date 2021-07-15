#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substring = "";
        string newSubstring = "";
        int subStringLen = 0;
        char curr = s[0];
        int i = 0;
        for (i = 0; i < s.size(); i++) {
            curr = s[i];
            if (newSubstring.back() != curr) {
                newSubstring.push_back(curr);
            }
            else {
                break;
            }
        }
    }
};
/*
a b c a b c b b

for each letter in string {
    start = string[i];
    string substring = "";
    string newSubstring;
    int substrLen = 0;
    concat letters until the starting letter appears again.
    save that as a newSubstring and calculate its length.
    if newSubstring > substring {substring = newSubstring}
    check how many of this substring exist inside the full string.
    repeat until last character.
}

a in str
ab in str
abc in str
abca in str
abcab in str
abcabc in str
abcabc
*/