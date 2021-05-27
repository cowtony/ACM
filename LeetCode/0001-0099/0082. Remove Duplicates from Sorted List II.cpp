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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }
        
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } else {
            while (head->next and head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }
    }
};
