class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());

        cout << endl;
        int lo = 0, hi;
        int ans = 0;
        for (hi = nums.size() - 1; hi > lo; hi--) {
            while (nums[lo] + nums[hi] <= target and lo < hi) {
                lo++;
            }
            ans += lo;
        }
        
        // All following combination is satisfied.
        ans += (1 + hi) * hi / 2;
        return ans;
    }
};
