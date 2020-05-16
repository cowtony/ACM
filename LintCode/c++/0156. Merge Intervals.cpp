/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.empty()) {
            return {};
        }
   
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret.back().end < intervals[i].start) {
                ret.push_back(intervals[i]);
            } else {
                ret.back().end = max(ret.back().end, intervals[i].end);
            }
        }
        return ret;
    }
};
