/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2, int digit = 0) {
        if (l1 && l2) {
            int val = l1->val + l2->val + digit;
            l1->val = val % 10;
            l1->next = addLists(l1->next, l2->next, val / 10);
            return l1;
        } else if (l1) {
            int val = l1->val + digit;
            l1->val = val % 10;
            l1->next = addLists(l1->next, nullptr, val / 10);
            return l1;
        } else if (l2) {
            int val = l2->val + digit;
            l2->val = val % 10;
            l2->next = addLists(nullptr, l2->next, val / 10);
            return l2;
        } else if (digit > 0) {
            return new ListNode(digit);
        } else {
            return nullptr;
        }
    }
};
