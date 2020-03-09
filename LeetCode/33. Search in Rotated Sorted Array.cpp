class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Fisrt find the rotation point.
        int lo = 0, hi = nums.size() - 1; 
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        // Then find the value.
        int loo = lo, hii = lo - 1 + nums.size();
        while (loo <= hii) {
            int mid = (loo + hii) / 2;
            if (nums[mid % nums.size()] < target) {
                loo = mid + 1;
            } else if (nums[mid % nums.size()] > target) {
                hii = mid - 1;
            } else {
                return mid % nums.size();
            }
        }
        return -1;
    }
};
