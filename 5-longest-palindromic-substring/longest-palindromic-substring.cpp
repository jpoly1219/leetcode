// works
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string final = "";
        
        for (int i; i < s.size(); i++) {
            string prevSubstrOdd = "";
            string prevSubstrEven = "";
            string newSubstr = "";
            int offset = 0;
            while (i - offset >= 0 && i + offset < s.size()) {
                newSubstr = s.substr(i - offset, offset*2 + 1);
                if(newSubstr.front() == newSubstr.back()) {
                    prevSubstrOdd = newSubstr;
                }
                else {
                    break;
                }
                offset++;
            }
            
            newSubstr = "";
            offset = 0;
            while (i - offset >= 0 && i + 1 + offset < s.size()) {
                newSubstr = s.substr(i - offset, offset*2 + 2);
                if(newSubstr.front() == newSubstr.back()) {
                    prevSubstrEven = newSubstr;
                }
                else {
                    break;
                }
                offset++;
            }
            
            if (prevSubstrOdd.size() > prevSubstrEven.size()) {
                if (prevSubstrOdd.size() > final.size()) {
                    final = prevSubstrOdd;
                }
            }
            else {
                if (prevSubstrEven.size() > final.size()) {
                    final = prevSubstrEven;
                }
            }
        }
        return final;
    }
};
// v3
#include <string>

using namespace std;

bool checkPalindrome(string *newSubstr);

class Solution {
public:
    string longestPalindrome(string s) {
        string final = "";
        
        for (int i; i < s.size(); i++) {
            string prevSubstrOdd = "";
            string prevSubstrEven = "";
            string newSubstr = "";
            int offset = 0;
            while (i - offset >= 0 && i + offset < s.size()) {
                newSubstr = s.substr(i - offset, offset*2 + 1);
                bool isPalindrome = checkPalindrome(&newSubstr);
                if (isPalindrome) {
                    prevSubstrOdd = newSubstr;
                }
                else {
                    break;
                }
                offset++;
            }
            
            newSubstr = "";
            offset = 0;
            while (i - offset >= 0 && i + 1 + offset < s.size()) {
                newSubstr = s.substr(i - offset, offset*2 + 2);
                bool isPalindrome = checkPalindrome(&newSubstr);
                if (isPalindrome) {
                    prevSubstrEven = newSubstr;
                }
                else {
                    break;
                }
                offset++;
            }
            
            if (prevSubstrOdd.size() > prevSubstrEven.size()) {
                if (prevSubstrOdd.size() > final.size()) {
                    final = prevSubstrOdd;
                }
            }
            else {
                if (prevSubstrEven.size() > final.size()) {
                    final = prevSubstrEven;
                }
            }
        }
        return final;
    }
};

bool checkPalindrome(string *newSubstr) {
    if (newSubstr->front() == newSubstr->back()) {
        return true;
    }
    return false;
}
// v2
#include <string>

using namespace std;

bool checkPalindrome(string substring, string curr);

class Solution {
public:
    string longestPalindrome(string s) {
        string final = "";
        string substring = "";
        string newSubstring = "";
        while (s.size() != 0) {
            for (string::iterator it = s.begin(); it != s.end(); it++) {
                newSubstring.push_back(*it);
                bool isPalindrome = checkPalindrome(newSubstring, substring);
                if (isPalindrome) {
                    if (newSubstring.size() > substring.size()) {
                        substring = newSubstring;
                    }
                }
            }
            if (substring.size() > final.size()) {
                final = substring;
            }
            substring = "";
            newSubstring = "";
            s.erase(0, 1);
        }
        return final;
    }
};

bool checkPalindrome(string substring, string curr) {
    if (substring.find(curr) > 0 && substring.find(curr) < substring.size()-1) {
        size_t pos = substring.find(curr);
        if (pos != string::npos) {
            substring.erase(pos, curr.size());
        }
    }

    int low = 0;
    int high = substring.size() - 1;
    while (low < high) {
        if (substring[low] != substring[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
// v1
#include <string>

using namespace std;

bool checkPalindrome(string substring, string curr);

class Solution {
public:
    string longestPalindrome(string s) {
        string substring = "";
        string newSubstring = "";
        while (s.size() != 0) {
            for (string::iterator it = s.begin(); it != s.end(); it++) {
                newSubstring.push_back(*it);
                bool isPalindrome = checkPalindrome(newSubstring, substring);
                if (isPalindrome) {
                    if (newSubstring.size() > substring.size()) {
                        substring = newSubstring;
                    }
                }
            }
            newSubstring = "";
            s.erase(0, 1);
        }
        return substring;
    }
};

bool checkPalindrome(string substring, string curr) {
    size_t pos = substring.find(curr);
    if (pos != string::npos) {
        substring.erase(pos, curr.size());
    }

    int low = 0;
    int high = substring.size() - 1;
    while (low < high) {
        if (substring[low] != substring[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

// removing a palindrome from a substring would still make it a palindrome

/* Better, but Inefficient Solution 2
#include <string>
#include <iostream>

using namespace std;

bool checkPalindrome(string *substring);

class Solution {
public:
    string longestPalindrome(string s) {
        string substring = "";
        string newSubstring = "";
        while (s.size() != 0) {
            for (string::iterator it = s.begin(); it != s.end(); it++) {
                newSubstring.push_back(*it);
                bool isPalindrome = checkPalindrome(&newSubstring);
                if (isPalindrome) {
                    if (newSubstring.size() > substring.size()) {
                        substring = newSubstring;
                    }
                }
            }
            newSubstring = "";
            s.erase(s.begin());
        }
        return substring;
    }
};

bool checkPalindrome(string *substring) {
    string firstHalf = "";
    string secondHalf = "";
    string reverse = "";
    size_t strSize = substring->size();
    if (strSize % 2 == 0) {
        firstHalf = substring->substr(0, strSize/2);
        secondHalf = substring->substr(strSize/2, string::npos);
        for (string::reverse_iterator itr = secondHalf.rbegin(); itr != secondHalf.rend(); itr++) {
            reverse.push_back(*itr);
        }
    }
    if (strSize % 2 == 1) {
        firstHalf = substring->substr(0, ((strSize - 1) / 2));
        secondHalf = substring->substr((strSize / 2) + 1, string::npos);
        for (string::reverse_iterator itr = secondHalf.rbegin(); itr != secondHalf.rend(); itr++) {
            reverse.push_back(*itr);
        }
    }

    if (firstHalf == reverse) {
        return true;
    }
    else {
        return false;
    }
}

inefficient solution 1
#include <string>
#include <iostream>

using namespace std;

bool checkPalindrome(string substring);

class Solution {
public:
    string longestPalindrome(string s) {
        // for each letter in s, create substrings by concatenating next letters
        // check if they are palindromic by running checkPalindrome
        // save it to a variable
        // when new palindromes appear, compare their lengths and replcae if necessary
        string substring = "";
        string newSubstring = "";
        while (s.size() != 0) {
            for (string::iterator it = s.begin(); it != s.end(); it++) {
                newSubstring.push_back(*it);
                bool isPalindrome = checkPalindrome(newSubstring);
                if (isPalindrome) {
                    if (newSubstring.size() > substring.size()) {
                        substring = newSubstring;
                    }
                }
            }
            newSubstring = "";
            s.erase(s.begin());
        }
        return substring;
    }
};

bool checkPalindrome(string substring) {
    string reverse = "";
    for (string::reverse_iterator itr = substring.rbegin(); itr != substring.rend(); itr++) {
        reverse.push_back(*itr);
    }
    if (substring == reverse) {
        return true;
    }
    else {
        return false;
    }
}
*/