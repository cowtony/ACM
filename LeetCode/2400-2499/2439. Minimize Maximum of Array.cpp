class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long result = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = max(result, (sum + i) / (i + 1));
        }
        return result;
    }
};
