class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        return numOfWays(nums, target);
    }
    
    unordered_map<int, int> dp; // Key: target, Value: ways
    int numOfWays(vector<int>& nums, int target) {
        if (dp.find(target) != dp.end()) {
            return dp.at(target);
        }
        dp[target] = 0;
        for (int num : nums) {
            if (num > target) {
                break;
            }
            dp[target] += numOfWays(nums, target - num);
        }
        return dp[target];
    }
};
