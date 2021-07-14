# define NULL __null
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum1 = 0;
        int sum2 = 0;
        int multiplier = 1;
        while (l1->next) {
            sum1 += multiplier * l1->val;
            multiplier *= 10;
        }
        multiplier = 1;
        while (l2->next) {
            sum2 += l2->val;
            multiplier *= 10;
        }

        int finalSum = sum1 + sum2;
        ListNode* l3 = NULL;
        while (finalSum >= 1) {

        }

    }
};

// https://www.softwaretestinghelp.com/linked-list/

/*
2 -> 4 -> 3
int sum;
loop through linked list
    for each element, multiply by 1, 10, 100, ...
    add them up
do the above for each linked list
sum1 + sum2 = sum3

ListNode* l3
while sum3 > 1 {
    digit = sum3 % 10
    l3.append(digit)
    sum3 = floor(sum3 / 10)
}
*/