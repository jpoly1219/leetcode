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

when * appears, get its index, and look at the character at index-1.

we can have two indices: one for s and the other for p
iP moves first, and if there is no * or ., iS moves.
if (* or . exists) {
    
}

*/