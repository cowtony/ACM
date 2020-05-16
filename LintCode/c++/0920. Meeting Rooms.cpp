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
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        map<int, int> event;
        for (Interval interval : intervals) {
            event[interval.start]++;
            event[interval.end]--;
        }
        
        int count = 0;
        for (auto p : event) {
            count += p.second;
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};
