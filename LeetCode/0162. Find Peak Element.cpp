class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((mid == 0 or nums[mid] > nums[mid - 1]) and (mid == nums.size() - 1 or nums[mid] > nums[mid + 1])) {
                return mid;
            }
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
