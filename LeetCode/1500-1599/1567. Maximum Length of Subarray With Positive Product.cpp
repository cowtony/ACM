class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int start = INT_MAX, negative = INT_MAX, negative_count = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = INT_MAX;
                negative = INT_MAX;
                negative_count = 0;
            } else {
                start = min(start, i);
                if (nums[i] < 0) {
                    negative_count++;
                    negative = min(negative, i);
                }
                res = max(res, i - (negative_count % 2? negative + 1 : start) + 1);
            }
        }
        return res;
    }
};
