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
    ListNode* oddEvenList(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        // O ->   
        // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        //    E(H)->
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while (even and even->next) {
            // O ------>     
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            //      E
            odd->next = even->next;
            //   ------> O -> 
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            //      E
            odd = odd->next;
            //   ------> O ->
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            //      E ------> 
            even->next = odd->next;
            //   ------> O ->
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            //        ------> E ->
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
