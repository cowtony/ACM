class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;
   
        int l = 0, r = costs.size() - 1;
        while (l < candidates && l <= r) {
            left.push(costs[l++]);
            if (l <= r) {
                right.push(costs[r--]);
            }
        }

        long long result = 0;
        for (int i = 0; i < k; i++) {
            if (right.empty() || !left.empty() && right.top() >= left.top()) {
                result += left.top();
                left.pop();
                if (l <= r) {
                    left.push(costs[l++]);
                }
            } else {
                result += right.top();
                right.pop();
                if (r >= l) {
                    right.push(costs[r--]);
                }
            }
        }

        return result;
    }
};
