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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        
        // Recursive swap:
        if (head->next->next) {
            head->next->next = swapPairs(head->next->next);
        }
        
        // Swap:
        ListNode* second = head->next;
        head->next = second->next;
        second->next = head;
        
        return second;
    }
};
