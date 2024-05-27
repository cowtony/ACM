class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= i + 1 && (i == nums.size() - 1 || nums[i + 1] < i + 1)) {
                return i + 1;
            }
        }
        return -1;
    }
};
