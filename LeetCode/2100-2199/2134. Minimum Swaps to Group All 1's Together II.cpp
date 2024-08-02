class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int length = count(nums.begin(), nums.end(), 1);
        int count_1 = count(nums.end() - length, nums.end(), 1);

        int max_1 = 0;
        for (int i = 0, j = nums.size() - length; i < nums.size(); i++, j++) {
            count_1 += nums[i];
            count_1 -= nums[j % nums.size()];

            max_1 = max(max_1, count_1);
        }
        return length - max_1;
    }
};
