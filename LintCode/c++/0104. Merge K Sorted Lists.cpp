/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
struct ListNodeCompare {
    // nullptr is not considered because it will not be inserted.
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> pq;
        for (ListNode* node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        
        ListNode* ret = pq.empty()? nullptr : pq.top();
        while (!pq.empty()) {
            ListNode* current = pq.top();
            pq.pop();
            if (current->next != nullptr) {
                pq.push(current->next);
            }
            current->next = pq.empty()? nullptr : pq.top();            
        }
        return ret;
    }
};


