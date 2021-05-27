class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, pair<int, int>> interval_map;  // start, <end, index>
        
        for (int i = 0; i < intervals.size(); i++) {
            interval_map[intervals[i][0]] = make_pair(intervals[i][1], i);
        }
        
        vector<int> res;
        for (const vector<int>& interval : intervals) {
            auto it = interval_map.lower_bound(interval[1]);
            if (it != interval_map.end()) {
                res.push_back(it->second.second);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};
