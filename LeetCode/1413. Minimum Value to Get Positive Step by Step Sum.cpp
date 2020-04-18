class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum = INT_MAX;
        int sum = 0;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            min_sum = min(min_sum, sum);
        }
        
        return max(1, 1 - min_sum);
    }
};
