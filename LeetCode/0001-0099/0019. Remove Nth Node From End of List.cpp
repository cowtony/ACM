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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode;
        dummy_head->next = head;
        
        ListNode* a = dummy_head;
        ListNode* d = dummy_head;
        int c = 0;
        
        while (a != nullptr) {
            
            a = a->next;
            
            if (c > n) {
                d = d->next;
            }
            c++;
        }
        
        // d should point on the previous element.
        // Execute the delete:
        a = d->next;
        if (a != nullptr) {
            d->next = a->next;
        }
        
        return dummy_head->next;
    }
};
