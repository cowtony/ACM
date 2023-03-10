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
    Solution(ListNode* head) : kHead(head) {}
    
    int getRandom() {
        ListNode* node = kHead;
        int reservoir;
        int i = 0;
        while (node) {
            i++;
            if (rand() % i == 0) {
                reservoir = node->val;
            }
            node = node->next;
        }
        return reservoir;
    }

private:
    ListNode* const kHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
