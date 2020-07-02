class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MAX);
        
        vector<string> res;
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (int64_t(nums[i]) != int64_t(nums[i - 1]) + 1) {
                if (nums[i - 1] == start) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }
        
        return res;
    }
};
