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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<pair<int,int>> stk;
        for (int i = 0; head != nullptr; ++i, head = head->next) {
            while (!stk.empty() && head->val > stk.top().second) {
                result[stk.top().first] = head->val;
                stk.pop();
            }
            result.push_back(0);
            stk.push({i, head->val});
        }

        return result;
    }
};
