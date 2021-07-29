#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
    }
};

/*
s = aa, p = a
if (s == p && "* or . doesn't exist at all") {
    return true;
}

// we can have two indices: one for s and the other for p

while (indexP != p.end() && indexS != s.end()) {
    // indexP moves first, and if there is no * or ., indexS moves.
    if (* exists at indexP) {

        // get character at indexP-1 and indexS;
        // * is guaranteed to have a character to repeat, aka will never be at p.begin();
        char pBefore = p.at(indexP-1);
        char sCurr = p.at(indexS);

        // if pBefore == ., skip and move on;

        // if equal, keep incrementing indexS until different character is found;
        char sNew = '';
        if (pBefore == sCurr) {
            while (sNew == sCurr) {
                sNew = p.at(indexS);
                indexS++;
            }
        }
        else {
            return false;
        }

        // when the different character is found, increment indexP by one and get the character;
        indexP++;
        char pCurr = p.at(indexP);
        if (sNew == pCurr) {
            // ok
        }
        else {
            return false;
        }
    }

    else if (. exists at indexP) {
        // if previous substring of p matches the previous substring of s, return true;
        if (p.substring(0, indexP) == s.substring(0, indexP)) {
            return true;
        }
    }

    else {
        if (indexS != s.begin()) {
            indexS++;
        }
    }

    indexP++;
}

return true;

*/