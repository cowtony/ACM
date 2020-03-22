class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        
        int lo = 0, hi = nums.size() - 1; 
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // This part handle the duplicate numbers.
            if (nums[mid] == nums[hi]) {
                hi--;
                continue;
            }
            // Rotate point is right half.
            if (nums[mid] > nums[hi]) { 
                // Trget is in left half.
                if (target <= nums[mid] and target >= nums[lo]) { 
                    hi = mid;
                } 
                // Target is in right half.
                else { 
                    lo = mid + 1;
                }
            }
            // Rotate point is left half.
            else {
                // Trget is in right half.
                if (target > nums[mid] and target <= nums[hi]) { 
                    lo = mid + 1;
                } 
                // Target is in left half.
                else { 
                    hi = mid;
                }
            }
        }
        
        if (nums[lo] == target) {
            return true;
        } else {
            return false;
        }
    }
};
