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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        k %= len;  // Incase k > len
        k = (len - k) % len;  // Now counting from left to right.
        if (k == 0) {
            return head;
        }

        int count = 1;
        ListNode* pointer = head;
        ListNode* new_head = head;
        ListNode* new_tail = head;
        
        while (pointer->next != nullptr) {
            if (count == k) {
                new_tail = pointer;
                new_head = new_tail->next;
            }
            
            count++;
            pointer = pointer->next;
        }
        pointer->next = head;
        new_tail->next = nullptr;
        return new_head;
    }
};
