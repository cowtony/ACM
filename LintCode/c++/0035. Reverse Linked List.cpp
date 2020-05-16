/**
 * Definition of singly-linked-list:
 *
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
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        ListNode *left = nullptr, *right = head;
        while (right != nullptr)
        {
            ListNode* nextRight = right->next;
            right->next = left;  // flip
            left = right;
            right = nextRight;
        }
        return left;
    }
};
