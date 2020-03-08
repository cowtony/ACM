class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 and nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 and nums.at(j) == nums.at(j - 1)) {
                    continue;
                }
                int remain_target = target - nums.at(i) - nums.at(j);
                for (int ans : twoSum(nums, j + 1, remain_target)) {
                    ret.emplace_back(vector<int>({nums.at(i), nums.at(j), ans, remain_target - ans}));
                }
            }
        }
        return ret;
    }
    
    // Return the smaller number list of the combination.
    // The larger one can be deduced by target - num.
    set<int> twoSum(vector<int>& nums, int start_index, int target) {
        set<int> ret;
        int lo = start_index, hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] == target) {
                ret.emplace(nums[lo]);
                lo++; 
                hi--;
            } else if (nums[lo] + nums[hi] < target) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return ret;
    }
};
