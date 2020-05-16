class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        vector<int> sum(nums.size() + 1, 0);
        unordered_map<int, int> m;
        m[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
            if (m.find(sum[i + 1]) == m.end()) {
                m[sum[i + 1]] = i + 1;
            } else {
                return {m[sum[i + 1]], i};
            }
        }
        return {};
    }
};
