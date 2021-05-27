class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int max_lo = 0, max_hi = 0;
        int volumn = 0;
        
        while (lo <= hi) {
            if (max_lo < max_hi) {
                max_lo = max(max_lo, height[lo]);
                volumn += max_lo - height[lo];
                lo++;
            } else {
                max_hi = max(max_hi, height[hi]);
                volumn += max_hi - height[hi];
                hi--;
            }
        }
        return volumn;
    }
};
