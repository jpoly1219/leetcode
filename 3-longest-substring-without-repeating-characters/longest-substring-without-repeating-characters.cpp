#include <string>

using namespace std;

string findSubstr(int index, string s);

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        string substring = "";
        string newSubstring = "";
        while (index < s.size()) {
            newSubstring = findSubstr(index, s);
            if (newSubstring.length() > substring.length()) {
                substring = newSubstring;
            }
            index++;
        }
        return substring.length();
    }
};

string findSubstr(int index, string s) {
    string newSubstring = "";
    int subStringLen = 0;
    char curr = s[index];
    for (int i = index; i < s.size(); i++) {
        curr = s[i];
        if (newSubstring != "" && newSubstring.find(curr) != string::npos) {
            return newSubstring;
        }
        else {
            newSubstring.push_back(curr);
        }
    }
    return newSubstring;
}