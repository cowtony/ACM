class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        
        // Find left bond.
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (nums[lo] != target) {
            return {-1, -1};
        }
        int loo = lo;
        
        // Find right bond.
        lo = 0; 
        hi = nums.size() - 1;
        while (lo < hi) {
            // Add 1 to bias right side.
            int mid = (lo + hi + 1) / 2;
            if (target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        
        int hii = nums[lo] == target? lo : -1;
        return {loo, hii};
    }
};
