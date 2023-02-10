class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result = 0;
        for (int i = 0; i <= k; i++) {
            result += min(tickets[i], tickets[k]);
        }
        for (int i = k + 1; i < tickets.size(); i++) {
            result += min(tickets[i], tickets[k] - 1);
        }
        return result;
    }
};
