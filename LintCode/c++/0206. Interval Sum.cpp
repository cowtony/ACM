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
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> prefix_sum(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + A[i];
        }
        vector<long long> ret;
        for (Interval i : queries) {
            ret.push_back(prefix_sum[i.end + 1] - prefix_sum[i.start]);
        }
        return ret;
    }
};
