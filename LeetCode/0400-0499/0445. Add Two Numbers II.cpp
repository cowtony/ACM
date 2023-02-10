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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        while (l1) {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            b.push(l2->val);
            l2 = l2->next;
        }

        stack<int> c;
        int carry = 0;
        while (!a.empty() || !b.empty()) {
            int i = carry;
            if (!a.empty()) {
                i += a.top();
                a.pop();
            }
            if (!b.empty()) {
                i += b.top();
                b.pop();
            }
            carry = i / 10;
            c.push(i % 10);
        }
        if (carry > 0) {
            c.push(carry);
        }
        
        ListNode* root = new ListNode();
        ListNode* node = root;
        while (!c.empty()) {
            node->next = new ListNode(c.top());
            node = node->next;
            c.pop();
        }
        return root->next;
    }
};
