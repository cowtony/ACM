class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        
        int ptr = 0;
        int result = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            while (ptr < banned.size() && banned[ptr] < i) {
                ptr++;
            }
            if (ptr < banned.size() && banned[ptr] == i) {
                continue;
            }

            sum += i;
            if (sum > maxSum) {
                return result;
            }
            result++;
        }
        return result;
    }
};
