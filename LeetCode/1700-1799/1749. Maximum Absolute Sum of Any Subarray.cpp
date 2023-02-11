class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix_sum = 0;
        int maxp = 0, minp = 0;
        for (int num : nums) {
            prefix_sum += num;
            maxp = max(maxp, prefix_sum);
            minp = min(minp, prefix_sum);
        }
        return maxp - minp;
    }
};
