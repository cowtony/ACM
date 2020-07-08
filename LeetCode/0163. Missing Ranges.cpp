class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<int64_t> num_64;
        for (int num : nums) {
            num_64.push_back(num);
        } // Convert to long long for overflow.
        num_64.push_back(upper + 1LL);
        int64_t current = lower - 1LL;
        vector<string> ret;
        int lo;
        for (int64_t num : num_64) {
            if (num > current + 1) {
                ret.push_back(buildRange(current + 1, num - 1));
            }
            current = num;
        }
        return ret;
    }
    
    string buildRange(int lo, int hi) {
        if (lo == hi) {
            return to_string(lo);
        } else {
            return to_string(lo) + "->" + to_string(hi);
        }
    }
};
