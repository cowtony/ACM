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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* group = head;
        for (int i = 0; i < k; i++) {
            if (group == nullptr) {
                return head;
            }
            group = group->next;
        }
        
        // Reverse Linked List:
        ListNode* left = head;
        ListNode* right = head->next;
        
        left->next = reverseKGroup(group, k);
        
        for (int i = 0; i < k - 1; i++) {
            ListNode* temp = right->next;  
            right->next = left;
            left = right;
            right = temp;
        }
        
        return left;
    }
};
