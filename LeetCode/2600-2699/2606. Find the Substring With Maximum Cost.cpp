class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26, 0);
        for (int i = 0; i < 26; i++) {
            cost[i] = i + 1;
        }
        for (int i = 0; i < chars.length(); i++) {
            cost[chars[i] - 'a'] = vals[i];
        }
        
        int sum_cost = 0;
        int min_cost = 0;
        int max_cost = 0;
        for (char c : s) {
            sum_cost += cost[c - 'a'];
            max_cost = max(max_cost, sum_cost - min_cost);
            min_cost = min(min_cost, sum_cost);
        }
        return max_cost;
    }
};
