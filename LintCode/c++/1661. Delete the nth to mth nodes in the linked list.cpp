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
     * @param head: The first node of linked list
     * @param n: the start index
     * @param m: the end node
     * @return: A ListNode
     */
    ListNode * deleteNode(ListNode * head, int n, int m) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* lo = dummy;
        for (int i = 0; i < n; i++) {
            lo = lo->next;
        }
        ListNode* hi = lo;
        for (int i = 0; i < m - n + 1 and hi != nullptr; i++) {
            hi = hi->next;
        }
        lo->next = hi == nullptr? nullptr : hi->next;
        
        return dummy->next;
    }
};
