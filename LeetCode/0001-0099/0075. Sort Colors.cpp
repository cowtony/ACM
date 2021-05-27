class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        for (int i = 0; i <= hi; i++) {
            if (i > lo and nums[i] == 0) {
                swap(nums[lo], nums[i]);
                lo++;
                i--;
            } 
            if (nums[i] == 2) {
                swap(nums[hi], nums[i]);
                hi--;
                i--;
            }
        }
    }
};
