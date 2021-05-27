class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.empty()) {
            return {};
        }
   
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret.back()[1] < intervals[i][0]) {
                ret.push_back(intervals[i]);
            } else {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
        }
        return ret;
    }
};
