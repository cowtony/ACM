class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());        
        return countLessThan(nums, upper) - countLessThan(nums, lower - 1);
    }
    
    long long countLessThan(const vector<int>& nums, int val) {
        long long result = 0;
        for (int left = 0, right = nums.size() - 1; left < right; left++) {
            while (right > left && nums[left] + nums[right] > val) {
                right--;
            }
            result += right - left;
        }
        return result;
    }
};
