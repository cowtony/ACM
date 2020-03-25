// LeetCode 287: https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
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
