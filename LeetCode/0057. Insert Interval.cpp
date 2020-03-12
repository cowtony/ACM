class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int lo, hi = 0;
        int i;
        bool used = false;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                ret.push_back(intervals[i]);
            } else { // intervals[i][1] >= newInterval[0]
                if (intervals[i][0] <= newInterval[1]) {
                    lo = min(intervals[i][0], newInterval[0]);
                    hi = max(intervals[i][1], newInterval[1]);
                    ret.push_back({lo, hi});
                } else {
                    ret.push_back(newInterval);
                    i--;
                }
                used = true;
                break;
            }
        }

        for (i = i + 1; i < intervals.size(); i++) {
            if (hi >= intervals[i][0]) {
                hi = max(hi, intervals[i][1]);
                ret.back()[1] = hi;
            } else {
                break;
            }
        }
        for (; i < intervals.size(); i++) {
            ret.push_back(intervals[i]);
        }
        if (!used) {
            ret.push_back(newInterval);
        }
        
        return ret;
    }
};
