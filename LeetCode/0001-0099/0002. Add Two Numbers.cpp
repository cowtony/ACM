/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int digit = 0) {
        if (l1 && l2) {
            int val = l1->val + l2->val + digit;
            l1->val = val % 10;
            l1->next = addTwoNumbers(l1->next, l2->next, val / 10);
            return l1;
        } else if (l1) {
            int val = l1->val + digit;
            l1->val = val % 10;
            l1->next = addTwoNumbers(l1->next, nullptr, val / 10);
            return l1;
        } else if (l2) {
            int val = l2->val + digit;
            l2->val = val % 10;
            l2->next = addTwoNumbers(nullptr, l2->next, val / 10);
            return l2;
        } else if (digit > 0) {
            return new ListNode(digit);
        } else {
            return nullptr;
        }
    }
};
