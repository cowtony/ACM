class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < sums.size(); i++) {
            if (m.find(sums[i] - k) != m.end()) {
                count += m.at(sums[i] - k);
            }
            m[sums[i]]++;
        }
        return count;
    }
};
