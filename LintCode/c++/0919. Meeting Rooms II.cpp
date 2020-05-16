/**
 * Definition of Interval:
 * classs Interval {
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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        map<int, int> sweep;
        for (Interval interval : intervals) {
            sweep[interval.start]++;
            sweep[interval.end]--;
        }
        int count = 0;
        int max_room = 0;
        for (pair<int, int> p : sweep) {
            count += p.second;
            max_room = max(max_room, count);
        }
        return max_room;
    }
};
