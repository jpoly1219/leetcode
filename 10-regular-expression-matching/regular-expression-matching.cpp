#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // recursion

        // simple case without a star
        cout << s << " " << p << endl;
        if (p == "") {
            return (s.length() == 0);
        }
        bool firstMatch = false;
        if (s != "" && (s.at(0) == p.at(0) || p.at(0) == '.')) {
            firstMatch = true;
        }

        if (p.length() >= 2 && p.at(1) == '*') {
            return (isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p)));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
        

        // string::iterator sItr = s.begin();
        // string::iterator pItr = p.begin();
        // bool hasStar = false;

        // while (pItr != p.end() && sItr != s.end()) {
        //     if (*sItr == *pItr) {
        //         pItr++;
        //         sItr++;
        //     } else if (*pItr == '.' && *(next(pItr, 1)) == '*') {
        //         hasStar = true;
        //         pItr++;
        //         sItr++;
        //     } else if (*(next(pItr, 1)) == '*') {
        //         hasStar = true;
        //         pItr++;
        //     } else if (*pItr == '.') {
        //         pItr++;
        //         sItr++;
        //     } else if (*pItr == '*') {
        //         hasStar = true;
        //         char pPattern = *(prev(pItr, 1));
        //         if (*sItr == pPattern) {
        //             sItr++;
        //         } else if (pPattern == '.') {
        //             *(prev(pItr, 1)) = *sItr;
        //             sItr++;
        //         } else {
        //             pItr += 1;
        //         }
        //     } else {
        //         return false;
        //     }
        // }

        // if (p.length() != s.length() && hasStar == false) {
        //     return false;
        // }

        // if (sItr == s.end() && pItr != p.end()) {
        //     if (*pItr == '*' && pItr++ == p.end()) {
        //         return true;
        //     }
        //     // dump the remaining p
        //     string rem = "";
        //     while (pItr != p.end()) {
        //         rem.push_back(*pItr);
        //         if (rem.length() == 1 && rem == "*") {
        //             pItr++;
        //         } 
        //         if (rem.length() == 2) {
        //             if (rem.back() != '*') {
        //                 return false;
        //             } else {
        //                 rem = "";
        //             }
        //         }
        //         pItr++;
        //     }
        //     if (rem.length()%2 == 1) {
        //         return false;
        //     }
        //     return true;
        // } else if (sItr == s.end() && pItr == p.end()) {   
        //     return true;
        // }
        // return false;
    }
};
/*
    let's try recursion
    - we know that every time we run into an asterisk, we need to do the matching.
    aa a*
    1: a == a
    2: * > a == a

    aaab c*a*b
*/
/*
    - iterate over p first.
    - append to pPattern
    - stop when *pItr == '*'. pPattern should be sth like ac*
    - compare 
*/
/*
    abbaabab ab*ab

    cmp(a, b)

    sPtr and pPtr has to move together
    compare first, return false if not matching.

    before moving, check the next char
    if pNext == '*'
    - move sPtr only
    if pNext == '*' && *sPtr != *pPtr
    - move pPtr only (twice)
    if pNext == null || sNext != null
    - return false
    if sNext == null || pNext != null
    - return false
    else
    - move both
*/
/*
    have two vectors: one for s and one for p
    iterate through each string and append to the vectors.
    if current pChar == '*', pop one from sVec.
    aa a* = ok
    aa a*a = ok
    ab a*b = ok
    a a* = ok
    do i try flipping it and iterating from the back? (not for now)

    # Happy Ending!
    s = "ababaaab", p = "ab*a*b"

    - init
    sPtr = 0, pPtr = 0. sVec = [], pVec = []
    - extract things before *
    sPtr = 0, pPtr = 2. sVec = [], pVec = [a, b, *]
    - if pVec.end() == '*', keep adding sChar until sVec.len = pVec.len. 
    sPtr = 1, pPtr = 2. sVec = [a, b], pVec = [a, b, *]
    - if sVec == pVec, clear sVec. save sPtr as bookmark.
    sPtr = 1, pPtr = 2. sVec = [], pVec = [a, b, *]
    - if pVec.end() == '*', keep adding sChar until sVec.len = pVec.len.
    sPtr = 3, pPtr = 2. sVec = [a, b], pVec = [a, b, *]
    - if sVec == pVec, clear sVec. save sPtr as bookmark.
    sPtr = 5, pPtr = 2. sVec = [a, a], pVec = [a, b, *]
    - if it doesn't match, clear both vectors. move sPtr back to bookmark.
    sPtr = 3, pPtr = 2. sVec = [], pVec = []
    - back to step 1. extract until *.
    sPtr = 3, pPtr = 4. sVec = [], pVec = [a, *]
    - iterate s
    sPtr = 4, pPtr = 4. sVec = [a], pVec = [a, *]
    ...
    sPtr = 6, pPtr = 4. sVec = [a], pVec = [a, *]
    - Save sPtr = 6 as bookmark.
    sPtr = 6, pPtr = 4. sVec = [], pVec = [a, *]
    sPtr = 7, pPtr = 4. sVec = [b], pVec = [a, *]
    - back to bookmark. Clear sVec and pVec
    sPtr = 6, pPtr = 4. sVec = [], pVec = []
    - iterate until p ends
    sPtr = 6, pPtr = 5. sVec = [], pVec = [b]
    - if if pVec.end() != '*', keep adding sChar.
    sPtr = 7, pPtr = 5. sVec = [b], pVec = [b]
    - if s is done, return true.

    # Sad Ending!

    s = aaabaabb, p = ab*a*b
*/





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