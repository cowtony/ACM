class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            if (nums[right] > nums[left]) {
                result++;
                left++;
            }
        }
        return result;
    }
};
