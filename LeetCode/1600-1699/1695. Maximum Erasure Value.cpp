class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        unordered_set<int> unique;
        for (int lo = 0, hi = 0; hi < nums.size(); hi++) {
            while (unique.find(nums[hi]) != unique.end()) {
                unique.erase(nums[lo]);
                sum -= nums[lo];
                lo++;
            }
            unique.insert(nums[hi]);
            sum += nums[hi];
            res = max(res, sum);
        }
        return res;
    }
};
