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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        ListNode* node = dummy_head;
        for(int i = 0; i < m - 1; i++) {
            node = node->next;
        }

        ListNode* start = node->next;
        ListNode* then = start->next;
        for(int i = 0; i < n - m; i++) {
            start->next = then->next;
            then->next = node->next;
            node->next = then;
            then = start->next;
        }

        return dummy_head->next;
    }
};
