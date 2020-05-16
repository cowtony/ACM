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
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode * insertNode(ListNode * head, int val) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *node = dummy;
        while (node) {
            if (node->next == nullptr or node->next->val >= val) {
                ListNode *n = new ListNode(val);
                n->next = node->next;
                node->next = n;
                break;
            }
            node = node->next;
        }
        return dummy->next;
    }
};
