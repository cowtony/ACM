class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int small = 1, large = nums.size() - 1;
        while (small < large) {
            int mid = small + (large - small + 1) / 2;
            int count = 0;
            for (int num : nums) {
                if (num < mid) {
                    count++;
                }
            }
            if (count < mid) {
                small = mid;
            } else {
                large = mid - 1;
            }
        }
        return small;
    }
};
