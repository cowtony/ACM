// LeetCode 986: https://leetcode.com/problems/interval-list-intersections/
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
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        int a = 0, b = 0;
        vector<Interval> ans;
        while (a < seqA.size() and b < seqB.size()) {
            if (seqA[a].end < seqB[b].start) {
                a++;
            } else if (seqA[a].start > seqB[b].end) {
                b++;
            } else {
                ans.push_back(Interval(max(seqA[a].start, seqB[b].start), min(seqA[a].end, seqB[b].end)));
                if (seqA[a].end < seqB[b].end) {
                    a++;
                } else {
                    b++;
                }
            }
        }
        return ans;
    }
};
