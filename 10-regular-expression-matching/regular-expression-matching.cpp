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

while (indexP == p.end() && indexS == s.end()) {
    // indexP moves first, and if there is no * or ., indexS moves.
    if (* exists at indexP) {
        if (indexP == p.begin()) {
            return false;
        }

        // get character at indexP-1 and indexS;
        char pBefore = p.at(indexP-1);
        char sCurr = p.at(indexS);

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

    if (. exists at indexP) {

    }
    else {
        return false;
    }

    indexP++;
}

return true;

*/