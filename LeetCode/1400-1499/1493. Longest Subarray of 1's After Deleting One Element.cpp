class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        for (int hi = 0, lo = 0, zeros = 0; hi < nums.size(); hi++) {
            if (nums[hi] == 0) {
                zeros++;
                if (zeros > 1) {
                    while (nums[lo++] == 1);
                    zeros--;
                }
            }
            res = max(res, hi - lo + 1);
        }
        return res - 1;
    }
};
