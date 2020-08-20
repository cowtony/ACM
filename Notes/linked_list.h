ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Reverse
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
