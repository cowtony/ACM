class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];
        for (int i = 2; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != score) {
                return i / 2;
            }
        }
        return nums.size() / 2;
    }
};
