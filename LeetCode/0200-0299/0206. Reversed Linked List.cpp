// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Iteratively
    ListNode* reverseList(ListNode* head) {
        ListNode *left = nullptr, *right = head;
        while (right != nullptr)
        {
            ListNode* nextRight = right->next;
            right->next = left;  // flip
            left = right;
            right = nextRight;
        }
        return left;
    }

    // Recursively
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
