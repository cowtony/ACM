// LeetCode 215: https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        vector<int> small;
        vector<int> large;
        int middle = nums[nums.size() / 2];
        for (int num : nums) {
            if (num < middle) {
                small.push_back(num);
            } else if (num > middle) {
                large.push_back(num);
            }
        }
        
        if (large.size() >= n) {
            return kthLargestElement(n, large);
        } else if (n > nums.size() - small.size()) {
            return kthLargestElement(n - (nums.size() - small.size()), small);
        } else {
            return middle;
        }
    }
};
