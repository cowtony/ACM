class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param target: an integer
     * @return: nothing
     */
    void MoveTarget(vector<int> &nums, int target) {
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                count++;
            } else {
                swap(nums[i + count], nums[i]);
            }
        }
    }
};
