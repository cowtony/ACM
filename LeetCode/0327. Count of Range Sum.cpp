class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<int64_t, int> ms; // <sum, occurance>
        ms[0]++;
        
        int64_t sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            int64_t new_lower = sum - upper;
            int64_t new_upper = sum - lower;
            for (auto it = ms.lower_bound(new_lower); it != ms.end() and it->first <= new_upper; it++) {
                count += it->second;
            }
            ms[sum]++;
        }
        return count;
    }
};
