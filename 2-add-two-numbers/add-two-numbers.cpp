#include <cmath>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void append(struct ListNode** head, int node_data);

int carryOver = 0;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        int a = 0;
        int b = 0;
        int sum = 0;
        carryOver = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }
            else {
                a = 0;
            }
            if (l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            else {
                b = 0;
            }
            sum = a + b + carryOver;
            if (sum >= 10) {
                carryOver = floor(sum/10);
                sum -= carryOver * 10;
            }
            else {
                carryOver = 0;
            }
            
            append(&l3, sum);
        }
        if (carryOver == 1) {
            append(&l3, 1);
        }
        return l3;
    }
};

void append(struct ListNode** head, int node_data) {
    struct ListNode* newNode = new ListNode;
    struct ListNode *last = *head;
    newNode->val = node_data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}