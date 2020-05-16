class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                return {start + 1, end + 1};
            }
            else if (nums[start] + nums[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return {};
    }
};
