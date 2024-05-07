/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (carry(head) == 0) {
            return head;
        } else {
            return new ListNode(1, head);
        }
    }

    int carry(ListNode* node) {
        if (!node) {
            return false;
        }
        int carry_val = carry(node->next);
        node->val = carry_val + 2 * node->val;
        carry_val = node->val / 10;
        node->val %= 10;
        
        return carry_val;
    }
};
