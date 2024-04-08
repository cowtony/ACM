class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int duplicate = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            if (r > 0 && nums[r] == nums[r - 1]) {
                duplicate++;
                continue;
            }
            while (nums[r] - nums[l] > nums.size() - 1) {
                l++;
                if (nums[l] == nums[l - 1]) {
                    duplicate--;
                }
            }
            maxLength = max(maxLength, r - l + 1 - duplicate);
        }

        return nums.size() - maxLength;
    }
};
