class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int product = 1;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            product *= nums[r];
            while (product >= k && l < r) {
                product /= nums[l++];
            }
            
            if (product < k) {
                count += r - l + 1;
            }
        }

        return count;
    }
};
