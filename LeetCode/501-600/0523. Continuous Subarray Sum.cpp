class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        
        unordered_map<int, int> m;
        for (int i = 0; i < sums.size(); i++) {
            int reminder;
            if (k == 0) {
                reminder = sums[i];
            } else {
                reminder = sums[i] % k;
            }
            if (m.find(reminder) != m.end()) {
                if (i - m[reminder] > 1) {
                    return true;
                }
            } else {
                m[reminder] = i;
            }
        }
        return false;
    }
};
