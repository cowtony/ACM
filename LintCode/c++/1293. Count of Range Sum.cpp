class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param lower: a integer
     * @param upper: a integer
     * @return: return a integer
     */
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        map<int, int> ms; // <sum, occurance>
        ms[0]++;
        
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            int new_lower = sum - upper;
            int new_upper = sum - lower;
            for (auto it = ms.lower_bound(new_lower); it != ms.end() and it->first <= new_upper; it++) {
                count += it->second;
            }
            ms[sum]++;
        }
        return count;
    }
};
