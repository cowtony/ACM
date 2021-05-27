class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (mid % 2 == 0) {
                if (nums.at(mid) == nums.at(mid + 1)) {
                    lo = mid + 2;
                } else {
                    hi = mid;
                }
            } else { // mid % 2 == 1
                if (nums.at(mid) == nums.at(mid - 1)) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }
        return nums[lo];
    }
};
