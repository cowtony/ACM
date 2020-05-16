class Solution {
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        int hi = nums.size() - 1, lo = -hi;
        
        # define A(i) nums[abs(i)]
        
        vector<vector<int>> ret;
        while (lo < hi) {
            // Skip negative at right and positive at left.
            while (lo < 0 and A(lo) > 0 or lo > 0 and A(lo) < 0) {
                lo++;
            }
            while (hi < 0 and A(hi) > 0 or hi > 0 and A(hi) < 0) {
                hi--;
            }
            
            if (A(lo) + A(hi) < target) {
                lo++;
            } else if (A(lo) + A(hi) > target) {
                hi--;
            } else {
                ret.push_back({min(abs(lo), abs(hi)), max(abs(lo), abs(hi))});
                lo++;
                hi--;
            }
        }
        
        return ret;
    }
};
