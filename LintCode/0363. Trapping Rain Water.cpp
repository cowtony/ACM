// LeetCode 42: https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int lo = 0, hi = heights.size() - 1;
        int max_lo = 0, max_hi = 0;
        int volumn = 0;
        
        while (lo <= hi) {
            if (max_lo < max_hi) {
                max_lo = max(max_lo, heights[lo]);
                volumn += max_lo - heights[lo];
                lo++;
            } else {
                max_hi = max(max_hi, heights[hi]);
                volumn += max_hi - heights[hi];
                hi--;
            }
        }
        return volumn;
    }
};
