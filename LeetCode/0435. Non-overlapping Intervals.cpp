class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int res = 0;
        int current_end = INT_MIN;
        for (auto interval : intervals) {
            if (interval[0] >= current_end) {
                res++;
                current_end = interval[1];
            }
        }
        
        return intervals.size() - res;
    }
};
