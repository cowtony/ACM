class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int>& numbers) {
        if (numbers.size() < 3) {
            return {};
        }
        vector<vector<int>> ret;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 2; i++) {
            if (i > 0 and numbers.at(i) == numbers.at(i - 1)) {
                continue;
            }
            for (const int& ans : twoSum(numbers, i + 1, -numbers.at(i))) {
                ret.emplace_back(vector<int>({numbers.at(i), ans, -numbers.at(i) - ans}));
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
