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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid->next);
        mid->next = nullptr;
        mergeList(head, head2);
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *left = nullptr, *right = head;
        while (right) {
            ListNode* nextRight = right->next;
            right->next = left;  // flip
            left = right;
            right = nextRight;
        }
        return left;
    }
    
    void mergeList(ListNode* head1, ListNode* head2) {
        while (head1 and head2) {
            ListNode* temp = head1->next;
            head1 = head1->next = head2;
            head2 = temp;
        }
    }
};
