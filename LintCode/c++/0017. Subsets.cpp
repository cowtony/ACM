class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = (1 << nums.size()) - 1;
        while (n >= 0) {
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++) {
                if (1 << i & n) {
                    ans.push_back(nums[i]);
                }
            }
            ret.push_back(ans);
            n--;
        }
        return ret;
    }
};
