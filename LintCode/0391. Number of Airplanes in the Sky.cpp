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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        map<int, int> line;
        for (Interval i : airplanes) {
            line[i.start]++;
            line[i.end]--;
        }
        int max_plane = 0;
        int count = 0;
        for (auto p : line) {
            count += p.second;
            max_plane = max(max_plane, count);
        }
        return max_plane;
    }
};
