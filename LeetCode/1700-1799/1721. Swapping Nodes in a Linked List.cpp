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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head, *left, *right = head;
        int count = 1;
        while (ptr) {
            if (count == k) {
                left = ptr;
            }

            if (count > k) {
                right = right->next;
            }
            ptr = ptr->next;
            count++;
        }
        swap(left->val, right->val);
        return head;
    }
};
