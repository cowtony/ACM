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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        ListNode *a = headA, *b = headB;

        while (a != b) {
            if (a) {
                a = a->next;
            } else {
                a = headB;
            }
                
            if (b) {
                b = b->next;
            } else {
                b = headA;
            }
        }
        return a;
    }
};
