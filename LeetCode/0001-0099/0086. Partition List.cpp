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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_head = new ListNode(0); // Dummy
        ListNode* small = small_head;
        ListNode* large_head = new ListNode(0); // Dummy
        ListNode* large = large_head;
        
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = head;
            } else {
                large->next = head;
                large = head;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = large_head->next;
        return small_head->next;
    }
};
