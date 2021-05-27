// Key point: Divide 3 sum problem into 2 sum problem.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 and nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            for (const int& ans : twoSum(nums, i + 1, -nums.at(i))) {
                ret.emplace_back(vector<int>({nums.at(i), ans, -nums.at(i) - ans}));
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
            } else if (nums[lo] + nums[hi] < target)
                lo++;
            else 
                hi--;
        }
        return ret;
    }
};
